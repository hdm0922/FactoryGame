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

	this->SetStaticMeshComponent();
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

void AFGFactoryUnit::SetStaticMeshComponent()
{
	this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	this->RootComponent = StaticMeshComponent;

	return;
}

void AFGFactoryUnit::StoreItem(UFGItem* _Item)
{
	checkf(false, TEXT("ABSTRACT"));
}

void AFGFactoryUnit::RemoveItem(UFGItem* _Item)
{
	checkf(false, TEXT("ABSTRACT"));
}

bool AFGFactoryUnit::CanStoreItem(UFGItem* _Item)
{
	checkf(false, TEXT("ABSTRACT"));
	return false;
}

bool AFGFactoryUnit::CanRemoveItem(UFGItem* _Item)
{
	checkf(false, TEXT("ABSTRACT"));
	return false;
}

void AFGFactoryUnit::UpdateRunningState()
{
	const bool bCanWork = this->bInputsValid && this->bOutputsValid;
	this->SetActorTickEnabled(bCanWork);

	return;
}
