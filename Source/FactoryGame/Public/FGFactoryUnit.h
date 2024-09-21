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

	virtual void StoreItem(UFGItem* InItem, uint32 InLoadSize = 1);
	virtual void RemoveItem(UFGItem* InItem, uint32 InLoadSize = 1);
	virtual bool CanStoreItem(UFGItem* InItem, uint32 InLoadSize = 1);
	virtual bool CanRemoveItem(UFGItem* InItem, uint32 InLoadSize = 1);
	virtual UFGItem* GetItemSample() const;

protected:

	virtual void InitializeStaticMeshComponent();
	virtual bool CanWork();

	virtual void UpdateRunningState();

protected:

	UStaticMeshComponent* StaticMeshComponent;

	float WorkTime;
	
	bool bInputsValid;
	bool bOutputsValid;

};
