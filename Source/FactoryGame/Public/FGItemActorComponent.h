#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "FGItemActorComponent.generated.h"

class AFGConveyorBelt;
class UFGItem;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FACTORYGAME_API UFGItemActorComponent : public USceneComponent
{
	GENERATED_BODY()

public:	

	UFGItemActorComponent();

protected:

	virtual void BeginPlay() override;

public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void NotifyPrevItemDestroyed();
	void SetTransportingConveyor(AFGConveyorBelt* InConveyorBelt) { this->TransportingConveyor = InConveyorBelt; }

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void SetItemData(UFGItem* InItem) { this->ItemData = InItem; }

private:

	void SetStaticMesh();

private:

	UStaticMeshComponent* StaticMeshComponent;

	UFGItem* ItemData;
	AFGConveyorBelt* TransportingConveyor;

};
