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

	void RemoveItemActorComponent(UFGItemActorComponent* InItemActorComponent);

	bool IsCycleReturned() const;

	const float GetCycleTime() const { return 60.0f / this->TransportVolumePerMinute; }
	const FVector GetTransportDirection() const;
	UFGItemActorComponent* GetItemActorComponent(UStaticMeshComponent* InStaticMesh) { return this->TransportingItems[InStaticMesh]; }

	void RegisterItemActor(UFGItemActorComponent* InItemActor);

protected:

	virtual void BeginPlay() override;
	virtual void InitializeStaticMeshComponent() override;

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
	TMap<UStaticMeshComponent*, UFGItemActorComponent*> TransportingItems;

	UFGItemActorComponent* ItemActorOverlappingOutputConnector;
};
