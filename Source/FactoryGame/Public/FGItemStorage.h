#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FGItemStorage.generated.h"

class UFGItem;

UCLASS()
class FACTORYGAME_API UFGItemStorage : public UObject
{
	GENERATED_BODY()
	
public:

	virtual void Store(UFGItem* _Item, uint32 _LoadSize = 1);
	virtual void Remove(uint32 _LoadSize);

	virtual bool CanStore(UFGItem* _Item, uint32 _LoadSize = 1);
	virtual bool CanRemove(uint32 _LoadSize = 1);

};
