// Copyright Epic Games, Inc. All Rights Reserved.


#include "GC_UE4CPPGameModeBase.h"

#include "MainCharacter/MainCharacter.h"

AGC_UE4CPPGameModeBase::AGC_UE4CPPGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/GC_UE4CPP/Characters/MainCharacter/BP_MainCharacter"));
	if (IsValid(PlayerPawnBPClass.Class))
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
