// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDMainMenu.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

AHUDMainMenu::AHUDMainMenu()
{
	
}

void AHUDMainMenu::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsValid(MenuWbpClass))
	{
		BPMenu = CreateWidget<UMainMenu>(GetWorld(), MenuWbpClass);
		BPMenu->AddToViewport();
	}

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC != nullptr)
		PC->bShowMouseCursor = true;
}


