#pragma once

#include "CoreMinimal.h"
#include "FGFactoryUnit.h"
#include "FGConveyorBelt.generated.h"

class UFGItemActorComponent;
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

	// InItemActor와 그 직전 ItemActor의 충돌을 처리한다.
	void HandleItemActorOverlapBeginEvent(UFGItemActorComponent* InItemActor1, UFGItemActorComponent* InItemActor2);
	void HandleItemActorOverlapBeginEvent(UFGItemActorComponent* InItemActor, UFGUnitConnectorComponent* InUnitConnector);
	void HandleItemActorOverlapEndEvent(UFGItemActorComponent* InItemActor, UFGItemActorComponent* InItemActor2);
	void HandleItemActorOverlapEndEvent(UFGItemActorComponent* InItemActor, UFGUnitConnectorComponent* InUnitConnector);

	bool IsCycleReturned() const;

	const FVector GetTransportDirection() const;

private:

	// Creates An ItemActorComponent At InputConnector's World Location.
	// Should NOT be called when "bCanSpawnAnotherItem" is false
	void CreateItemActorComponent(UFGItem* InItem);

public:

	UPROPERTY(EditAnywhere, Category = "Factory")
	UFGUnitConnectorComponent* InputConnector;

	UPROPERTY(EditAnywhere, Category = "Factory")
	UFGUnitConnectorComponent* OutputConnector;

private:

	bool bCanSpawnAnotherItem;

	uint32 TransportVolumePerMinute;
	TList<UFGItemActorComponent*>* TransportingItems;
};
