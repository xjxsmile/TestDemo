// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/UI/MyUserWidget.h"
#include "Image.h"
#include "CanvasPanel.h"
#include "Button.h"
#include "Engine/Texture2D.h"
#include "CanvasPanelSlot.h"
#include "WidgetTree.h"


UMyUserWidget::UMyUserWidget(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{

}

bool UMyUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	RootPanel = Cast<UCanvasPanel>(GetRootWidget());
	if (RootPanel)
	{
		BGImage = Cast<UImage>(RootPanel->GetChildAt(0));
	}

	UButton* ButtonTwo = (UButton*)GetWidgetFromName(L"ButtonTwo");

	ButtonOne->OnClicked.__Internal_AddDynamic(this, &UMyUserWidget::FuncTionOneEvent, FName("FuncTionOneEvent"));

	FScriptDelegate ButTwoDel;
	ButTwoDel.BindUFunction(this, "FuncTionTwoEvent");
	ButtonTwo->OnReleased.Add(ButTwoDel);

	return true;
}


void UMyUserWidget::FuncTionThreeEvent()
{
	if (!DyImage)
	{
		return;
	}
	RootPanel->RemoveChild(DyImage);

	//DyImage->RemoveFromParent();

	DyImage->ConditionalBeginDestroy();
	DyImage = NULL;

}

void UMyUserWidget::FuncTionTwoEvent()
{
	if (DyImage)
	{
		return;
	}

	DyImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());

	UCanvasPanelSlot* DyCanvasslot = RootPanel->AddChildToCanvas(DyImage);

	DyCanvasslot->SetAnchors(0.f);
	DyCanvasslot->SetOffsets(FMargin(244.f, 268.f, 300.f, 200.f));

	UTexture2D* tartex = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/StarterContent/Textures/T_Fire_SubUV.T_Fire_SubUV'"));

	DyImage->SetBrushFromTexture(tartex);
}

void UMyUserWidget::FuncTionOneEvent()
{
	UTexture2D* TarTex = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/StarterContent/Textures/T_TableRound_M.T_TableRound_M'"));
	BGImage->SetBrushFromTexture(TarTex);
}
