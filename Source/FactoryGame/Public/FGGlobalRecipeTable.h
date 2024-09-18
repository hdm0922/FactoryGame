#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FGRecipe.h"
#include "FGGlobalRecipeTable.generated.h"

UCLASS()
class FACTORYGAME_API UFGGlobalRecipeTable : public UDataAsset
{
	GENERATED_BODY()
	
public:

	static UFGRecipe* GetRecipe(const uint32 _RecipeID) { return UFGGlobalRecipeTable::GlobalRecipeTable[_RecipeID]; }

public:

	static TArray<UFGRecipe*> GlobalRecipeTable;

	UPROPERTY(EditAnywhere, Category = "Data")
	TArray<UFGRecipe*> RecipeData;
};
