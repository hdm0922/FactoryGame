#pragma once

#include "CoreMinimal.h"
#include "FGFactoryUnit.h"
#include "FGConveyorBelt.generated.h"

class AFGItemActorComponent;
class UFGUnitConnectorComponent;

UCLASS()
class FACTORYGAME_API AFGConveyorBelt : public AFGFactoryUnit
{
	GENERATED_BODY()
	
public:

	AFGConveyorBelt() : AFGConveyorBelt(60) {}
	AFGConveyorBelt(const uint32 InTransportVolumePerMinute);

	virtual void Work(float DeltaTime) override;
	virtual void NotifyInputChanged() override;
	virtual void NotifyOutputChanged() override;

	bool IsCycleReturned() const;

public:

	UPROPERTY(EditAnywhere, Category = "Factory")
	UFGUnitConnectorComponent* InputConnector;

	UPROPERTY(EditAnywhere, Category = "Factory")
	UFGUnitConnectorComponent* OutputConnector;

private:

	bool bReceivedSleepRequest;

	uint32 TransportVolumePerMinute;
	uint32 NumberOfItemsSleeping;

	TList<AFGItemActorComponent*> TransportingItems;
};
