// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TestDemoGameMode.h"
#include "TestDemoBall.h"

ATestDemoGameMode::ATestDemoGameMode()
{
	// set default pawn class to our ball
	DefaultPawnClass = ATestDemoBall::StaticClass();
}
