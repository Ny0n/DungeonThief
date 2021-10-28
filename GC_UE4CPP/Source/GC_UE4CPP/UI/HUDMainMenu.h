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

public:
	AHUDMainMenu();
	void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> MenuWbpClass;
	
	UPROPERTY()
	UMainMenu* BPMenu;
	
};
