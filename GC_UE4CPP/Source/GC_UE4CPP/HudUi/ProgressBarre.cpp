// Fill out your copyright notice in the Description page of Project Settings.


#include "ProgressBarre.h"

#include "Components/Button.h"
#include "Components/ProgressBar.h"

void UProgressBarre::NativeConstruct()
{
	Super::NativeConstruct();
	
}

void UProgressBarre::UpdateProgressBarre(int val)
{
	ProgressBarre-> SetPercent(val);
}


