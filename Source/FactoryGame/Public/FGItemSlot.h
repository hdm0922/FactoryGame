#pragma once

#include "CoreMinimal.h"
#include "FGItemStorage.h"
#include "FGItemSlot.generated.h"

UCLASS()
class FACTORYGAME_API UFGItemSlot : public UFGItemStorage
{
	GENERATED_BODY()
	
public:

	UFGItemSlot();

public:

	virtual void Initialize(UFGItem* _Item = nullptr) override;

	virtual void Store(UFGItem* _Item, uint32 _LoadSize = 1) override;
	virtual void Remove(uint32 _LoadSize) override;

	virtual bool CanStore(UFGItem* _Item, uint32 _LoadSize = 1) const override;
	virtual bool CanRemove(uint32 _LoadSize = 1) const override;

	const UFGItem* GetItemSample() const { return this->Item; }
	const uint32 GetItemsInSlot() const { return this->ItemsInSlot; }

private:

	UFGItem* Item;
	uint32 ItemsInSlot;

};
