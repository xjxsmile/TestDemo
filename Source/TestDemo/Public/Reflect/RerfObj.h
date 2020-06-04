// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "RerfObj.generated.h"


/**
 * 
 */
UENUM()
enum class ERefState : uint8 {
	None,
	Active,
	Disable
};

USTRUCT(BlueprintType)   
//struct FMyStruct £ºpublic FTableRowBase
struct FDataTableTestData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataTable Test")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataTable Test")
	int32 Count;
};


UCLASS()
class TESTDEMO_API URerfObj : public UObject
{
	GENERATED_BODY()
public:
	void EchoInfo();
};
