// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMyInterface : public UInterface
{
	//GENERATED_UINTERFACE_BODY()
	GENERATED_BODY()
};

/**
 * 
 */
class TESTDEMO_API IMyInterface
{
	//GENERATED_UINTERFACE_BODY()
	GENERATED_BODY()
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	/*UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
		void FunOne();*/

};
