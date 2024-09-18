// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FactoryGameProjectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef FACTORYGAME_FactoryGameProjectile_generated_h
#error "FactoryGameProjectile.generated.h already included, missing '#pragma once' in FactoryGameProjectile.h"
#endif
#define FACTORYGAME_FactoryGameProjectile_generated_h

#define FID_FactoryGame_Source_FactoryGame_FactoryGameProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnHit);


#define FID_FactoryGame_Source_FactoryGame_FactoryGameProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFactoryGameProjectile(); \
	friend struct Z_Construct_UClass_AFactoryGameProjectile_Statics; \
public: \
	DECLARE_CLASS(AFactoryGameProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FactoryGame"), NO_API) \
	DECLARE_SERIALIZER(AFactoryGameProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_FactoryGame_Source_FactoryGame_FactoryGameProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AFactoryGameProjectile(AFactoryGameProjectile&&); \
	AFactoryGameProjectile(const AFactoryGameProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFactoryGameProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFactoryGameProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFactoryGameProjectile) \
	NO_API virtual ~AFactoryGameProjectile();


#define FID_FactoryGame_Source_FactoryGame_FactoryGameProjectile_h_12_PROLOG
#define FID_FactoryGame_Source_FactoryGame_FactoryGameProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_FactoryGame_Source_FactoryGame_FactoryGameProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_FactoryGame_Source_FactoryGame_FactoryGameProjectile_h_15_INCLASS_NO_PURE_DECLS \
	FID_FactoryGame_Source_FactoryGame_FactoryGameProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FACTORYGAME_API UClass* StaticClass<class AFactoryGameProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_FactoryGame_Source_FactoryGame_FactoryGameProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
