#include "FGItemSlot.h"
#include "FGItem.h"

UFGItemSlot::UFGItemSlot()
	: Super()
	, Item(nullptr)
	, ItemsInSlot(0)
{
}

void UFGItemSlot::Initialize(UFGItem* _Item)
{
	this->Item = _Item;
	this->ItemsInSlot = 0;
}

void UFGItemSlot::Store(UFGItem* _Item, uint32 _LoadSize)
{
	this->Item = _Item;
	this->ItemsInSlot += _LoadSize;
}

void UFGItemSlot::Remove(uint32 _LoadSize)
{
	this->ItemsInSlot -= _LoadSize;
}

bool UFGItemSlot::CanStore(UFGItem* _Item, uint32 _LoadSize) const
{
	const bool bItemValid = (this->GetItemSample() != nullptr);
	const bool bItemSame = (this->GetItemSample() == _Item);
	if (bItemValid && !bItemSame) return false;

	const uint32 ItemsAfterStore = this->GetItemsInSlot() + _LoadSize;
	return (ItemsAfterStore <= _Item->StackSize);
}

bool UFGItemSlot::CanRemove(UFGItem* _Item, uint32 _LoadSize) const
{
	const bool BHasEnoughItems = (this->GetItemsInSlot() >= _LoadSize);
	const bool BItemSame = (this->GetItemSample() == _Item);
	return (BItemSame || !_Item) && BHasEnoughItems;
}
