// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "Public/Obj/DataSingleTon.h"

void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();
	UDataSingleTon* data = Cast<UDataSingleTon>(GEngine->GameSingleton); 

	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Orange, data->SourceVector.ToString(), true);
}
