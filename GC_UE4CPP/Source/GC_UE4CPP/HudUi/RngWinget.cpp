// Fill out your copyright notice in the Description page of Project Settings.


#include "RngWinget.h"

#include "Components/Button.h"

void URngWinget::NativeConstruct()
{
	Super::NativeConstruct();

	GenerateRandom();

	GenerateButton -> OnClicked.AddUniqueDynamic( this, &URngWinget::OnGenerateButtonCliked);
}
void URngWinget::GenerateRandom()
{
	int32 RandomNumber = FMath::RandRange(0,100);
	RandomNumberLabel -> SetText(FText::AsNumber( RandomNumber));
}

void URngWinget::OnGenerateButtonCliked()
{
	GenerateRandom();
}


