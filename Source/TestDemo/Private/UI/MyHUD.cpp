// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Public/UI/MyUserWidget.h"

void AMyHUD::BeginPlay()
{
	Super::BeginPlay();
	if (MyWidget)
	{
		UMyUserWidget* user = CreateWidget<UMyUserWidget>(GetWorld(),MyWidget);
		user->AddToViewport();
	}
}
