// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DecActor.generated.h"

UCLASS()
class TESTDEMO_API ADecActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADecActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//����ʵ��������
	void ReflectInstance();
	//�������UProperty
	void ControlUProperty();

	//����UFunction����һ��FScriptDelegate
	void RunFunOne();

	//����UFunction��������TBaseDelegate
	void RunFunTwo();

	//����UFunction��������UFuntion
	void RunFunThree();

	void RunFunFour();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
private:
	class ASrcActor* srcActor;
	UObject* scrObj;
};
