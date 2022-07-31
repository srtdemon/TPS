// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
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

UCLASS()
class TPS_API UTypes : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
};