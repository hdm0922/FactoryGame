#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FGItem.h"
#include "FGRecipe.generated.h"

UCLASS()
class FACTORYGAME_API UFGRecipe : public UDataAsset
{
	GENERATED_BODY()
	
public:

	int32 GetInputSize() const { return this->InputItems.Num(); }
	int32 GetOutputSize() const { return this->OutputItems.Num(); }

public:

	UPROPERTY(EditAnywhere, Category = "Recipe")
	FString RecipeName;

	UPROPERTY(EditAnywhere, Category = "Recipe")
	uint32 RecipeID;

	UPROPERTY(EditAnywhere, Category = "Recipe")
	float WorkTime;

	UPROPERTY(EditAnywhere, Category = "Input")
	TMap<UFGItem*, uint32> InputItems;

	UPROPERTY(EditAnywhere, Category = "Output")
	TMap<UFGItem*, uint32> OutputItems;

};
