// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	PlayButton->OnClicked.AddDynamic(this, &UMainMenu::StartPlaying);
	ExitButton->OnClicked.AddDynamic(this, &UMainMenu::QuitGame);
}

void UMainMenu::StartPlaying()
{
	UGameplayStatics::OpenLevel(GetWorld(),"niveau");
}

void UMainMenu::QuitGame()
{
	UKismetSystemLibrary::QuitGame(GetWorld(),GetWorld()->GetFirstPlayerController(),EQuitPreference::Quit,false);
	//FGenericPlatformMisc::RequestExit(false);
	//UKismetSystemLibrary::QuitGame();
	//GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}