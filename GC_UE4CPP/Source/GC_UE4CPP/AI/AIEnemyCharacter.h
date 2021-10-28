// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GC_UE4CPP/Food/PickUp.h"
#include "GC_UE4CPP/Food/SpotFood.h"
#include "AIEnemyCharacter.generated.h"

UCLASS()
class GC_UE4CPP_API AAIEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAIEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* Enemy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class APickUp> FoodBP;

	UPROPERTY()
	APickUp* FoodActor;

	UPROPERTY(BlueprintReadOnly)
	bool bCarrying = false;

	void CreateAndAttachFood();
	void DropFoodOnSpot(ASpotFood* TargetSpot);
};
