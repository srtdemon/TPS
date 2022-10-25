// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TPS/FuncLibrary/Types.h"
#include "Engine/DataTable.h"
#include "TPS/WeaponDefault.h"

#include "TPSGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class TPS_API TPSGameInstance : public UGameInstance
{
	GENERATED_BODY()


public:
	//table
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponSetting")
		UDataTable* WeaponInfoRable = nullptr;
	UFUNCTION(BlueprintCallable)
		FWeaponInfo GetWeaponInfoByName(FName NameWeapon);
};
