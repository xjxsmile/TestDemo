// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DataSingleTon.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class TESTDEMO_API UDataSingleTon : public UObject
{
	GENERATED_BODY()
public:
	UDataSingleTon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataSingleTon")
		TArray<UClass*> SourceBlueprint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataSingleTon")
		class UTexture2D * SourceText2D;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataSingleTon")
		FVector SourceVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataSingleTon")
		FString SourceFilePath;



};
