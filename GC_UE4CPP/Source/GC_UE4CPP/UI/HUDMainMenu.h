// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenu.h"
#include "HUDMainMenu.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API AHUDMainMenu : public AHUD
{
	GENERATED_BODY()
	AHUDMainMenu();
	void BeginPlay() override;

private:
	TSubclassOf<UUserWidget> MenuWBPClass;

public:
	UPROPERTY()
	UMainMenu* BPMenu;
};
