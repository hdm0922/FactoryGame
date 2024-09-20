#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FGUnitConnectorComponent.generated.h"

class AFGFactoryUnit;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FACTORYGAME_API UFGUnitConnectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFGUnitConnectorComponent();

protected:

	virtual void BeginPlay() override;

public:	

	void SetStaticMeshComponentProperty(const FVector& _Location, const FRotator& _Rotation = FRotator::ZeroRotator, const FVector& _Scale = FVector(1.0f));

	void NotifyInputChanged();
	void NotifyOutputChanged();

	void SetInputUnit(AFGFactoryUnit* _FactoryUnit) { this->InputUnit = _FactoryUnit; }
	void SetOutputUnit(AFGFactoryUnit* _FactoryUnit) { this->OutputUnit = _FactoryUnit; }

	AFGFactoryUnit* GetInputUnit() const { return this->InputUnit; }
	AFGFactoryUnit* GetOutputUnit() const { return this->OutputUnit; }

private:

	void InitializeStaticMeshComponent();

public:

	UPROPERTY(EditAnywhere, Category = "Connector")
	AFGFactoryUnit* InputUnit;

	UPROPERTY(EditAnywhere, Category = "Connector")
	AFGFactoryUnit* OutputUnit;

private:

	UStaticMeshComponent* StaticMeshComponent;

};
