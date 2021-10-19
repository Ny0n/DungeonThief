// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FoodProgressBar.generated.h"

// Forward declaration to avoid circular dependencies
class AGC_UE4CPPGameModeBase;

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
	
	UPROPERTY()
	AGC_UE4CPPGameModeBase* GameModeBase;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* WidgetFoodProgressBar;
};
