#include "FGUnitConnectorComponent.h"
#include "FGFactoryUnit.h"

UFGUnitConnectorComponent::UFGUnitConnectorComponent()
	: Super()
	, InputUnit(nullptr)
	, OutputUnit(nullptr)
	, StaticMeshComponent(nullptr)
{
	PrimaryComponentTick.bCanEverTick = false;

	this->InitializeStaticMeshComponent();
}

void UFGUnitConnectorComponent::BeginPlay()
{
	Super::BeginPlay();	
}

void UFGUnitConnectorComponent::SetStaticMeshComponentProperty(
	const FVector& _Location,
	const FRotator& _Rotation
)
{
	this->StaticMeshComponent->SetRelativeLocation(_Location);
	this->StaticMeshComponent->SetRelativeRotation(_Rotation);
}

void UFGUnitConnectorComponent::NotifyInputChanged()
{
	UE_LOG(LogTemp, Warning, TEXT("Notify Input Changed Called, UnitConnector"));

	if (this->InputUnit) { this->InputUnit->NotifyOutputChanged(); }
	if (this->OutputUnit) { this->OutputUnit->NotifyInputChanged(); }
}

void UFGUnitConnectorComponent::NotifyOutputChanged()
{
	UE_LOG(LogTemp, Warning, TEXT("Notify Output Changed Called, UnitConnector"));

	if (this->InputUnit) { this->InputUnit->NotifyOutputChanged(); }
	if (this->OutputUnit) { this->OutputUnit->NotifyInputChanged(); }
}

void UFGUnitConnectorComponent::InitializeStaticMeshComponent()
{
	// Creating StaticMeshComponent
	AActor* Owner = this->GetOwner();
	if (!Owner) return;

	this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh_UnitConnector"));
	if (!this->StaticMeshComponent) return;

	// Initializing StaticMeshComponent
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	this->StaticMeshComponent->SetStaticMesh(CubeMesh.Object);

	this->StaticMeshComponent->SetupAttachment(Owner->GetRootComponent());
	this->StaticMeshComponent->RegisterComponent();

	// Set World Scale Fixed
	this->StaticMeshComponent->SetWorldScale3D(FVector(0.05f, 0.15f, 0.08f));
	this->StaticMeshComponent->SetUsingAbsoluteScale(true);

	return;
}
