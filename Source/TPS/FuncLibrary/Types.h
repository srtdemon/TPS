// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/DataTable.h"

#include "Types.generated.h"

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Aim_State UMETA(DisplayName = "Aim State"),
	AimWalk_State UMETA(DisplayName = "AimWalk State"),
	Walk_State UMETA(DisplayName = "Walk State"),
	Run_State UMETA(DisplayName = "Run State"),
	SprintRun_State UMETA(DisplayName = "SprintRun State")
};

USTRUCT(BlueprintType)
struct FCharacterSpeed
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	  float AimSpeedNormal = 300;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	  float WalkSpeedNormal = 200;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	  float RunSpeedNormal = 600;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	  float AimSpeedWalk = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	  float SprintRunSpeedRun = 800;

};

USTRUCT(BlueprintType)
struct FProjectileInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSettings")
		TSubclassOf<class AProjectileDefault> Projectile = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSettings")
		float ProjectileDamage = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSettings")
		float ProjectileLifeTime = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSettings")
		float ProjectileInitSpeed = 2000.0f;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSettings")
		bool bIsLikeBomp = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSettings")
		float ProjectileMaxRadiusSpeed = 200.0f;
};

USTRUCT(BlueprintType)
struct FWeaponDispersion
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
		float DispersionAimStart = 0.5f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
		float DispersionAimMax = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
		float DispersionAimMin = 0.1f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
		float DispersionAimShootCoef = 1.0f;
};

USTRUCT(BlueprintType)
struct FWeaponInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class")
		TSubclassOf<class AWeaponDefault> WeaponClass = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
		float RateOfFire = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
		float ReloadTime = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
		int32 MaxRound = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
		FWeaponDispersion DispersionWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
		USoundBase* SoundFireWeapon = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
		USoundBase* SoundReloadWeapon = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
		UParticleSystem* EffectFireWeapon = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
		FProjectileInfo ProjectileInfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
		float WeaponDamage = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
		float DistanceTrace = 2000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitEffect")
		UDecalComponent* DecalOnHit = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
		UAnimMontage* AnimCharFire = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
		UAnimMontage* AnimCharReload = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSettings")
		UStaticMesh* MagazineDrop = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSettings")
		UStaticMesh* SleeveBullets = nullptr;
};

USTRUCT(BlueprintType)
struct FAddicionalWeaponInfo
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Stats")
		int32 Round = 10;
};

UCLASS()
class TPS_API UTypes : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
};