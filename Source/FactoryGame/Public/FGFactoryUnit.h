#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FGFactoryUnit.generated.h"

class UFGItem;
class UFGItemStorage;

UCLASS()
class FACTORYGAME_API AFGFactoryUnit : public AActor
{
	GENERATED_BODY()
	
public:

	AFGFactoryUnit();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;
	virtual void Work(float DeltaTime);
	virtual void NotifyInputChanged();
	virtual void NotifyOutputChanged();

	virtual void StoreItem(UFGItemStorage* _ItemStorage, UFGItem* _Item);
	virtual void RemoveItem(UFGItemStorage* _ItemStorage, UFGItem* _Item);
	virtual bool CanStoreItem(UFGItemStorage* _ItemStorage, UFGItem* _Item);
	virtual bool CanRemoveItem(UFGItemStorage* _ItemStorage, UFGItem* _Item);

protected:

	virtual void InitializeStaticMeshComponent();
	virtual bool CanWork();

	void UpdateRunningState();

protected:

	UStaticMeshComponent* StaticMeshComponent;

	float WorkTime;
	
	bool bInputsValid;
	bool bOutputsValid;

};
