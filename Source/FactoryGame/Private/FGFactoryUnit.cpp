#include "FGFactoryUnit.h"
#include "FGItem.h"

AFGFactoryUnit::AFGFactoryUnit(const uint32 _InputSize, const uint32 _OutputSize)
	: Super()

	, StaticMeshComponent(nullptr)
	, WorkTime(0.0f)

	, bInputsValid(false)
	, bOutputsValid(false)
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFGFactoryUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFGFactoryUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->Work(DeltaTime);

	return;
}

void AFGFactoryUnit::Work(float DeltaTime)
{
	this->WorkTime += DeltaTime;

	return;
}

void AFGFactoryUnit::NotifyInputChanged()
{
}

void AFGFactoryUnit::NotifyOutputChanged()
{
}

void AFGFactoryUnit::StoreItem(UFGItemStorage* _ItemStorage, UFGItem* _Item)
{
	checkf(false, TEXT("ABSTRACT"));
}

void AFGFactoryUnit::RemoveItem(UFGItemStorage* _ItemStorage, UFGItem* _Item)
{
	checkf(false, TEXT("ABSTRACT"));
}

bool AFGFactoryUnit::CanStoreItem(UFGItemStorage* _ItemStorage, UFGItem* _Item)
{
	checkf(false, TEXT("ABSTRACT"));
	return false;
}

bool AFGFactoryUnit::CanRemoveItem(UFGItemStorage* _ItemStorage, UFGItem* _Item)
{
	checkf(false, TEXT("ABSTRACT"));
	return false;
}

void AFGFactoryUnit::InitializeStaticMeshComponent()
{
	this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	this->RootComponent = StaticMeshComponent;

	return;
}


void AFGFactoryUnit::UpdateRunningState()
{
	this->SetActorTickEnabled(this->CanWork());
	UE_LOG(LogTemp, Warning, TEXT("Now FactoryUnit's Tick Set As : %d"), this->CanWork());

	return;
}

bool AFGFactoryUnit::CanWork()
{
	return (this->bInputsValid && this->bOutputsValid);
}