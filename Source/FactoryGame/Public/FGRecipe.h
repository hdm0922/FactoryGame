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
	TArray<UFGItem*> InputItems;

	UPROPERTY(EditAnywhere, Category = "Input")
	TArray<uint32> InputItemsCount;

	UPROPERTY(EditAnywhere, Category = "Output")
	TArray<UFGItem*> OutputItems;

	UPROPERTY(EditAnywhere, Category = "Output")
	TArray<uint32> OutputItemsCount;
};
