#include "FGFactoryGameInstance.h"
#include "FGGlobalItemTable.h"
#include "FGGlobalRecipeTable.h"

UFGFactoryGameInstance::UFGFactoryGameInstance()
	: Super()
{
	this->LoadDataAssets();
}

void UFGFactoryGameInstance::Init()
{
	Super::Init();

	return;
}

void UFGFactoryGameInstance::LoadDataAssets()
{
	// Load Global Item Table
	static ConstructorHelpers::FObjectFinder<UFGGlobalItemTable> GlobalItemTableFinder(TEXT("/Game/DataAssets/Item/GlobalItemTable"));
	UFGGlobalItemTable::GlobalItemTable = GlobalItemTableFinder.Object->ItemTable;

	// Load Global Recipe Table
	static ConstructorHelpers::FObjectFinder<UFGGlobalRecipeTable> GlobalRecipeTableFinder(TEXT("/Game/DataAssets/Recipe/GlobalRecipeTable"));
	UFGGlobalRecipeTable::GlobalRecipeTable = GlobalRecipeTableFinder.Object->RecipeData;

	return;
}
