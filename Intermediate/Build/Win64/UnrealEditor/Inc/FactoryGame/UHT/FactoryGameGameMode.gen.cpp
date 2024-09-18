// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FactoryGame/FactoryGameGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFactoryGameGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
FACTORYGAME_API UClass* Z_Construct_UClass_AFactoryGameGameMode();
FACTORYGAME_API UClass* Z_Construct_UClass_AFactoryGameGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_FactoryGame();
// End Cross Module References

// Begin Class AFactoryGameGameMode
void AFactoryGameGameMode::StaticRegisterNativesAFactoryGameGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFactoryGameGameMode);
UClass* Z_Construct_UClass_AFactoryGameGameMode_NoRegister()
{
	return AFactoryGameGameMode::StaticClass();
}
struct Z_Construct_UClass_AFactoryGameGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "FactoryGameGameMode.h" },
		{ "ModuleRelativePath", "FactoryGameGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFactoryGameGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AFactoryGameGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_FactoryGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFactoryGameGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFactoryGameGameMode_Statics::ClassParams = {
	&AFactoryGameGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFactoryGameGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AFactoryGameGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFactoryGameGameMode()
{
	if (!Z_Registration_Info_UClass_AFactoryGameGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFactoryGameGameMode.OuterSingleton, Z_Construct_UClass_AFactoryGameGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFactoryGameGameMode.OuterSingleton;
}
template<> FACTORYGAME_API UClass* StaticClass<AFactoryGameGameMode>()
{
	return AFactoryGameGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFactoryGameGameMode);
AFactoryGameGameMode::~AFactoryGameGameMode() {}
// End Class AFactoryGameGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_FactoryGame_Source_FactoryGame_FactoryGameGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFactoryGameGameMode, AFactoryGameGameMode::StaticClass, TEXT("AFactoryGameGameMode"), &Z_Registration_Info_UClass_AFactoryGameGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFactoryGameGameMode), 2027932903U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FactoryGame_Source_FactoryGame_FactoryGameGameMode_h_3298075508(TEXT("/Script/FactoryGame"),
	Z_CompiledInDeferFile_FID_FactoryGame_Source_FactoryGame_FactoryGameGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FactoryGame_Source_FactoryGame_FactoryGameGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
