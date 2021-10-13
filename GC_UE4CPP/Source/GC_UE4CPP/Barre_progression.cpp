// Fill out your copyright notice in the Description page of Project Settings.


#include "Barre_progression.h"

#include "Components/Button.h"
#include "Components/ProgressBar.h"

void UBarre_progression::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonBarre -> OnClicked.AddUniqueDynamic(this , &UBarre_progression::OnGenerateButtonCliked);
}

void UBarre_progression::OnGenerateButtonCliked()
{
	LBarre = LBarre+25;
	if (LBarre >100)
	{
		LBarre=1;
	}
	progressBarre-> Percent  = LBarre;
	
}