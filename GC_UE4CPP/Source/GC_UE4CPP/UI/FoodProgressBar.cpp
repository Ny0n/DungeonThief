// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodProgressBar.h"

#include "Components/ProgressBar.h"

void UFoodProgressBar::NativeConstruct()
{
	Super::NativeConstruct();

	if (WidgetFoodProgressBar)
	{
		WidgetFoodProgressBar->SetPercent(0.5);
	}
	
}

void UFoodProgressBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
}

void UFoodProgressBar::UpdateFoodProgressBar(float Value)
{
//		WidgetFoodProgressBar->SetPercent(Value);
}


