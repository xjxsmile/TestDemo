// Fill out your copyright notice in the Description page of Project Settings.


#include "Reflect/SrcActor.h"
#include "MyWorldSettings.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameModeBase.h"

void ASrcActor::UFunOne()
{
	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Red, L"ASrcActor-->UFunOne");
}

void ASrcActor::UFunTwo(FString InfoStr, int32& Count)
{
	FString str = InfoStr + FString("--->") + FString::FromInt(Count);
	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Red, str);
	Count = 888;
}

bool ASrcActor::UFuncThree(FString InfoStr, int32 Count)
{
	FString str = InfoStr + FString("--->") + FString::FromInt(Count);
	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Red, str);
	return true;
}

int32 ASrcActor::UFuncFour(FString InfoStr, int32& Count)
{
	FString str = InfoStr + FString("--->") + FString::FromInt(Count);
	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Red, str);
	Count = 888;
	return 789;
}

void ASrcActor::UFunFour(FString InfoStr)
{
	FString str = InfoStr + FString("--->");
	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Red, str);
}

// Sets default values
ASrcActor::ASrcActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ActorName = FString("ASrcActor");
	IsActive = true;
}

// Called when the game starts or when spawned
void ASrcActor::BeginPlay()
{
	Super::BeginPlay();

	AWorldSettings * setting=UGameplayStatics::GetGameMode(this)->GetWorld()->GetWorldSettings();

	AMyWorldSettings * mSet=Cast<AMyWorldSettings>(setting);

	GEngine->AddOnScreenDebugMessage(-1,100,FColor::Orange,FString::SanitizeFloat(mSet->SettintValue));
}

// Called every frame
void ASrcActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

