// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomeConfigActor.h"
#include "HAL/IConsoleManager.h"


//static TAutoConsoleVariable<bool> TestBool(TEXT("TT.Testbool"), false, TEXT("Test Bool Enable Or Not"), ECVF_Default);


static TAutoConsoleVariable<int32> TestInt(TEXT("TT.Testint"), 3, TEXT("Test int32 Enable Or Not"), ECVF_Default);

static TAutoConsoleVariable<FString> TestFString(TEXT("TT.TestFString"), TEXT("Jack"), TEXT("Test FString Enable Or Not"), ECVF_Default);

// Sets default values
ACustomeConfigActor::ACustomeConfigActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
// Called when the game starts or when spawned
void ACustomeConfigActor::BeginPlay()
{
//aaaaaa   bbbbb
/*
	chuan
*/
	Super::BeginPlay();
	LoadConfig();
}

void ACustomeConfigActor::AddValueFloat(float _va)
{
	valuefloat+=_va;
	SaveConfig();
}


/*
	gggg
*/
// Called every frame
void ACustomeConfigActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*FString str=FString::Printf(TEXT("TT.Testbool:%s"), TestBool.GetValueOnGameThread()?TEXT("true"):TEXT("false"));*/
	FString str=FString::Printf(TEXT("TT.Testint"), TestInt.GetValueOnGameThread());
	str+=FString::Printf(TEXT("TT.TestFString"), *TestFString.GetValueOnGameThread());
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, str);
}




