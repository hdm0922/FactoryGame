#include "FGItemStorage.h"

void UFGItemStorage::Store(UFGItem* _Item, uint32 _LoadSize)
{
	checkf(false, TEXT("Cannot Call ABSTRACT Class"));
}

void UFGItemStorage::Remove(uint32 _LoadSize)
{
	checkf(false, TEXT("Cannot Call ABSTRACT Class"));
}

bool UFGItemStorage::CanStore(UFGItem* _Item, uint32 _LoadSize)
{
	checkf(false, TEXT("Cannot Call ABSTRACT Class"));
	return false;
}

bool UFGItemStorage::CanRemove(uint32 _LoadSize)
{
	checkf(false, TEXT("Cannot Call ABSTRACT Class"));
	return false;
}
