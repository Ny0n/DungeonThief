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
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* WidgetFoodProgressBar;
	
	UFUNCTION()
	void UpdateFoodProgressBar(float Value);
};
