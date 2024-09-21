#include "FGConveyorBelt.h"
#include "FGUnitConnectorComponent.h"
#include "FGItemActorComponent.h"

AFGConveyorBelt::AFGConveyorBelt(const uint32 InTransportVolumePerMinute)
	: Super()

	, InputConnector(nullptr)
	, OutputConnector(nullptr)

	, bCanSpawnAnotherItem(true)
	, TransportVolumePerMinute(InTransportVolumePerMinute)
	, TransportingItems(nullptr)
{
}

void AFGConveyorBelt::Work(float DeltaTime)
{
	Super::Work(DeltaTime);

	if (!this->IsCycleReturned()) return;
	this->WorkTime = 0.0f;

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
	if (InUnitConnector == this->InputConnector)
		this->bCanSpawnAnotherItem = true;

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

void AFGConveyorBelt::CreateItemActorComponent(UFGItem* InItem)
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Owner = this;

	UFGItemActorComponent* ItemActorCreated = 
		this->GetWorld()->SpawnActor<UFGItemActorComponent>(
			UFGItemActorComponent::StaticClass(),
			this->InputConnector->GetWorldLocation() -
			this->GetActorLocation(),
			FRotator::ZeroRotator,
			SpawnParams
		);

	ItemActorCreated->SetTransportingConveyor(this);
	ItemActorCreated->SetItemData(InItem);

	this->TransportingItems = new TList<UFGItemActorComponent*>(ItemActorCreated, this->TransportingItems);
}
