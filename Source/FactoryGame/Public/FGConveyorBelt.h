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

	AFGConveyorBelt();

	virtual void Work(float DeltaTime) override;
	virtual void NotifyInputChanged() override;
	virtual void NotifyOutputChanged() override;

public:

	UPROPERTY(EditAnywhere, Category = "Factory")
	UFGUnitConnectorComponent* InputConnector;

	UPROPERTY(EditAnywhere, Category = "Factory")
	UFGUnitConnectorComponent* OutputConnector;

private:

	uint32 NumberOfItemsSleeping;

	TList<AFGItemActorComponent*> TransportingItems;
};
