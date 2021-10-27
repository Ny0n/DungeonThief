// Copyright Epic Games, Inc. All Rights Reserved.


#include "GC_UE4CPPGameModeBase.h"
#include "GameFramework/HUD.h"
#include "Kismet/KismetMathLibrary.h"

AGC_UE4CPPGameModeBase::AGC_UE4CPPGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/GC_UE4CPP/Characters/MainCharacter/BP_MainCharacter"));
	if (IsValid(PlayerPawnBPClass.Class))
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<AHUD> MainHUDBPClass(TEXT("/Game/GC_UE4CPP/UI/HUD/BP_InterfaceCreation"));
	if (IsValid(MainHUDBPClass.Class))
	{
		HUDClass = MainHUDBPClass.Class;
	}
}

void AGC_UE4CPPGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	HUDBase = Cast<AInterfaceCreation>(GetWorld()->GetFirstPlayerController()->GetHUD());
	HUDBase->InitWidgets();
	Play();
}

void AGC_UE4CPPGameModeBase::Victory()
{
	bVictory = true;
	bDefeat = false;
	bPlaying = false;

	HUDBase->ShowEndHUD(true);
}

void AGC_UE4CPPGameModeBase::Defeat()
{
	bVictory = false;
	bDefeat = true;
	bPlaying = false;

	HUDBase->ShowEndHUD(false);
}

void AGC_UE4CPPGameModeBase::Play()
{
	bVictory = false;
	bDefeat = false;
	bPlaying = true;

	HUDBase->ShowPlayHUD();
}

void AGC_UE4CPPGameModeBase::AddFood()
{
	FoodCurrentQuantity = UKismetMathLibrary::Min(FoodCurrentQuantity + 1, FoodMaxQuantity);
	if (FoodCurrentQuantity == 5 )
	{
		Victory();
	}
}
