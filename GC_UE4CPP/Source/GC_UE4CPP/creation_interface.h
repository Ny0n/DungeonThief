// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Barre_progression.h"

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "creation_interface.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API Acreation_interface : public AHUD
{
	
	GENERATED_BODY()
public:
	virtual void DrawHUD() override;
	virtual  void BeginPlay() override;

	

	UPROPERTY(EditDefaultsOnly,Category= "widgets")
	TSubclassOf<UUserWidget>Barre_ProgressionClass;
	
	UBarre_progression * Barre_Winget;
	
	
};
