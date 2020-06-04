// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class TESTDEMO_API AMyHUD : public AHUD
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, Category = "Default|MyHUD")
	TSubclassOf<class UMyUserWidget> MyWidget;
public:
	virtual void BeginPlay()override;
	
};
