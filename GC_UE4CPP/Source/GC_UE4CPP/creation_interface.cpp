// Fill out your copyright notice in the Description page of Project Settings.


#include "creation_interface.h"

#include "Blueprint/UserWidget.h"



void Acreation_interface::BeginPlay()
{
	Super::BeginPlay();
	if (Barre_ProgressionClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("I just started running"));
		Barre_Winget = CreateWidget<UBarre_progression>(GetWorld(),Barre_ProgressionClass);
		if (Barre_Winget)
		{
			Barre_Winget -> AddToViewport();
		}
		Barre_Winget -> UpdateProgressBarre(0.5f);
	}
}


void Acreation_interface::DrawHUD()
{
	Super::DrawHUD();
}



