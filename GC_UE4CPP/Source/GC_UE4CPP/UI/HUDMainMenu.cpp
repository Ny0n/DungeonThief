// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDMainMenu.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

AHUDMainMenu::AHUDMainMenu()
{
	
	static ConstructorHelpers::FClassFinder<UUserWidget> UFoodProgressBarBPClass(TEXT("/Game/GC_UE4CPP/UI/MainMenu/WBP_MainMenu"));
	if (IsValid(UFoodProgressBarBPClass.Class))
	{
		MenuWBPClass = UFoodProgressBarBPClass.Class;
	}
	
}

void AHUDMainMenu::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(MenuWBPClass))
	{
		BPMenu = CreateWidget<UMainMenu>(GetWorld(), MenuWBPClass);
	}

	BPMenu->AddToViewport();
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
		PC->bShowMouseCursor = true;
	//UWidgetBlueprintLibrary::SetInputMode_UIOnly()

}


