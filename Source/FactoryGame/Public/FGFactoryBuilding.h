#pragma once

#include "CoreMinimal.h"
#include "FGFactoryUnit.h"
#include "FGFactoryBuilding.generated.h"

class AFGUnitConnector;
class UFGConnectorComponent;
class UFGItemSlot;
class UFGRecipe;

UCLASS()
class FACTORYGAME_API AFGFactoryBuilding : public AFGFactoryUnit
{
	GENERATED_BODY()
	
public:

	AFGFactoryBuilding() : AFGFactoryBuilding(1,1) {}
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

	virtual void SetInputConnectorsProperty();
	virtual void SetOutputConnectorsProperty();

	virtual bool CanWork() override;

private:

	AFGUnitConnector* CreateConnector(const FVector& _Location);
	void CreateInputConnectors();
	void CreateOutputConnectors();

	bool IsAllInputsValid() const;
	bool IsAllOutputsValid() const;

public:

	UPROPERTY(EditAnywhere, Category = "Input")
	TArray<AFGUnitConnector*> InputConnectors;

	UPROPERTY(EditAnywhere, Category = "Input")
	TMap<uint32, UFGItemSlot*> InputItemSlots;


	UPROPERTY(EditAnywhere, Category = "Output")
	TArray<AFGUnitConnector*> OutputConnectors;

	UPROPERTY(EditAnywhere, Category = "Output")
	TMap<uint32, UFGItemSlot*> OutputItemSlots;


	UPROPERTY(EditAnywhere, Category = "Recipe")
	UFGRecipe* Recipe;

};