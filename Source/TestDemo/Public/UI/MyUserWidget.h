// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTDEMO_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
    UMyUserWidget(const FObjectInitializer & ObjectInitializer);

    virtual bool Initialize()override;

    UFUNCTION(BlueprintCallable, Category = "UserWidget")
        void FuncTionThreeEvent();

	UFUNCTION()
		void FuncTionTwoEvent();

	UFUNCTION()
		void FuncTionOneEvent();


private:
	UPROPERTY(meta = (BindWidget))
		class UButton* ButtonOne;

	class UImage* BGImage;
	class UCanvasPanel* RootPanel;
	class UImage* DyImage;


};
