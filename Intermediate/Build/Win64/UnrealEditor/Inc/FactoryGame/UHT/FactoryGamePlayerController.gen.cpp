// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FactoryGame/FactoryGamePlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFactoryGamePlayerController() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
FACTORYGAME_API UClass* Z_Construct_UClass_AFactoryGamePlayerController();
FACTORYGAME_API UClass* Z_Construct_UClass_AFactoryGamePlayerController_NoRegister();
UPackage* Z_Construct_UPackage__Script_FactoryGame();
// End Cross Module References

// Begin Class AFactoryGamePlayerController
void AFactoryGamePlayerController::StaticRegisterNativesAFactoryGamePlayerController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFactoryGamePlayerController);
UClass* Z_Construct_UClass_AFactoryGamePlayerController_NoRegister()
{
	return AFactoryGamePlayerController::StaticClass();
}
struct Z_Construct_UClass_AFactoryGamePlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "FactoryGamePlayerController.h" },
		{ "ModuleRelativePath", "FactoryGamePlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputMappingContext_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Input Mapping Context to be used for player input */" },
#endif
		{ "ModuleRelativePath", "FactoryGamePlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Input Mapping Context to be used for player input" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMappingContext;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFactoryGamePlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFactoryGamePlayerController_Statics::NewProp_InputMappingContext = { "InputMappingContext", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFactoryGamePlayerController, InputMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputMappingContext_MetaData), NewProp_InputMappingContext_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFactoryGamePlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFactoryGamePlayerController_Statics::NewProp_InputMappingContext,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFactoryGamePlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AFactoryGamePlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_FactoryGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFactoryGamePlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFactoryGamePlayerController_Statics::ClassParams = {
	&AFactoryGamePlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AFactoryGamePlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AFactoryGamePlayerController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFactoryGamePlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AFactoryGamePlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFactoryGamePlayerController()
{
	if (!Z_Registration_Info_UClass_AFactoryGamePlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFactoryGamePlayerController.OuterSingleton, Z_Construct_UClass_AFactoryGamePlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFactoryGamePlayerController.OuterSingleton;
}
template<> FACTORYGAME_API UClass* StaticClass<AFactoryGamePlayerController>()
{
	return AFactoryGamePlayerController::StaticClass();
}
AFactoryGamePlayerController::AFactoryGamePlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFactoryGamePlayerController);
AFactoryGamePlayerController::~AFactoryGamePlayerController() {}
// End Class AFactoryGamePlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_FactoryGame_Source_FactoryGame_FactoryGamePlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFactoryGamePlayerController, AFactoryGamePlayerController::StaticClass, TEXT("AFactoryGamePlayerController"), &Z_Registration_Info_UClass_AFactoryGamePlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFactoryGamePlayerController), 3014066035U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FactoryGame_Source_FactoryGame_FactoryGamePlayerController_h_2336433735(TEXT("/Script/FactoryGame"),
	Z_CompiledInDeferFile_FID_FactoryGame_Source_FactoryGame_FactoryGamePlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FactoryGame_Source_FactoryGame_FactoryGamePlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
