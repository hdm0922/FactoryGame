#include "FGConveyorBelt.h"
#include "FGUnitConnectorComponent.h"

AFGConveyorBelt::AFGConveyorBelt(const uint32 InTransportVolumePerMinute)
	: Super()

	, InputConnector(nullptr)
	, OutputConnector(nullptr)

	, bCanSpawnAnotherItem(true)
	, TransportVolumePerMinute(InTransportVolumePerMinute)
	, TransportingItems({})
{
}

void AFGConveyorBelt::Work(float DeltaTime)
{
	Super::Work(DeltaTime);

	//uint32 ItemIndex = 0;
	//while (ItemIndex++ < this->NumberOfItemsSleeping)
	//	this->TransportingItems = *this->TransportingItems.Next;

	//// Element (= ItemActor) Update
	//while (this->TransportingItems.Next)
	//	this->TransportingItems.Element;

	if (!this->IsCycleReturned()) return;
	this->WorkTime = 0.0f;

	//if (this->bReceivedSleepRequest)
	//{
	//	this->bReceivedSleepRequest = false;
	//	this->SetActorTickEnabled(false);
	//	return;
	//}

	if (UFGItem* ItemFetched = this->InputConnector->FetchItem())
	{

	}
}

void AFGConveyorBelt::NotifyInputChanged()
{
	const bool BNewInputValid = this->InputConnector->CanFetchItem();
	if (this->bInputsValid == BNewInputValid) return;

	this->bInputsValid = BNewInputValid;
	this->UpdateRunningState();
}

void AFGConveyorBelt::NotifyOutputChanged()
{
}

void AFGConveyorBelt::HandleItemActorOverlapBeginEvent(
	UFGItemActorComponent* InItemActor1, 
	UFGItemActorComponent* InItemActor2
)
{
	check(false);
	return;
}

void AFGConveyorBelt::HandleItemActorOverlapBeginEvent(
	UFGItemActorComponent* InItemActor, 
	UFGUnitConnectorComponent* InUnitConnector
)
{
	check(false);
	return;
}

void AFGConveyorBelt::HandleItemActorOverlapEndEvent(
	UFGItemActorComponent* InItemActor1, 
	UFGItemActorComponent* InItemActor2
)
{
	check(false);
	return;
}

void AFGConveyorBelt::HandleItemActorOverlapEndEvent(
	UFGItemActorComponent* InItemActor, 
	UFGUnitConnectorComponent* InUnitConnector
)
{
	check(false);
	return;
}

bool AFGConveyorBelt::IsCycleReturned() const
{
	const float CycleTime = (60.0f / this->TransportVolumePerMinute);
	return (this->WorkTime > CycleTime);
}

const FVector AFGConveyorBelt::GetTransportDirection() const
{
	
	const FVector TransportDirection =
		this->OutputConnector->GetWorldLocation() -
		this->InputConnector->GetWorldLocation();

	return TransportDirection.GetUnsafeNormal();
}
