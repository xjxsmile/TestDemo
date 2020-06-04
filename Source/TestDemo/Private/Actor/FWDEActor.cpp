// Fill out your copyright notice in the Description page of Project Settings.


#include "FWDEActor.h"

// Sets default values
AFWDEActor::AFWDEActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFWDEActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFWDEActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFWDEActor::RegFunDel(FWDE_Dy_sl_Zero TargetFun) {
	TargetFun.ExecuteIfBound();
}

void AFWDEActor::RegOne(TFunction<void(FString)> TargetFun)
{
	TFunOne = TargetFun;
	TFunOne(FString("RegOne"));
} 




//
//void AFWDEActor::RegFunDel1(FWDE_Single_Zero TargetFun)
//{
//
//}
