// Fill out your copyright notice in the Description page of Project Settings.


#include "InterfaceCreation.h"

#include "Components/TextBlock.h"

AInterfaceCreation::AInterfaceCreation()
{
	
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
	if (IsValid(BarWbpClass))
	{
		BarWbp = CreateWidget<UFoodProgressBar>(GetWorld(), BarWbpClass);
	}

	if (IsValid(EndScreenWbpClass))
	{
		EndScreenWbp = CreateWidget<UEndScreen>(GetWorld(), EndScreenWbpClass);
	}
}

void AInterfaceCreation::ShowPlayHUD()
{
	BarWbp->AddToViewport();
	EndScreenWbp->RemoveFromParent();
	
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
	
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC != nullptr)
		PC->bShowMouseCursor = false;
}

void AInterfaceCreation::ShowEndHUD(bool bVictory)
{
	BarWbp->RemoveFromParent();
	EndScreenWbp->AddToViewport();
	
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC != nullptr)
		PC->bShowMouseCursor = true;

	// we show the right end text
	
	EndScreenWbp->VictoryText->SetVisibility(ESlateVisibility::Hidden);
	EndScreenWbp->DefeatText->SetVisibility(ESlateVisibility::Hidden);

	if (bVictory)
		EndScreenWbp->VictoryText->SetVisibility(ESlateVisibility::Visible);
	else
		EndScreenWbp->DefeatText->SetVisibility(ESlateVisibility::Visible);
}
