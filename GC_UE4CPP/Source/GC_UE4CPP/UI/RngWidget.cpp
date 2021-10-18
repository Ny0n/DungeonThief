// Fill out your copyright notice in the Description page of Project Settings.


#include "RngWidget.h"

#include "Components/Button.h"

void URngWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GenerateRandom();

	GenerateButton->OnClicked.AddUniqueDynamic(this, &URngWidget::OnGenerateButtonCliked);
}
void URngWidget::GenerateRandom()
{
	int32 RandomNumber = FMath::RandRange(0, 100);
	RandomNumberLabel->SetText(FText::AsNumber(RandomNumber));
}

void URngWidget::OnGenerateButtonCliked()
{
	GenerateRandom();
}
