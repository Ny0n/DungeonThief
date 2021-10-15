// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ProgressBarre.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UProgressBarre : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,  meta = (BindWidget))
	class  UProgressBar * ProgressBarre;

	
	
	UFUNCTION()
			void UpdateProgressBarre(int val);
	
	void NativeConstruct() override;
};