#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FGIOGate.generated.h"

class AFGFactoryUnit;
class UFGItemStorage;

UCLASS()
class FACTORYGAME_API AFGIOGate : public AActor
{
	GENERATED_BODY()
	
public:	

	AFGIOGate();

	static AFGIOGate* CreateIOGateWithItemSlot();
	static AFGIOGate* CreateIOGateWithItemBuffer();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(EditAnywhere, Category = "Factory")
	AFGFactoryUnit* PrevFactoryUnit;

	UPROPERTY(EditAnywhere, Category = "Factory")
	AFGFactoryUnit* NextFactoryUnit;

	UFGItemStorage* ItemStorage;

};
