#include "FGFactoryBuilding.h"
#include "FGItemSlot.h"
#include "FGRecipe.h"
#include "FGGlobalRecipeTable.h"
#include "FGUnitConnector.h"

AFGFactoryBuilding::AFGFactoryBuilding(const uint32 _InputSize, const uint32 _OutputSize)
	: Super(_InputSize, _OutputSize)
	, InputConnectors({})
	, InputItemSlots({})

	, OutputConnectors({})
	, OutputItemSlots({})

	, Recipe(nullptr)
{

	this->InputConnectors.SetNum(_InputSize);
	this->OutputConnectors.SetNum(_OutputSize);

	this->InitializeStaticMeshComponent();
}

void AFGFactoryBuilding::BeginPlay()
{
	Super::BeginPlay();

	this->CreateInputConnectors();
	this->CreateOutputConnectors();

	{// Some Test Codes Coming In ...
		this->SelectRecipe(1);

		// Recipe 1 : [1] x 1 -> [2] x 1
		// Give InputItemSlot [1] x 5
		this->InputItemSlots[1] += 5;
		this->NotifyInputChanged();

		this->UpdateRunningState();
		UE_LOG(LogTemp, Warning, TEXT("START.."));

		UE_LOG(LogTemp, Warning, TEXT("Building Can Run : %d"), this->CanWork());
		UE_LOG(LogTemp, Warning, TEXT("Building Input Valid : %d"), this->bInputsValid);
		UE_LOG(LogTemp, Warning, TEXT("Building Output Valid : %d"), this->bOutputsValid);
		UE_LOG(LogTemp, Warning, TEXT("Building Recipe Valid : %d"), (this->Recipe != nullptr));
	}

	return;
}

void AFGFactoryBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFGFactoryBuilding::Work(float DeltaTime)
{
	Super::Work(DeltaTime);

	const bool bWorkTimeOver = (this->WorkTime > this->Recipe->WorkTime);
	if (bWorkTimeOver)
	{
		this->WorkTime = 0.0f;
		this->ProduceOutput();
		UE_LOG(LogTemp, Warning, TEXT("Work Done"));
	}

	return;
}

void AFGFactoryBuilding::NotifyInputChanged()
{
	UE_LOG(LogTemp, Warning, TEXT("Notify Input Changed Called, FactoryBuilding"));
	const bool bNewState = this->IsAllInputsValid();

	if (this->bInputsValid == bNewState) return;

	this->bInputsValid = bNewState;
	this->UpdateRunningState();

	return;
}

void AFGFactoryBuilding::NotifyOutputChanged()
{
	UE_LOG(LogTemp, Warning, TEXT("Notify Output Changed Called, FactoryBuilding"));
	const bool bNewState = this->IsAllOutputsValid();

	if (this->bOutputsValid == bNewState) return;

	this->bOutputsValid = bNewState;
	this->UpdateRunningState();

	return;

}

void AFGFactoryBuilding::InitializeStaticMeshComponent()
{
	Super::InitializeStaticMeshComponent();

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	this->StaticMeshComponent->SetStaticMesh(CubeMesh.Object);

	return;
}

void AFGFactoryBuilding::SelectRecipe(uint32 _RecipeID)
{
	this->SelectRecipe(UFGGlobalRecipeTable::GetRecipe(_RecipeID));
}

void AFGFactoryBuilding::SelectRecipe(UFGRecipe* _Recipe)
{

	// Set Recipe
	this->Recipe = _Recipe;

	// Clear InputItems (Give Player Left Items)
	this->InputItemSlots.Empty(0);

	// Clear OutputItems (Give Player Left Items)
	this->OutputItemSlots.Empty(0);

	if (!this->Recipe) return;

	// Set InputItems Context
	for (const auto& RequiredItemData : this->Recipe->InputItems)
	{
		UFGItemSlot* ItemSlot = NewObject<UFGItemSlot>();
		ItemSlot->Initialize(RequiredItemData.Key);
		
		this->InputItemSlots.Add(RequiredItemData.Key->ItemID, ItemSlot);
	}

	// Notify InputConnectors
	for (AFGUnitConnector* InputConnector : this->InputConnectors)
		InputConnector->NotifyOutputChanged();

	// Set OutputItems Context
	for (const auto& GeneratedItemData : this->Recipe->OutputItems)
	{
		UFGItemSlot* ItemSlot = NewObject<UFGItemSlot>();
		ItemSlot->Initialize(GeneratedItemData.Key);

		this->OutputItemSlots.Add(GeneratedItemData.Key->ItemID, ItemSlot);
	}

	// Notify OutputConnectors
	for (AFGUnitConnector* OutputConnector : this->OutputConnectors)
		OutputConnector->NotifyInputChanged();
}

