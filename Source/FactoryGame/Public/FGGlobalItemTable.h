#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FGItem.h"
#include "FGGlobalItemTable.generated.h"

UCLASS()
class FACTORYGAME_API UFGGlobalItemTable : public UDataAsset
{
	GENERATED_BODY()
	
public:

	static UFGItem* GetItem(const uint32 _ItemID) { return GlobalItemTable[_ItemID]; }

public:

	static TArray<UFGItem*> GlobalItemTable;

	UPROPERTY(EditAnywhere, Category = "Data")
	TArray<UFGItem*> ItemTable;
};
