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

	
}

void UFGItemActorComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UFGItemActorComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	Super::OnComponentDestroyed(bDestroyingHierarchy);
	
	if (!this->LastOverlappedItemActorComponent) return;

	this->LastOverlappedItemActorComponent->LastOverlappedItemActorComponent = nullptr;
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

void UFGItemActorComponent::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& SweepResult
)
{
	UFGItemActorComponent* ItemActorComponentOverlapped = Cast<UFGItemActorComponent>(OverlappedComponent);
	if (ItemActorComponentOverlapped &&
		(this->TransportingConveyor == ItemActorComponentOverlapped->TransportingConveyor))
	{
		this->LastOverlappedItemActorComponent = ItemActorComponentOverlapped;
		this->TransportingConveyor->HandleItemActorOverlapBeginEvent(this, ItemActorComponentOverlapped);
	}
		
	UFGUnitConnectorComponent* UnitConnectorOverlapped = Cast<UFGUnitConnectorComponent>(OverlappedComponent);
	if (UnitConnectorOverlapped) this->TransportingConveyor->HandleItemActorOverlapBeginEvent(this, UnitConnectorOverlapped);

	return;
}

void UFGItemActorComponent::OnOverlapEnd(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex
)
{
	UFGItemActorComponent* ItemActorComponentOverlapped = Cast<UFGItemActorComponent>(OverlappedComponent);
	if (ItemActorComponentOverlapped == this->LastOverlappedItemActorComponent)
	{
		this->LastOverlappedItemActorComponent = nullptr;
		this->SetComponentTickEnabled(true);
		this->TransportingConveyor->HandleItemActorOverlapEndEvent(this, ItemActorComponentOverlapped);
	}

	UFGUnitConnectorComponent* UnitConnectorOverlapped = Cast<UFGUnitConnectorComponent>(OverlappedComponent);
	if (UnitConnectorOverlapped) this->TransportingConveyor->HandleItemActorOverlapEndEvent(this, UnitConnectorOverlapped);

	return;
}

void UFGItemActorComponent::SetStaticMesh()
{
	AActor* Owner = this->GetOwner();
	if (!Owner) return;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));

	this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	this->StaticMeshComponent->SetStaticMesh(CubeMesh.Object);

	this->StaticMeshComponent->SetupAttachment(Owner->GetRootComponent());
	this->StaticMeshComponent->RegisterComponent();

	// Set World Scale Fixed
	this->StaticMeshComponent->SetWorldScale3D(FVector(0.05f, 0.15f, 0.08f));
	this->StaticMeshComponent->SetUsingAbsoluteScale(true);

	// Bind Overlap Events
	this->StaticMeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	this->StaticMeshComponent->SetGenerateOverlapEvents(true);
	this->StaticMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &UFGItemActorComponent::OnOverlapBegin);
	this->StaticMeshComponent->OnComponentEndOverlap.AddDynamic(this, &UFGItemActorComponent::OnOverlapEnd);

	return;
}

