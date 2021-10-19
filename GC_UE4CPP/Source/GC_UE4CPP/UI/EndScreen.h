// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EndScreen.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UEndScreen : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void Restart();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* VictoryText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* DefeatText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* RestartButton;
	
};
