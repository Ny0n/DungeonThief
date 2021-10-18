// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodProgressBar.h"

#include "Components/ProgressBar.h"

void UFoodProgressBar::NativeConstruct()
{
	Super::NativeConstruct();
	
}

void UFoodProgressBar::UpdateFoodProgressBar(int val)
{
	FoodProgressBar->SetPercent(val);
}


