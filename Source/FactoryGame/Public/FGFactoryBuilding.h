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

	AFGFactoryBuilding() : AFGFactoryBuilding(4,1) {}
	AFGFactoryBuilding(const uint32 _InputSize, const uint32 _OutputSize);

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
	virtual void Work(float DeltaTime) override;
	virtual void NotifyInputChanged() override;
	virtual void NotifyOutputChanged() override;

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
	TArray<UFGUnitConnectorComponent*> OutputConnectors;

	UPROPERTY(EditAnywhere, Category = "Output")
	TMap<uint32, UFGItemSlot*> OutputItemSlots;


	UPROPERTY(EditAnywhere, Category = "Recipe")
	UFGRecipe* Recipe;

};