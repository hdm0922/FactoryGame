// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FactoryGameGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FACTORYGAME_FactoryGameGameMode_generated_h
#error "FactoryGameGameMode.generated.h already included, missing '#pragma once' in FactoryGameGameMode.h"
#endif
#define FACTORYGAME_FactoryGameGameMode_generated_h

#define FID_FactoryGame_Source_FactoryGame_FactoryGameGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFactoryGameGameMode(); \
	friend struct Z_Construct_UClass_AFactoryGameGameMode_Statics; \
public: \
	DECLARE_CLASS(AFactoryGameGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/FactoryGame"), FACTORYGAME_API) \
	DECLARE_SERIALIZER(AFactoryGameGameMode)


#define FID_FactoryGame_Source_FactoryGame_FactoryGameGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AFactoryGameGameMode(AFactoryGameGameMode&&); \
	AFactoryGameGameMode(const AFactoryGameGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(FACTORYGAME_API, AFactoryGameGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFactoryGameGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFactoryGameGameMode) \
	FACTORYGAME_API virtual ~AFactoryGameGameMode();


#define FID_FactoryGame_Source_FactoryGame_FactoryGameGameMode_h_9_PROLOG
#define FID_FactoryGame_Source_FactoryGame_FactoryGameGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_FactoryGame_Source_FactoryGame_FactoryGameGameMode_h_12_INCLASS_NO_PURE_DECLS \
	FID_FactoryGame_Source_FactoryGame_FactoryGameGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FACTORYGAME_API UClass* StaticClass<class AFactoryGameGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_FactoryGame_Source_FactoryGame_FactoryGameGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
