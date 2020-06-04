// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MyDataAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TESTDEMO_API UMyDataAsset : public UDataAsset
{
	GENERATED_BODY()
public: 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DataDemo")
		FString QuestSetName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DataDemo")
		TArray<AActor *> QuestArray;
};
