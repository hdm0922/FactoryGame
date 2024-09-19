#include "FGItemStorage.h"

void UFGItemStorage::Store(UFGItem* _Item, uint32 _LoadSize)
{
	checkf(false, TEXT("ABSTRACT"));
}

void UFGItemStorage::Remove(uint32 _LoadSize)
{
	checkf(false, TEXT("ABSTRACT"));
}

bool UFGItemStorage::CanStore(UFGItem* _Item, uint32 _LoadSize)
{
	checkf(false, TEXT("ABSTRACT"));
	return false;
}

bool UFGItemStorage::CanRemove(uint32 _LoadSize)
{
	checkf(false, TEXT("ABSTRACT"));
	return false;
}
