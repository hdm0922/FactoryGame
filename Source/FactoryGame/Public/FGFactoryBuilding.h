#pragma once

#include "CoreMinimal.h"
#include "FGFactoryUnit.h"
#include "FGFactoryBuilding.generated.h"

class AFGUnitConnector;
class UFGItemSlot;
class UFGRecipe;

UCLASS()
class FACTORYGAME_API AFGFactoryBuilding : public AFGFactoryUnit
{
	GENERATED_BODY()
	
public:

	AFGFactoryBuilding() : AFGFactoryBuilding(0,0) {}
	AFGFactoryBuilding(const uint32 _InputSize, const uint32 _OutputSize);

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
	virtual void Work(float DeltaTime) override;
	virtual void NotifyInputChanged() override;
	virtual void NotifyOutputChanged() override;
	virtual void SetStaticMeshComponent() override;

protected:

	virtual void UpdateRunningState() override;
	virtual void ProduceOutput();

public:

	UPROPERTY(EditAnywhere, Category = "Input")
	TArray<AFGUnitConnector*> InputConnectors;

	UPROPERTY(EditAnywhere, Category = "Output")
	TArray<AFGUnitConnector*> OutputConnectors;

	UPROPERTY(EditAnywhere, Category = "Recipe")
	UFGRecipe* Recipe;

};
