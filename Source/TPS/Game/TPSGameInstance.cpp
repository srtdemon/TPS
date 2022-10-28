// Fill out your copyright notice in the Description page of Project Settings.


#include "TPS/Game/TPSGameInstance.h"

bool UTPSGameInstance::GetWeaponInfoByName(FName NameWeapon, FWeaponInfo& OutInfo)
{
	bool bIsFind = false;
	FWeaponInfo* WeaponInfoRow;

	WeaponInfoRow = WeaponInfoTable->FindRow<FWeaponInfo>(NameWeapon, "", false);
		if (WeaponInfoRow) 
		{
			bIsFind = true;
			OutInfo = *WeaponInfoRow;
		}
	return bIsFind;
}

  