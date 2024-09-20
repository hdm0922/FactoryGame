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
	const FRotator& _Rotation,
	const FVector& _Scale)
{
	this->StaticMeshComponent->SetRelativeLocation(_Location);
	this->StaticMeshComponent->SetRelativeRotation(_Rotation);
	this->StaticMeshComponent->SetRelativeScale3D(_Scale);
}

void UFGUnitConnectorComponent::NotifyInputChanged()
{
	UE_LOG(LogTemp, Warning, TEXT("Notify Input Changed Called, UnitConnector"));
	if (!this->InputUnit) return;
	this->InputUnit->NotifyOutputChanged();
}

void UFGUnitConnectorComponent::NotifyOutputChanged()
{
	UE_LOG(LogTemp, Warning, TEXT("Notify Output Changed Called, UnitConnector"));
	if (!this->OutputUnit) return;
	this->OutputUnit->NotifyInputChanged();
}

void UFGUnitConnectorComponent::InitializeStaticMeshComponent()
{
	// Creating StaticMeshComponent
	AActor* Owner = this->GetOwner();
	if (!Owner) return;

	this->StaticMeshComponent = NewObject<UStaticMeshComponent>(Owner, UStaticMeshComponent::StaticClass());
	if (!this->StaticMeshComponent) return;

	this->StaticMeshComponent->SetupAttachment(Owner->GetRootComponent());

	// Initializing StaticMeshComponent
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	this->StaticMeshComponent->SetStaticMesh(CubeMesh.Object);

	// Register StaticMeshComponent
	this->StaticMeshComponent->RegisterComponent();

	return;
}
