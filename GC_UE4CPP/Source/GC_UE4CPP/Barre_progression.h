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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "progresBarre",  meta = (BindWidget))
		class  UProgressBar * progressBarre;

	
	UFUNCTION()
			void UpdateProgressBarre(int val);
	
	void NativeConstruct() override;



	
};
