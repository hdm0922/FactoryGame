#include "FGFactoryUnit.h"
#include "FGItem.h"

AFGFactoryUnit::AFGFactoryUnit()
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

void AFGFactoryUnit::StoreItem(UFGItem* InItem, uint32 InLoadSize)
{
	checkf(false, TEXT("ABSTRACT"));
}

void AFGFactoryUnit::RemoveItem(UFGItem* InItem, uint32 InLoadSize)
{
	checkf(false, TEXT("ABSTRACT"));
}

bool AFGFactoryUnit::CanStoreItem(UFGItem* InItem, uint32 InLoadSize)
{
	checkf(false, TEXT("ABSTRACT"));
	return false;
}

bool AFGFactoryUnit::CanRemoveItem(UFGItem* InItem, uint32 InLoadSize)
{
	checkf(false, TEXT("ABSTRACT"));
	return false;
}

UFGItem* AFGFactoryUnit::GetItemSample() const
{
	checkf(false, TEXT("ABSTRACT"));
	return nullptr;
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