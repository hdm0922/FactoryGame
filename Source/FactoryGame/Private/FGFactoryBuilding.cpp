#include "FGFactoryBuilding.h"
#include "FGItemSlot.h"
#include "FGGlobalItemTable.h"
#include "FGRecipe.h"
#include "FGGlobalRecipeTable.h"
#include "FGUnitConnectorComponent.h"

AFGFactoryBuilding::AFGFactoryBuilding(const uint32 _InputSize)
	: Super()
	, InputConnectors({})
	, InputItemSlots({})

	, OutputConnector(nullptr)
	, OutputItemSlot(nullptr)

	, Recipe(nullptr)
{
	this->InitializeStaticMeshComponent();

	this->CreateInputConnectors(_InputSize);
	this->CreateOutputConnectors(1);
}

void AFGFactoryBuilding::BeginPlay()
{
	Super::BeginPlay();

	{// Some Test Codes Coming In ...
		this->SelectRecipe(1);

		// Recipe 1 : [1] x 1 -> [2] x 1
		// Give InputItemSlot [1] x 5
		this->InputItemSlots[1]->Store(UFGGlobalItemTable::GetItem(1), 5);
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
	const bool bNewState = this->IsAllInputsValid();

	if (this->bInputsValid == bNewState) return;

	this->bInputsValid = bNewState;
	this->UpdateRunningState();

	return;
}

void AFGFactoryBuilding::NotifyOutputChanged()
{
	const bool bNewState = this->IsAllOutputsValid();

	if (this->bOutputsValid == bNewState) return;

	this->bOutputsValid = bNewState;
	this->UpdateRunningState();

	return;

}

void AFGFactoryBuilding::StoreItem(UFGItem* InItem, uint32 InLoadSize)
{
	this->InputItemSlots[InItem->ItemID]->Store(InItem, InLoadSize);

	for (UFGUnitConnectorComponent* InputConnector : this->InputConnectors)
		InputConnector->NotifyOutputChanged();
}

void AFGFactoryBuilding::RemoveItem(UFGItem* InItem, uint32 InLoadSize)
{
	this->OutputItemSlot->Remove(InLoadSize);
	this->OutputConnector->NotifyInputChanged();
}

bool AFGFactoryBuilding::CanStoreItem(UFGItem* InItem, uint32 InLoadSize)
{
	return 
		this->InputItemSlots.Contains(InItem->ItemID) &&
		this->InputItemSlots[InItem->ItemID]->CanStore(InItem, InLoadSize);
}

bool AFGFactoryBuilding::CanRemoveItem(UFGItem* InItem, uint32 InLoadSize)
{
	return this->OutputItemSlot->CanRemove(InItem, InLoadSize);
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
	this->OutputItemSlot->Initialize();

	if (!this->Recipe) return;

	// Set InputItems Context
	for (const auto& RequiredItemData : this->Recipe->InputItems)
	{
		UFGItemSlot* ItemSlot = NewObject<UFGItemSlot>();
		ItemSlot->Initialize(RequiredItemData.Key);
		
		this->InputItemSlots.Add(RequiredItemData.Key->ItemID, ItemSlot);
	}

	// Notify InputConnectors
	for (UFGUnitConnectorComponent* InputConnector : this->InputConnectors)
		InputConnector->NotifyOutputChanged();

	// Set OutputItems Context
	// Must Change Recipe Output Data...
	for (const auto& GeneratedItemData : this->Recipe->OutputItems)
	{
		this->OutputItemSlot->Initialize(GeneratedItemData.Key);
	}

	// Notify OutputConnector
	this->OutputConnector->NotifyInputChanged();
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
	for (UFGUnitConnectorComponent* InputConnector : this->InputConnectors)
		InputConnector->NotifyOutputChanged();

	// Store Output Items
	for (const auto& GeneratedItemData : this->Recipe->OutputItems)
	{
		this->OutputItemSlot->Store(GeneratedItemData.Key, GeneratedItemData.Value);
	}

	// NotifyOutputConnectors
	this->OutputConnector->NotifyInputChanged();

	return;
}

bool AFGFactoryBuilding::CanWork()
{
	return Super::CanWork() && this->Recipe;
}

void AFGFactoryBuilding::CreateInputConnectors(const uint32 _InputSize)
{
	this->InputConnectors.SetNum(_InputSize);

	for (int32 iter = 0; iter < this->InputConnectors.Num(); iter++)
	{
		FString ConnectorName = FString::Printf(TEXT("InputConnector_%d"), iter);
		this->InputConnectors[iter] = this->CreateDefaultSubobject<UFGUnitConnectorComponent>(FName(*ConnectorName));
		this->InputConnectors[iter]->SetOutputUnit(this);
	}

	// Set Connector Transforms
	FVector Origin;
	FVector BoxExtent;
	this->GetActorBounds(true, Origin, BoxExtent);

	const FVector LeftEnd = -FVector(BoxExtent[0], BoxExtent[1], 0.5f * BoxExtent[2]);
	this->PlaceConnectorsArray(LeftEnd, this->InputConnectors);

	return;
}

void AFGFactoryBuilding::CreateOutputConnectors(const uint32 _OutputSize)
{
	this->OutputConnector = this->CreateDefaultSubobject<UFGUnitConnectorComponent>(TEXT("OutputConnector"));
	this->OutputConnector->SetInputUnit(this);

	// Set Connector Transforms
	FVector Origin;
	FVector BoxExtent;
	this->GetActorBounds(true, Origin, BoxExtent);

	const FVector LeftEnd = FVector(BoxExtent[0], -BoxExtent[1], -0.5f * BoxExtent[2]);

	TArray<UFGUnitConnectorComponent*> OutputConnectorsArray = {this->OutputConnector};
	this->PlaceConnectorsArray(LeftEnd, OutputConnectorsArray);

	return;
}

void AFGFactoryBuilding::PlaceConnectorsArray(const FVector& _BeginLocation, TArray<UFGUnitConnectorComponent*>& _ConnectorsArray)
{
	FVector Origin;
	FVector BoxExtent;
	this->GetActorBounds(true, Origin, BoxExtent);

	const float LineLength = 2.0f * BoxExtent[1];
	const uint32 ConnectorsCount = _ConnectorsArray.Num();
	const float ConnectorHalfLength = UFGUnitConnectorComponent::GetUnitConnectorHalfLength();
	const float DistanceBetweenConnectors = (LineLength - 2.0f * ConnectorsCount * ConnectorHalfLength) / (ConnectorsCount + 1);

	FVector ConnectorLocation = _BeginLocation - FVector(0.0f, ConnectorHalfLength, 0.0f);
	for (int32 iter = 0; iter < _ConnectorsArray.Num(); iter++)
	{
		ConnectorLocation[1] += (DistanceBetweenConnectors + 2.0f * ConnectorHalfLength);
		_ConnectorsArray[iter]->SetStaticMeshComponentProperty(ConnectorLocation);
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
		const bool bEnoughSpaceInSlot = this->OutputItemSlot->
			CanStore(GeneratedItemData.Key, GeneratedItemData.Value);
		if (!bEnoughSpaceInSlot) return false;
	}

	return true;
}