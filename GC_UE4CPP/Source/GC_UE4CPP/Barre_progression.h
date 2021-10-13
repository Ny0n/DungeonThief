// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Barre_progression.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UBarre_progression : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY( meta = (BindWidget))
	class UTextBlock * BarreLabel;	

	UPROPERTY( meta = (BindWidget))
		class UButton * ButtonBarre;

	UPROPERTY(  meta = (BindWidget))
		class  UProgressBar * progressBarre;

	
	UFUNCTION()
			void OnGenerateButtonCliked();
	
	void NativeConstruct() override;

private:
	int32 LBarre = 1;

	
};
