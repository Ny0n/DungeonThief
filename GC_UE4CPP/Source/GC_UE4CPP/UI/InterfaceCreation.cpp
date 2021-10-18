// Fill out your copyright notice in the Description page of Project Settings.


#include "InterfaceCreation.h"

#include "Blueprint/UserWidget.h"

void AInterfaceCreation::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("test"));

	// BarWBP = CreateWidget<UFoodProgressBar>(GetWorld());
	// if (BarWBP)
	// {
	// 	BarWBP->AddToViewport();
	// }
}

void AInterfaceCreation::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}
