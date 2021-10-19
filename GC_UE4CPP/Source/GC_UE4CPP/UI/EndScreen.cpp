// Fill out your copyright notice in the Description page of Project Settings.


#include "EndScreen.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UEndScreen::NativeConstruct()
{
	Super::NativeConstruct();

	RestartButton->OnClicked.AddDynamic(this, &UEndScreen::Restart);
}

void UEndScreen::Restart()
{
	UGameplayStatics::OpenLevel(this, FName(GetWorld()->GetName()));
}
