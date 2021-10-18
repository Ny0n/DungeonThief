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
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	// UFoodProgressBar* BarWBP;
};
