// Fill out your copyright notice in the Description page of Project Settings.


#include "InterfaceCreation.h"

#include "Components/TextBlock.h"

AInterfaceCreation::AInterfaceCreation()
{
	// HUD food bar
	static ConstructorHelpers::FClassFinder<UUserWidget> UFoodProgressBarBPClass(TEXT("/Game/GC_UE4CPP/UI/HUD/WBP_FoodProgressBar"));
	if (IsValid(UFoodProgressBarBPClass.Class))
	{
		BarWBPClass = UFoodProgressBarBPClass.Class;
	}

	// HUD end screen
	static ConstructorHelpers::FClassFinder<UUserWidget> UEndScreenBPClass(TEXT("/Game/GC_UE4CPP/UI/HUD/WBP_EndScreen"));
	if (IsValid(UEndScreenBPClass.Class))
	{
		EndScreenWBPClass = UEndScreenBPClass.Class;
	}
}

void AInterfaceCreation::BeginPlay()
{
	Super::BeginPlay();
}

void AInterfaceCreation::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}

void AInterfaceCreation::InitWidgets()
{
	if (IsValid(BarWBPClass))
	{
		BarWBP = CreateWidget<UFoodProgressBar>(GetWorld(), BarWBPClass);
	}

	if (IsValid(EndScreenWBPClass))
	{
		EndScreenWBP = CreateWidget<UEndScreen>(GetWorld(), EndScreenWBPClass);
	}
}

void AInterfaceCreation::ShowPlayHUD()
{
	BarWBP->AddToViewport();
	EndScreenWBP->RemoveFromParent();
	
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
	
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
		PC->bShowMouseCursor = false;
}

void AInterfaceCreation::ShowEndHUD(bool bVictory)
{
	BarWBP->RemoveFromParent();
	EndScreenWBP->AddToViewport();
	
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
		PC->bShowMouseCursor = true;

	// we show the right end text
	
	EndScreenWBP->VictoryText->SetVisibility(ESlateVisibility::Hidden);
	EndScreenWBP->DefeatText->SetVisibility(ESlateVisibility::Hidden);

	if (bVictory)
		EndScreenWBP->VictoryText->SetVisibility(ESlateVisibility::Visible);
	else
		EndScreenWBP->DefeatText->SetVisibility(ESlateVisibility::Visible);
}
