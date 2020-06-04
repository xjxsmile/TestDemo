// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "MyDeveloperSettings.generated.h"

/**
 * 
 */
UCLASS(Config= mSetting,defaultconfig)
class TESTDEMO_API UMyDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, DisplayName = "DataDrivenProjectSettings")
		static UMyDeveloperSettings* Get() { return GetMutableDefault<UMyDeveloperSettings>(); }
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = Shop)
		float PriceOff = 50.f;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = Player)
		float PlayerStartLevel = 10.f;

};
