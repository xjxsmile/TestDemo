// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FWDEActor.generated.h"

DECLARE_DELEGATE(FWDE_Single_Zero)
DECLARE_DELEGATE_TwoParams(FWDE_Single_Two,FString,int32)
DECLARE_MULTICAST_DELEGATE(FWDE_Muti_Zero)

DECLARE_DYNAMIC_DELEGATE(FWDE_Dy_sl_Zero);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWDE_Dy_sl_One,FString, InfoStr);

UCLASS()
class TESTDEMO_API AFWDEActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFWDEActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable, Category = "AFWDEActor")
		void RegFunDel(FWDE_Dy_sl_Zero TargetFun);


	//UFUNCTION(BlueprintCallable, Category = "AFWDEActor")
		//	void RegFunDel1(FWDE_Single_Zero TargetFun);
	UPROPERTY(BlueprintAssignable,Category="AFWDEActor")
	FWDE_Dy_sl_One FDSFun;

	/*UPROPERTY(BlueprintAssignable, Category = "AFWDEActor")
		FWDE_Muti_Zero FDSFunMu;*/
	/*UPROPERTY(BlueprintAssignable, Category = "AFWDEActor")
		FWDE_Dy_sl_Zero FDSFunZero;*/


	TFunction<void(FString)> TFunOne;

	void RegOne(TFunction<void(FString)> TargetFun);

	template<class UserClass>
	void RegTwo(UserClass* TarObj, typename TMemFunPtrType<false, UserClass, void(FString, int32)>::Type InMethod);

	template<class UserClass>
	void RegThree(UserClass* Obj, typename FWDE_Single_Two::TUObjectMethodDelegate<UserClass>::FMethodPtr InMethod);

	template<class DelegateType,class UserClass,typename... VarTypes>
	void RegFour(UserClass* Obj, typename DelegateType::template TUObjectMethodDelegate<UserClass>::FMethodPtr InMeth, VarTypes... vars);


	template<class RetType,typename... VarTypes>
	void RegFive(TFunction<RetType(VarTypes...)> TarFun);


};

template<class UserClass>
void AFWDEActor::RegTwo(UserClass* TarObj, typename TMemFunPtrType<false, UserClass, void(FString, int32)>::Type InMethod)
{
	FWDE_Single_Zero ExcDel;
	ExcDel.BindUObject(TarObj, InMethod, FString("AAAAAAAAAAAA"), 100);
	ExcDel.ExecuteIfBound(); 
}

template<class UserClass>
void AFWDEActor::RegThree(UserClass* Obj, typename FWDE_Single_Two::TUObjectMethodDelegate<UserClass>::FMethodPtr InMethod)
{
	FWDE_Single_Two ExcDel;
	ExcDel.BindUObject(Obj, InMethod);
	ExcDel.ExecuteIfBound(FString("BBBBBBBBBBBBB"),200);
}

template<class DelegateType, class UserClass, typename... VarTypes>
void AFWDEActor::RegFour(UserClass* Obj, typename DelegateType::template TUObjectMethodDelegate<UserClass>::FMethodPtr InMeth, VarTypes... vars)
{
	FWDE_Single_Zero ExcDel;
	ExcDel.BindUObject(Obj, InMeth, vars...);
	ExcDel.ExecuteIfBound();
}

template<class RetType, typename... VarTypes>
void AFWDEActor::RegFive(TFunction<RetType(VarTypes...)> TarFun)
{
	if (TarFun(FString("aaaaaaaaaaa"),78))
	{
		GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Green, L"Return True");
		GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Green, FString::SanitizeFloat(1222.f));
	}
}
