// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "RngWidget.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API URngWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	void GenerateRandom();
	
	UPROPERTY( meta = (BindWidget))
		class UTextBlock * RandomNumberLabel;

	UPROPERTY( meta = (BindWidget))
		class UButton * GenerateButton;
	UFUNCTION()
		void OnGenerateButtonCliked();
	
	void NativeConstruct() override;
};
