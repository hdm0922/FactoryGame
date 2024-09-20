#include "FGConveyorBelt.h"
#include "FGUnitConnectorComponent.h"

AFGConveyorBelt::AFGConveyorBelt(const uint32 InTransportVolumePerMinute)
	: Super()

	, InputConnector(nullptr)
	, OutputConnector(nullptr)

	, bReceivedSleepRequest(false)
	, TransportVolumePerMinute(InTransportVolumePerMinute)
	, NumberOfItemsSleeping(0)
	, TransportingItems({})
{
}

void AFGConveyorBelt::Work(float DeltaTime)
{
	Super::Work(DeltaTime);

	if (!this->IsCycleReturned()) return;
	this->WorkTime = 0.0f;

	if (this->bReceivedSleepRequest)
	{
		this->bReceivedSleepRequest = false;
		this->SetActorTickEnabled(false);
		return;
	}

	uint32 ItemIndex = 0;
	while (ItemIndex++ < this->NumberOfItemsSleeping)
		this->TransportingItems = *this->TransportingItems.Next;

	// Element (= ItemActor) Update
	while (this->TransportingItems.Next)
		this->TransportingItems.Element;
}

void AFGConveyorBelt::NotifyInputChanged()
{
	const bool BNewInputValid = this->InputConnector->InputUnit->CanRemoveItem(nullptr);
	if (this->bInputsValid == BNewInputValid) return;

	this->bInputsValid = BNewInputValid;
}

void AFGConveyorBelt::NotifyOutputChanged()
{
}

bool AFGConveyorBelt::IsCycleReturned() const
{
	const float CycleTime = (60.0f / this->TransportVolumePerMinute);
	return (this->WorkTime > CycleTime);
}