void AFGFactoryBuilding::ProduceOutput()
{
	// Remove Input Items
	for (const auto& RequiredItemData : this->Recipe->InputItems)
	{
		UFGItemSlot* ItemSlot = *this->InputItemSlots.Find(RequiredItemData.Key->ItemID);
		ItemSlot->Remove(RequiredItemData.Value);
	}
		
	// Notify InputConnectors
	for (AFGUnitConnector* InputConnector : this->InputConnectors)
		InputConnector->NotifyOutputChanged();

	// Store Output Items
	for (const auto& GeneratedItemData : this->Recipe->OutputItems)
	{
		UFGItemSlot* ItemSlot = *this->OutputItemSlots.Find(GeneratedItemData.Key->ItemID);
		ItemSlot->Remove(GeneratedItemData.Value);
	}

	// NotifyOutputConnectors
	for (AFGUnitConnector* OutputConnector : this->OutputConnectors)
		OutputConnector->NotifyInputChanged();

	return;
}

bool AFGFactoryBuilding::CanWork()
{
	return Super::CanWork() && this->Recipe;
}

AFGUnitConnector* AFGFactoryBuilding::CreateConnector(const FVector& _Location)
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Owner = this;

	AFGUnitConnector* ConnectorCreated = this->GetWorld()->SpawnActor<AFGUnitConnector>(
		_Location, FRotator::ZeroRotator, SpawnParams
	);

	ConnectorCreated->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

	return ConnectorCreated;
}

void AFGFactoryBuilding::CreateInputConnectors()
{
	for (int32 iter = 0; iter < this->InputConnectors.Num(); iter++)
	{
		// Temporary Location
		FVector ConnectorLocation = FVector(-50.0f, -50.0f + (10.0f * iter), 0.0f);

		this->InputConnectors[iter] = this->CreateConnector(ConnectorLocation);
		this->InputConnectors[iter]->SetOutputUnit(this);
	}

	return;
}

void AFGFactoryBuilding::CreateOutputConnectors()
{
	for (int32 iter = 0; iter < this->OutputConnectors.Num(); iter++)
	{
		// Temporary Location
		FVector ConnectorLocation = FVector(50.0f, -50.0f + (10.0f * iter), 0.0f);

		this->OutputConnectors[iter] = this->CreateConnector(ConnectorLocation);
		this->OutputConnectors[iter]->SetInputUnit(this);
	}

	return;
}

bool AFGFactoryBuilding::IsAllInputsValid() const
{
	if (!this->Recipe) return false;

	for (const auto& RequiredItemData : this->Recipe->InputItems)
	{
		UFGItemSlot* ItemSlot = this->InputItemSlots[RequiredItemData.Key->ItemID];
		const bool bEnoughItemsInSlot = ItemSlot->CanRemove(RequiredItemData.Key, RequiredItemData.Value);
		if (!bEnoughItemsInSlot) return false;
	}

	return true;
}

bool AFGFactoryBuilding::IsAllOutputsValid() const
{
	if (!this->Recipe) return false;

	for (const auto& GeneratedItemData : this->Recipe->OutputItems)
	{
		UFGItemSlot* ItemSlot = this->OutputItemSlots[GeneratedItemData.Key->ItemID];
		const bool bEnoughSpaceInSlot = ItemSlot->CanStore(GeneratedItemData.Key, GeneratedItemData.Value);
		if (!bEnoughSpaceInSlot) return false;
	}

	return true;
}