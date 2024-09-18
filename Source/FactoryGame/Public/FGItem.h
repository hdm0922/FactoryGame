#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FGItem.generated.h"

UCLASS()
class FACTORYGAME_API UFGItem : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category = "Data")
	FString ItemName;

	UPROPERTY(EditAnywhere, Category = "Data")
	uint32 ItemID;

	UPROPERTY(EditAnywhere, Category = "Data")
	uint32 StackSize;

};
