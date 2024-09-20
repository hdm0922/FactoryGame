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

	// Half Length of Connectors = 25.0f;
	// Can be calculated by :
	// 0.5 * (Connector->GetConnectorBound().BoxExtent[1] *
	// Connector->StaticMeshComponent->GetComponentScale()[1]);
	static float GetUnitConnectorHalfLength() { return 25.0f; }

	void SetStaticMeshComponentProperty(const FVector& _Location, const FRotator& _Rotation = FRotator::ZeroRotator);

	void NotifyInputChanged();
	void NotifyOutputChanged();

	void SetInputUnit(AFGFactoryUnit* _FactoryUnit) { this->InputUnit = _FactoryUnit; }
	void SetOutputUnit(AFGFactoryUnit* _FactoryUnit) { this->OutputUnit = _FactoryUnit; }

	AFGFactoryUnit* GetInputUnit() const { return this->InputUnit; }
	AFGFactoryUnit* GetOutputUnit() const { return this->OutputUnit; }

	FBoxSphereBounds GetConnectorBound() const { return this->StaticMeshComponent->GetStaticMesh()->GetBounds(); }

private:

	void InitializeStaticMeshComponent();

public:

	UPROPERTY(EditAnywhere, Category = "Connector")
	AFGFactoryUnit* InputUnit;

	UPROPERTY(EditAnywhere, Category = "Connector")
	AFGFactoryUnit* OutputUnit;

	UPROPERTY(VisibleAnywhere, Category = "Connector")
	UStaticMeshComponent* StaticMeshComponent;

private:

	

};
