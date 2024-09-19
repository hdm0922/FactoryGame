#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FGUnitConnector.generated.h"

class AFGFactoryUnit;

UCLASS()
class FACTORYGAME_API AFGUnitConnector : public AActor
{
	GENERATED_BODY()
	
public:	

	AFGUnitConnector();

protected:

	virtual void BeginPlay() override;

public:	

	void NotifyInputChanged();
	void NotifyOutputChanged();

	void SetInputUnit(AFGFactoryUnit* _FactoryUnit) { this->InputUnit = _FactoryUnit; }
	void SetOutputUnit(AFGFactoryUnit* _FactoryUnit) { this->OutputUnit = _FactoryUnit; }

	AFGFactoryUnit* GetInputUnit() const { return this->InputUnit; }
	AFGFactoryUnit* GetOutputUnit() const { return this->OutputUnit; }

public:

	UPROPERTY(EditAnywhere, Category = "Connector")
	AFGFactoryUnit* InputUnit;

	UPROPERTY(EditAnywhere, Category = "Connector")
	AFGFactoryUnit* OutputUnit;

};
