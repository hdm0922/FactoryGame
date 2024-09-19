#include "FGUnitConnector.h"
#include "FGFactoryUnit.h"

AFGUnitConnector::AFGUnitConnector()
	: Super()
	, InputUnit(nullptr)
	, OutputUnit(nullptr)
{
	PrimaryActorTick.bCanEverTick = false;

}

void AFGUnitConnector::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFGUnitConnector::NotifyInputChanged()
{
	UE_LOG(LogTemp, Warning, TEXT("Notify Input Changed Called, UnitConnector"));
	if (!this->InputUnit) return;
	this->InputUnit->NotifyOutputChanged();

	return;
}

void AFGUnitConnector::NotifyOutputChanged()
{
	UE_LOG(LogTemp, Warning, TEXT("Notify Output Changed Called, UnitConnector"));
	if (!this->OutputUnit) return;
	this->OutputUnit->NotifyInputChanged();

	return;
}

void AFGUnitConnector::InitializeStaticMeshComponent()
{
	this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	this->RootComponent = StaticMeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	this->StaticMeshComponent->SetStaticMesh(CubeMesh.Object);

	return;

}

