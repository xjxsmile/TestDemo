// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomeConfigActor.generated.h"

UCLASS(config=CustomeConfigActor)
class TESTDEMO_API ACustomeConfigActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACustomeConfigActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void AddValueFloat(float _va);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(config,BlueprintReadWrite)
		int32 value=1;

	UPROPERTY(config, BlueprintReadWrite)
		float valuefloat = 1.f;






};
