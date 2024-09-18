// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FactoryGameCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FACTORYGAME_FactoryGameCharacter_generated_h
#error "FactoryGameCharacter.generated.h already included, missing '#pragma once' in FactoryGameCharacter.h"
#endif
#define FACTORYGAME_FactoryGameCharacter_generated_h

#define FID_FactoryGame_Source_FactoryGame_FactoryGameCharacter_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFactoryGameCharacter(); \
	friend struct Z_Construct_UClass_AFactoryGameCharacter_Statics; \
public: \
	DECLARE_CLASS(AFactoryGameCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FactoryGame"), NO_API) \
	DECLARE_SERIALIZER(AFactoryGameCharacter)


#define FID_FactoryGame_Source_FactoryGame_FactoryGameCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AFactoryGameCharacter(AFactoryGameCharacter&&); \
	AFactoryGameCharacter(const AFactoryGameCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFactoryGameCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFactoryGameCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFactoryGameCharacter) \
	NO_API virtual ~AFactoryGameCharacter();


#define FID_FactoryGame_Source_FactoryGame_FactoryGameCharacter_h_19_PROLOG
#define FID_FactoryGame_Source_FactoryGame_FactoryGameCharacter_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_FactoryGame_Source_FactoryGame_FactoryGameCharacter_h_22_INCLASS_NO_PURE_DECLS \
	FID_FactoryGame_Source_FactoryGame_FactoryGameCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FACTORYGAME_API UClass* StaticClass<class AFactoryGameCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_FactoryGame_Source_FactoryGame_FactoryGameCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
