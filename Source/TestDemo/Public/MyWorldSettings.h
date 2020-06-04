// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "MyWorldSettings.generated.h"

/**
 * 
 */
UCLASS()
class TESTDEMO_API AMyWorldSettings : public AWorldSettings
{
	GENERATED_BODY()
	public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DefaultSettting")
	float SettintValue=100.f ;
};
