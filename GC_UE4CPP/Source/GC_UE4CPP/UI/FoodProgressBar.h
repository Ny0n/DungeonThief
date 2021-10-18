// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FoodProgressBar.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UFoodProgressBar : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class  UProgressBar * FoodProgressBar;
	
	UFUNCTION()
			void UpdateFoodProgressBar(int val);
	
	void NativeConstruct() override;
};