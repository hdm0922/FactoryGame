#include "FGItemActorComponent.h"
#include "FGConveyorBelt.h"
#include "FGUnitConnectorComponent.h"

UFGItemActorComponent::UFGItemActorComponent()
	: Super()
	, StaticMeshComponent(nullptr)
	, LastOverlappedItemActorComponent(nullptr)
	, ItemData(nullptr)
	, TransportingConveyor(nullptr)
{
	PrimaryComponentTick.bCanEverTick = true;

	this->SetStaticMesh();
}

void UFGItemActorComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UFGItemActorComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	Super::OnComponentDestroyed(bDestroyingHierarchy);
	
	if (!this->LastOverlappedItemActorComponent) return;

	this->LastOverlappedItemActorComponent->SetComponentTickEnabled(true);
	this->LastOverlappedItemActorComponent->TransportingConveyor->
		HandleItemActorOverlapEndEvent(this, this->LastOverlappedItemActorComponent);
		
	return;
}


void UFGItemActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const float Speed = 100.0f;
	const FVector DeltaPosition = this->TransportingConveyor->GetTransportDirection() * Speed * DeltaTime;
	this->SetRelativeLocation(this->GetRelativeLocation() + DeltaPosition);
}

void UFGItemActorComponent::SetTransportingConveyor(AFGConveyorBelt* InConveyorBelt)
{
	this->TransportingConveyor = InConveyorBelt;
	return;
}

void UFGItemActorComponent::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& SweepResult
)
{
	UStaticMeshComponent* OverlappedStaticMeshComponent = Cast<UStaticMeshComponent>(OverlappedComponent);
	if (!OverlappedStaticMeshComponent) return;

	UFGItemActorComponent* ItemActorComponentOverlapped = 
		this->TransportingConveyor->GetItemActorComponent(OverlappedStaticMeshComponent);

	if (ItemActorComponentOverlapped &&
		(this->TransportingConveyor == ItemActorComponentOverlapped->TransportingConveyor))
	{
		if (ItemActorComponentOverlapped->IsComponentTickEnabled())
			this->LastOverlappedItemActorComponent = ItemActorComponentOverlapped;

		this->TransportingConveyor->HandleItemActorOverlapBeginEvent(this, ItemActorComponentOverlapped);
	}
	
	if (OverlappedStaticMeshComponent == this->TransportingConveyor->InputConnector->StaticMeshComponent)
		this->TransportingConveyor->HandleItemActorOverlapBeginEvent(this, this->TransportingConveyor->InputConnector);
	else if (OverlappedStaticMeshComponent == this->TransportingConveyor->OutputConnector->StaticMeshComponent)
		this->TransportingConveyor->HandleItemActorOverlapBeginEvent(this, this->TransportingConveyor->OutputConnector);

	return;
}

void UFGItemActorComponent::OnOverlapEnd(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex
)
{
	UStaticMeshComponent* OverlappedStaticMeshComponent = Cast<UStaticMeshComponent>(OverlappedComponent);
	if (!OverlappedStaticMeshComponent) return;

	UFGItemActorComponent* ItemActorComponentOverlapped =
		this->TransportingConveyor->GetItemActorComponent(OverlappedStaticMeshComponent);

	if (ItemActorComponentOverlapped == this->LastOverlappedItemActorComponent)
	{
		this->LastOverlappedItemActorComponent->SetComponentTickEnabled(true);
		this->LastOverlappedItemActorComponent = nullptr;
		this->TransportingConveyor->HandleItemActorOverlapEndEvent(this, ItemActorComponentOverlapped);
	}

	if (OverlappedStaticMeshComponent == this->TransportingConveyor->InputConnector->StaticMeshComponent)
		this->TransportingConveyor->HandleItemActorOverlapEndEvent(this, this->TransportingConveyor->InputConnector);
	else if (OverlappedStaticMeshComponent == this->TransportingConveyor->OutputConnector->StaticMeshComponent)
		this->TransportingConveyor->HandleItemActorOverlapEndEvent(this, this->TransportingConveyor->OutputConnector);

	return;
}

void UFGItemActorComponent::SetStaticMesh()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));

	this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	check(this->StaticMeshComponent->SetStaticMesh(CubeMesh.Object));

	//check(this->StaticMeshComponent->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform));
	//this->StaticMeshComponent->RegisterComponent();

	//// Bind Overlap Events
	//this->StaticMeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	//this->StaticMeshComponent->SetGenerateOverlapEvents(true);
	//this->StaticMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &UFGItemActorComponent::OnOverlapBegin);
	//this->StaticMeshComponent->OnComponentEndOverlap.AddDynamic(this, &UFGItemActorComponent::OnOverlapEnd);

	return;
}

