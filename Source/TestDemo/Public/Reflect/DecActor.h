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
	//反射实例化对象
	void ReflectInstance();
	//反射操作UProperty
	void ControlUProperty();

	//调用UFunction方法一：FScriptDelegate
	void RunFunOne();

	//调用UFunction方法二：TBaseDelegate
	void RunFunTwo();

	//调用UFunction方法三：UFuntion
	void RunFunThree();

	void RunFunFour();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
private:
	class ASrcActor* srcActor;
	UObject* scrObj;
};
