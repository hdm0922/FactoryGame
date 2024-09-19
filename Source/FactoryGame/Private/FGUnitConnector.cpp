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
	if (!this->InputUnit) return;
	this->InputUnit->NotifyOutputChanged();

	return;
}

void AFGUnitConnector::NotifyOutputChanged()
{
	if (!this->OutputUnit) return;
	this->OutputUnit->NotifyInputChanged();

	return;
}

