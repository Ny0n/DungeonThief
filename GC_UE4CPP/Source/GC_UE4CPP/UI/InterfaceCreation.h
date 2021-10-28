// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EndScreen.h"
#include "FoodProgressBar.h"
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
	AInterfaceCreation();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> BarWbpClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> EndScreenWbpClass;
	
	void InitWidgets();
	void ShowPlayHUD();
	void ShowEndHUD(bool bVictory);
	
private:
	UPROPERTY()
	UFoodProgressBar* BarWbp;

	UPROPERTY()
	UEndScreen* EndScreenWbp;
	
};
