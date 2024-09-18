#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FGFactoryUnit.generated.h"

class AFGIOGate;

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

protected:

	virtual void UpdateRunningState();

public:

	UPROPERTY(EditAnywhere, Category = "Factory")
	TArray<AFGIOGate*> InputGates;

	UPROPERTY(EditAnywhere, Category = "Factory")
	TArray<AFGIOGate*> OutputGates;

protected:

	UStaticMeshComponent* StaticMeshComponent;

	float WorkTime;
	
	bool bInputsValid;
	bool bOutputsValid;

};
