// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FWReceActor.generated.h"


UCLASS()
class TESTDEMO_API AFWReceActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFWReceActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void EchoInfoOne(FString InfoStr);

	void EchoInfoTwo(FString InfoStr,int32 count);

	bool EchoInfoThree(FString InfoStr, int32 count);
};
