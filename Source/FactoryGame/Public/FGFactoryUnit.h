#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FGFactoryUnit.generated.h"

class UFGItem;

UCLASS()
class FACTORYGAME_API AFGFactoryUnit : public AActor
{
	GENERATED_BODY()
	
public:

	AFGFactoryUnit() : AFGFactoryUnit(0, 0) {};
	AFGFactoryUnit(const uint32 _InputSize, const uint32 _OutputSize);

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;
	virtual void Work(float DeltaTime);
	virtual void NotifyInputChanged();
	virtual void NotifyOutputChanged();

	virtual void SetStaticMeshComponent();

	virtual void StoreItem(UFGItem* _Item);
	virtual void RemoveItem(UFGItem* _Item);

	virtual bool CanStoreItem(UFGItem* _Item);
	virtual bool CanRemoveItem(UFGItem* _Item);

protected:

	virtual void UpdateRunningState();

public:

protected:

	UStaticMeshComponent* StaticMeshComponent;

	float WorkTime;
	
	bool bInputsValid;
	bool bOutputsValid;

};
