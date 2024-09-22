#include "FGConveyorBelt.h"
#include "FGUnitConnectorComponent.h"
#include "FGItemActorComponent.h"

#include "FGFactoryBuilding.h"
#include "FGGlobalItemTable.h"
#include "EngineUtils.h"

AFGConveyorBelt::AFGConveyorBelt(const uint32 InTransportVolumePerMinute)
	: Super()

	, InputConnector(nullptr)
	, OutputConnector(nullptr)

	, bCanSpawnAnotherItem(true)
	, TransportVolumePerMinute(InTransportVolumePerMinute)
	, TransportingItems({})
	, ItemActorOverlappingOutputConnector(nullptr)
{
	this->WorkTime = this->GetCycleTime();

	this->InitializeStaticMeshComponent();
}

void AFGConveyorBelt::Work(float DeltaTime)
{
	Super::Work(DeltaTime);

	if (!this->IsCycleReturned()) return;

	// 주기가 돌았으면, Fetch 조건을 확인한다.
	// Fetch가 가능하다면 Fetch 연산 수행 후 WorkTime 초기화.
	// Fetch가 불가능하다면 Tick 끄기
	
	const bool BCanFetchItem = this->bCanSpawnAnotherItem && this->InputConnector->CanFetchItem();
	UE_LOG(LogTemp, Warning, TEXT("Conveyor Work... : Fetch = %d"), BCanFetchItem);

	if (BCanFetchItem)
	{
		UFGItem* ItemFetched = this->InputConnector->FetchItem();
		this->CreateItemActorComponent(ItemFetched);
		this->WorkTime = 0.0f;
	}
	else
	{
		this->SetActorTickEnabled(false);
	}

	return;
}

void AFGConveyorBelt::NotifyInputChanged()
{
	const bool BNewInputValid = this->InputConnector->CanFetchItem();
	this->bInputsValid = BNewInputValid;
	
	this->SetActorTickEnabled(BNewInputValid);
}

void AFGConveyorBelt::NotifyOutputChanged()
{

	if (!this->ItemActorOverlappingOutputConnector) return;

	this->bOutputsValid = 
		this->OutputConnector->CanSendItem(
		this->ItemActorOverlappingOutputConnector->GetItemData()
	);

	if (this->bOutputsValid) 
		this->RemoveItemActorComponent(this->ItemActorOverlappingOutputConnector);

	return;
}

void AFGConveyorBelt::HandleItemActorOverlapBeginEvent(
	UFGItemActorComponent* InItemActor1, 
	UFGItemActorComponent* InItemActor2
)
{
	UE_LOG(LogTemp, Warning, TEXT("Handling Overlap Begin : Item & Item"));

	InItemActor1->SetComponentTickEnabled(false);
	InItemActor2->SetComponentTickEnabled(false);
	return;
}

void AFGConveyorBelt::HandleItemActorOverlapBeginEvent(
	UFGItemActorComponent* InItemActor, 
	UFGUnitConnectorComponent* InUnitConnector
)
{
	UE_LOG(LogTemp, Warning, TEXT("Handling Overlap Begin : Item & Connector"));
	const bool BOverlapWithInputConnector = (InUnitConnector == this->InputConnector);
	const bool BOverlapWithOutputConnector = (InUnitConnector == this->OutputConnector);

	if (BOverlapWithInputConnector) 
		this->bCanSpawnAnotherItem = false;

	else if (BOverlapWithOutputConnector)
	{
		this->ItemActorOverlappingOutputConnector = InItemActor;
		this->bOutputsValid = this->OutputConnector->CanSendItem(InItemActor->GetItemData());
		if (this->bOutputsValid) this->RemoveItemActorComponent(InItemActor);
	}
		
	return;
}

void AFGConveyorBelt::HandleItemActorOverlapEndEvent(
	UFGItemActorComponent* InItemActor1, 
	UFGItemActorComponent* InItemActor2
)
{
	UE_LOG(LogTemp, Warning, TEXT("Handling Overlap End : Item & Item"));
	InItemActor1->SetComponentTickEnabled(true);
	InItemActor2->SetComponentTickEnabled(true);
	return;
}

void AFGConveyorBelt::HandleItemActorOverlapEndEvent(
	UFGItemActorComponent* InItemActor, 
	UFGUnitConnectorComponent* InUnitConnector
)
{
	UE_LOG(LogTemp, Warning, TEXT("Handling Overlap End : Item & Connector"));
	if (InUnitConnector == this->InputConnector)
		this->bCanSpawnAnotherItem = true;

	return;
}

