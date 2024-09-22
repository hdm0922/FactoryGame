#pragma once

#include "CoreMinimal.h"
#include "FGFactoryUnit.h"
#include "FGFactoryBuilding.generated.h"

class UFGUnitConnectorComponent;
class UFGItemSlot;
class UFGRecipe;

UCLASS()
class FACTORYGAME_API AFGFactoryBuilding : public AFGFactoryUnit
{
	GENERATED_BODY()
	
public:

	AFGFactoryBuilding() : AFGFactoryBuilding(4) {}
	AFGFactoryBuilding(const uint32 _InputSize);

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
	virtual void Work(float DeltaTime) override;
	virtual void NotifyInputChanged() override;
	virtual void NotifyOutputChanged() override;

	// For InputItemSlots
	virtual void StoreItem(UFGItem* InItem, uint32 InLoadSize = 1) override;
	// For OutputItemSlots
	virtual void RemoveItem(UFGItem* InItem, uint32 InLoadSize = 1) override;
	// Check InputItemSlots
	virtual bool CanStoreItem(UFGItem* InItem, uint32 InLoadSize = 1) override;
	// Check OutputItemSlots
	virtual bool CanRemoveItem(UFGItem* InItem, uint32 InLoadSize = 1) override;

	virtual UFGItem* GetItemSample() const override;

	void SelectRecipe(uint32 _RecipeID);
	void SelectRecipe(UFGRecipe* _Recipe);

protected:

	virtual void InitializeStaticMeshComponent() override;
	virtual void ProduceOutput();

	virtual bool CanWork() override;

private:

	void CreateInputConnectors(const uint32 _InputSize);
	void CreateOutputConnectors(const uint32 _OutputSize);
	void PlaceConnectorsArray(const FVector& _BeginLocation, TArray<UFGUnitConnectorComponent*>& _ConnectorsArray);

	bool IsAllInputsValid() const;
	bool IsAllOutputsValid() const;

public:

	UPROPERTY(EditAnywhere, Category = "Input")
	TArray<UFGUnitConnectorComponent*> InputConnectors;

	UPROPERTY(EditAnywhere, Category = "Input")
	TMap<uint32, UFGItemSlot*> InputItemSlots;


	UPROPERTY(EditAnywhere, Category = "Output")
	UFGUnitConnectorComponent* OutputConnector;

	UPROPERTY(EditAnywhere, Category = "Output")
	UFGItemSlot* OutputItemSlot;


	UPROPERTY(EditAnywhere, Category = "Recipe")
	UFGRecipe* Recipe;

};