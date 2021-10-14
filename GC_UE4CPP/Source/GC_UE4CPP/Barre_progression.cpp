// Fill out your copyright notice in the Description page of Project Settings.


#include "Barre_progression.h"

#include "Components/Button.h"
#include "Components/ProgressBar.h"

void UBarre_progression::NativeConstruct()
{
	Super::NativeConstruct();
}

void UBarre_progression::UpdateProgressBarre(int val)
{
	progressBarre-> Percent = 50;
}