void AFGConveyorBelt::RemoveItemActorComponent(UFGItemActorComponent* InItemActorComponent)
{
	// Give OutputConnector the Item
	this->OutputConnector->SendItem(InItemActorComponent->GetItemData());

	// Delete ItemActor From TSet
	this->TransportingItems.Remove(InItemActorComponent->GetStaticMesh());

	// Delete ItemActor Completely
	InItemActorComponent->DestroyComponent();
	InItemActorComponent = nullptr;

	return;
}

bool AFGConveyorBelt::IsCycleReturned() const
{
	return (this->WorkTime > this->GetCycleTime());
}

const FVector AFGConveyorBelt::GetTransportDirection() const
{
	
	const FVector TransportDirection =
		this->OutputConnector->GetWorldLocation() -
		this->InputConnector->GetWorldLocation();

	return TransportDirection.GetUnsafeNormal();
}

void AFGConveyorBelt::RegisterItemActor(UFGItemActorComponent* InItemActor)
{
	check(InItemActor);
	check(InItemActor->GetStaticMesh());
	this->TransportingItems.Add(InItemActor->GetStaticMesh(), InItemActor);
}

void AFGConveyorBelt::BeginPlay()
{
	Super::BeginPlay();

	int32 Cnt = 0;

	for (TActorIterator<AFGFactoryBuilding> Iter(this->GetWorld()); Iter; ++Iter)
	{
		AFGFactoryBuilding* Factory = *Iter;

		if (Factory && (Cnt == 0))
		{
			Factory->SelectRecipe(1);
			Factory->StoreItem(UFGGlobalItemTable::GetItem(1), 5);

			Factory->OutputConnector->OutputUnit = this;

			this->InputConnector = Factory->OutputConnector;

			UE_LOG(LogTemp, Warning, TEXT("InputConnector World Location : %s"), *this->InputConnector->GetWorldLocation().ToString());
			Cnt++;
		}

		else if (Factory && (Cnt == 1))
		{
			Factory->SelectRecipe(2);

			Factory->InputConnectors[0]->InputUnit = this;
			this->OutputConnector = Factory->InputConnectors[0];
			Cnt++;
		}

	}

	return;
}

void AFGConveyorBelt::InitializeStaticMeshComponent()
{
	Super::InitializeStaticMeshComponent();

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	this->StaticMeshComponent->SetStaticMesh(CubeMesh.Object);
	this->StaticMeshComponent->SetRelativeScale3D(FVector(1.0f, 3.0f, 0.1f));

	return;
}

void AFGConveyorBelt::CreateItemActorComponent(UFGItem* InItem)
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Owner = this;

	UFGItemActorComponent* ItemActorCreated = NewObject<UFGItemActorComponent>(this, UFGItemActorComponent::StaticClass());

	// Set ItemActor Properties
	this->RegisterItemActor(ItemActorCreated);
	ItemActorCreated->SetTransportingConveyor(this);
	ItemActorCreated->SetItemData(InItem);

	// Register
	ItemActorCreated->GetStaticMesh()->AttachToComponent(ItemActorCreated, FAttachmentTransformRules::KeepRelativeTransform);
	ItemActorCreated->GetStaticMesh()->RegisterComponent();

	ItemActorCreated->AttachToComponent(this->RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ItemActorCreated->RegisterComponent();

	// Set ActorSM Transforms
	ItemActorCreated->GetStaticMesh()->SetWorldLocation(this->InputConnector->GetWorldLocation());
	ItemActorCreated->GetStaticMesh()->SetWorldScale3D(FVector(0.2f));
	ItemActorCreated->GetStaticMesh()->SetUsingAbsoluteScale(true);

	// Bind Overlap Events
	ItemActorCreated->GetStaticMesh()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	ItemActorCreated->GetStaticMesh()->SetGenerateOverlapEvents(true);
	ItemActorCreated->GetStaticMesh()->OnComponentBeginOverlap.AddDynamic(ItemActorCreated, &UFGItemActorComponent::OnOverlapBegin);
	ItemActorCreated->GetStaticMesh()->OnComponentEndOverlap.AddDynamic(ItemActorCreated, &UFGItemActorComponent::OnOverlapEnd);

	return;
}
