// Fill out your copyright notice in the Description page of Project Settings.


#include "FWReceActor.h"
#include "FWDEActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFWReceActor::AFWReceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFWReceActor::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> ActArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFWDEActor::StaticClass(), ActArray);

	if (ActArray.Num() > 0)
	{
		AFWDEActor* fwAc = Cast<AFWDEActor>(ActArray[0]);

		//fwAc->RegOne([this](FString str) {EchoInfoOne(str); });

		//fwAc->RegTwo(this, &AFWReceActor::EchoInfoTwo);

		//fwAc->RegThree(this, &AFWReceActor::EchoInfoTwo);

		///DECLARE_DELEGATE_TwoParams(TempDel, FString, int32);
		//fwAc->RegFour<TempDel>(this, &AFWReceActor::EchoInfoTwo, FString("CCCCCCCCCCCC"),300);

		//fwAc->RegFive<bool, FString, float>([this](FString InfoStr, int32 count) {return EchoInfoThree(InfoStr, count); });
	}

	
}

// Called every frame
void AFWReceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFWReceActor::EchoInfoOne(FString InfoStr)
{
	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Green, InfoStr);
}

void AFWReceActor::EchoInfoTwo(FString InfoStr, int32 count)
{
	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Green, InfoStr);
	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Green, FString::FromInt(count));
}

bool AFWReceActor::EchoInfoThree(FString InfoStr, int32 count)
{
	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Green, L"pppppppppppppppppppppp");

	return true;
}

