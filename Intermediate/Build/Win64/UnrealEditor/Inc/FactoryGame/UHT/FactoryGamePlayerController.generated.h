// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FactoryGamePlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FACTORYGAME_FactoryGamePlayerController_generated_h
#error "FactoryGamePlayerController.generated.h already included, missing '#pragma once' in FactoryGamePlayerController.h"
#endif
#define FACTORYGAME_FactoryGamePlayerController_generated_h

#define FID_FactoryGame_Source_FactoryGame_FactoryGamePlayerController_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFactoryGamePlayerController(); \
	friend struct Z_Construct_UClass_AFactoryGamePlayerController_Statics; \
public: \
	DECLARE_CLASS(AFactoryGamePlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FactoryGame"), NO_API) \
	DECLARE_SERIALIZER(AFactoryGamePlayerController)


#define FID_FactoryGame_Source_FactoryGame_FactoryGamePlayerController_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFactoryGamePlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AFactoryGamePlayerController(AFactoryGamePlayerController&&); \
	AFactoryGamePlayerController(const AFactoryGamePlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFactoryGamePlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFactoryGamePlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFactoryGamePlayerController) \
	NO_API virtual ~AFactoryGamePlayerController();


#define FID_FactoryGame_Source_FactoryGame_FactoryGamePlayerController_h_14_PROLOG
#define FID_FactoryGame_Source_FactoryGame_FactoryGamePlayerController_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_FactoryGame_Source_FactoryGame_FactoryGamePlayerController_h_17_INCLASS_NO_PURE_DECLS \
	FID_FactoryGame_Source_FactoryGame_FactoryGamePlayerController_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FACTORYGAME_API UClass* StaticClass<class AFactoryGamePlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_FactoryGame_Source_FactoryGame_FactoryGamePlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
