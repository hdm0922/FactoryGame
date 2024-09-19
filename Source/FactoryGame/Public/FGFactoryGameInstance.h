#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FGFactoryGameInstance.generated.h"

UCLASS()
class FACTORYGAME_API UFGFactoryGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UFGFactoryGameInstance();

	virtual void Init() override;

private:

	void LoadDataAssets();

};