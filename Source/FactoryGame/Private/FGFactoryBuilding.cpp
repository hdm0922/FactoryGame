#include "FGFactoryBuilding.h"
#include "FGRecipe.h"
#include "FGUnitConnector.h"

AFGFactoryBuilding::AFGFactoryBuilding(const uint32 _InputSize, const uint32 _OutputSize)
	: Super(_InputSize, _OutputSize)
	, InputConnectors(TArray<AFGUnitConnector*>(nullptr, _InputSize))
	, OutputConnectors(TArray<AFGUnitConnector*>(nullptr, _InputSize))
{
}

void AFGFactoryBuilding::BeginPlay()
{
	Super::BeginPlay();
}

void AFGFactoryBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFGFactoryBuilding::Work(float DeltaTime)
{
	Super::Work(DeltaTime);

	const bool bWorkTimeOver = (this->WorkTime > this->Recipe->WorkTime);
	if (bWorkTimeOver)
	{
		this->WorkTime = 0.0f;
		this->ProduceOutput();
	}

	return;
}

void AFGFactoryBuilding::NotifyInputChanged()
{
}

void AFGFactoryBuilding::NotifyOutputChanged()
{
}

void AFGFactoryBuilding::SetStaticMeshComponent()
{
}

void AFGFactoryBuilding::StoreItem(UFGItem* _Item)
{
}

void AFGFactoryBuilding::RemoveItem(UFGItem* _Item)
{
}

bool AFGFactoryBuilding::CanStoreItem(UFGItem* _Item)
{
	return false;
}

bool AFGFactoryBuilding::CanRemoveItem(UFGItem* _Item)
{
	return false;
}

void AFGFactoryBuilding::UpdateRunningState()
{
}

void AFGFactoryBuilding::ProduceOutput()
{
	// Remove Input Items
	

	// Store Output Items

	return;
}
