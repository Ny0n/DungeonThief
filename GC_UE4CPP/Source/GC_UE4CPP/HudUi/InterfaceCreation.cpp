// Fill out your copyright notice in the Description page of Project Settings.


#include "InterfaceCreation.h"

#include "Blueprint/UserWidget.h"



void AInterfaceCreation::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("test"));

	if (ProgressBarreClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("I just started running"));
		Barre_Winget = CreateWidget<UProgressBarre>(GetWorld(),ProgressBarreClass);
		if (Barre_Winget)
		{
			Barre_Winget -> AddToViewport();
		}
		Barre_Winget -> UpdateProgressBarre(0.5f);
	}
}


void AInterfaceCreation::DrawHUD()
{
	Super::DrawHUD();
}



