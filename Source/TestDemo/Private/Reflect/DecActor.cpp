// Fill out your copyright notice in the Description page of Project Settings.


#include "Reflect/DecActor.h"
#include "Reflect/RerfObj.h"
#include "Kismet/GameplayStatics.h"
#include "Reflect/SrcActor.h"
#include "UnrealType.h"

// Sets default values
ADecActor::ADecActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADecActor::BeginPlay()
{
	Super::BeginPlay();
	//Instance();


	TArray<AActor*> ActArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASrcActor::StaticClass(), ActArray);

	if (ActArray.Num() > 0)
	{
		srcActor = Cast<ASrcActor>(ActArray[0]);
		scrObj = (UObject*)srcActor;
		
		//RunFunOne();

		//RunFunTwo();

		//RunFunThree();
		//RunFunFour();

		ControlUProperty();

	}
}

void ADecActor::ReflectInstance()
{
	UClass* ref = StaticLoadClass(UObject::StaticClass(), nullptr, TEXT("URerfObj"));

	URerfObj* refObj = Cast<URerfObj>(ref);
	refObj->EchoInfo();

	UObject* refptr = StaticLoadObject(UObject::StaticClass(), nullptr, TEXT("URerfObj"));
	URerfObj* refins = Cast<URerfObj>(ref);
	refins->EchoInfo();

	UEnum* ENumPtr = FindObject<UEnum>((UObject*)ANY_PACKAGE, *FString("ERefState"), true);
	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Green, ENumPtr->GetEnumName((int32)1));

	if (refObj == refins)
	{
		GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Green, L"refObj== refins");
	}
}

void ADecActor::ControlUProperty()
{
	for (TFieldIterator<UProperty> ProIt(scrObj->GetClass()); ProIt; ++ProIt)
	{
		UProperty* Property = *ProIt;

		if (Property->GetNameCPP().Equals("ActorName"))
		{
			UStrProperty* StrPtr = Cast<UStrProperty>(Property);
			if (StrPtr)
			{
				void* ValPtr = Property->ContainerPtrToValuePtr<uint8>(scrObj);
				FString str = FString("ActorName Be") +StrPtr->GetPropertyValue(ValPtr);
				GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Green, str);
				StrPtr->SetPropertyValue(ValPtr, FString("New Name"));
			}

			GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Green, srcActor->ActorName);

		}

		if (Property->GetNameCPP().Equals("IsActive"))
		{
			UBoolProperty* BoolPro = Cast<UBoolProperty>(Property);

			if (BoolPro)
			{
				void* ValPtr = Property->ContainerPtrToValuePtr<uint8>(scrObj);
				FString str = FString("ActorName Be") + FString::FromInt(BoolPro->GetPropertyValue(ValPtr));
				GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Green, str);

				BoolPro->SetPropertyValue(ValPtr, false);
			}
			GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Green, FString::FromInt(srcActor->IsActive));

		}

	}
}

void ADecActor::RunFunOne()
{
	FScriptDelegate FunDelOne;
	FunDelOne.BindUFunction(scrObj, "UFunOne");
	//FunDelOne.ProcessDelegate<UObject>(NULL);

	FScriptDelegate FunDelTwo;
	FunDelTwo.BindUFunction(scrObj, "UFunTwo");

	struct  
	{
		FString InfoStr;
		int32 Count;
	}FunTwoParam;

	FunTwoParam.InfoStr = FString("AScrActor--->UFunTwo");
	FunTwoParam.Count = 666;
	FunDelTwo.ProcessDelegate<UObject>(&FunTwoParam);

	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Red, FString::FromInt(FunTwoParam.Count));
}

void ADecActor::RunFunTwo()
{
	TBaseDelegate<bool, FString, int32> FunDelThree = TBaseDelegate<bool, FString, int32>::CreateUFunction(scrObj, "UFuncThree");

	bool Deresult = FunDelThree.Execute(FString("ASrcActor-->UFunThree"), 999);

	if (Deresult)
	{
		GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Yellow , L"Success");
	}
}

void ADecActor::RunFunThree()
{
	UFunction* FunFour = scrObj->FindFunction(FName("UFuncFour"));

	if (FunFour)
	{
		struct 
		{
			FString InfoStr;
			int32 Count;
 		}FunFourParam;


		FunFourParam.InfoStr = FString("AScrActor--->UFunFour");
		FunFourParam.Count = 1000;
		scrObj->ProcessEvent(FunFour, &FunFourParam);

		uint8* RefValPtr = (uint8*)&FunFourParam + FunFour->ReturnValueOffset;

		int32* RetfValue = (int32*)RefValPtr;

		GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Red, FString::FromInt(*RetfValue));
		GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Red, FString::FromInt(FunFourParam.Count));

	}
}

void ADecActor::RunFunFour()
{
	UFunction *InFun= scrObj->FindFunction(FName("UFunFour"));

	FString info = FString(TEXT("UFunFourInfoMessage"));

	if (InFun)
	{
		ProcessEvent(InFun, &info);
	}
}

// Called every frame
void ADecActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

