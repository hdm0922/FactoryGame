#include "FGConveyorBelt.h"

AFGConveyorBelt::AFGConveyorBelt()
	: Super()

	, InputConnector(nullptr)
	, OutputConnector(nullptr)

	, NumberOfItemsSleeping(0)
	, TransportingItems({})
{
}

void AFGConveyorBelt::Work(float DeltaTime)
{
	Super::Work(DeltaTime);

	uint32 ItemIndex = 0;
	while (ItemIndex < this->NumberOfItemsSleeping)
		this->TransportingItems = *this->TransportingItems.Next;

	while (this->TransportingItems.Next)
		this->TransportingItems.Element;
}

void AFGConveyorBelt::NotifyInputChanged()
{
}

void AFGConveyorBelt::NotifyOutputChanged()
{
}
