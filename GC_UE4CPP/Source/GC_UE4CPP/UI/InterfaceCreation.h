// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "FoodProgressBar.h"

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InterfaceCreation.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API AInterfaceCreation : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void DrawHUD() override;
	virtual  void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly,Category= "widgets")
	TSubclassOf<UUserWidget> ProgressBarreClass;
	
	UFoodProgressBar* BarWidget;
};
