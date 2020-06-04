// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "SrcActor.generated.h"

USTRUCT(BlueprintType)
struct FMStruct : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
		FString sName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		class UTexture2D * mesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		int32 price;

};

UCLASS()
class TESTDEMO_API ASrcActor : public AActor
{
	GENERATED_BODY()
public:
	UFUNCTION()
		void UFunOne();
	UFUNCTION()
		void UFunTwo(FString InfoStr, int32& Count);
	UFUNCTION()
		bool UFuncThree(FString InfoStr, int32 Count);
	UFUNCTION()
		int32 UFuncFour(FString InfoStr, int32& Count);
	UFUNCTION()
		void UFunFour(FString InfoStr);
public:
	UPROPERTY(EditAnywhere)
		FString ActorName;

	UPROPERTY(EditAnywhere)
		bool IsActive;
	



public:	
	// Sets default values for this actor's properties
	ASrcActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
