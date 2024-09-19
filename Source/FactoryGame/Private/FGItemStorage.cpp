#include "FGItemStorage.h"

void UFGItemStorage::Initialize(UFGItem* _Item)
{
	checkf(false, TEXT("ABSTRACT"));
}

void UFGItemStorage::Store(UFGItem* _Item, uint32 _LoadSize)
{
	checkf(false, TEXT("ABSTRACT"));
}

void UFGItemStorage::Remove(uint32 _LoadSize)
{
	checkf(false, TEXT("ABSTRACT"));
}

bool UFGItemStorage::CanStore(UFGItem* _Item, uint32 _LoadSize) const
{
	checkf(false, TEXT("ABSTRACT"));
	return false;
}

bool UFGItemStorage::CanRemove(UFGItem* _Item, uint32 _LoadSize) const
{
	checkf(false, TEXT("ABSTRACT"));
	return false;
}
