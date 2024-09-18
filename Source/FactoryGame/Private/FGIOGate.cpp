#include "FGIOGate.h"
#include "FGFactoryUnit.h"

AFGIOGate::AFGIOGate()
{
	PrimaryActorTick.bCanEverTick = true;

}

AFGIOGate* AFGIOGate::CreateIOGateWithItemSlot()
{
	return nullptr;
}

AFGIOGate* AFGIOGate::CreateIOGateWithItemBuffer()
{
	return nullptr;
}

void AFGIOGate::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFGIOGate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

