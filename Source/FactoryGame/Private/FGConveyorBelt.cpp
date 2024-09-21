#include "FGConveyorBelt.h"
#include "FGUnitConnectorComponent.h"
#include "FGItemActorComponent.h"

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
}

void AFGConveyorBelt::Work(float DeltaTime)
{
	Super::Work(DeltaTime);

	if (!this->IsCycleReturned()) return;

	// 주기가 돌았으면, Fetch 조건을 확인한다.
	// Fetch가 가능하다면 Fetch 연산 수행 후 WorkTime 초기화.
	// Fetch가 불가능하다면 Tick 끄기

	const bool BCanFetchItem = this->bCanSpawnAnotherItem && this->InputConnector->CanFetchItem();
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
	InItemActor1->SetComponentTickEnabled(false);
	InItemActor2->SetComponentTickEnabled(false);
	return;
}

void AFGConveyorBelt::HandleItemActorOverlapBeginEvent(
	UFGItemActorComponent* InItemActor, 
	UFGUnitConnectorComponent* InUnitConnector
)
{
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
	InItemActor1->SetComponentTickEnabled(true);
	InItemActor2->SetComponentTickEnabled(true);
	return;
}

void AFGConveyorBelt::HandleItemActorOverlapEndEvent(
	UFGItemActorComponent* InItemActor, 
	UFGUnitConnectorComponent* InUnitConnector
)
{
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

void AFGConveyorBelt::CreateItemActorComponent(UFGItem* InItem)
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Owner = this;

	FString ItemActorComponentName = FString::Printf(TEXT("ItemActor_%d"), this->TransportingItems.Num());
	UFGItemActorComponent* ItemActorCreated = this->CreateDefaultSubobject<UFGItemActorComponent>(*ItemActorComponentName);

	ItemActorCreated->SetTransportingConveyor(this);
	ItemActorCreated->SetItemData(InItem);

	this->TransportingItems.Add(ItemActorCreated->GetStaticMesh(), ItemActorCreated);
	
	return;
}
