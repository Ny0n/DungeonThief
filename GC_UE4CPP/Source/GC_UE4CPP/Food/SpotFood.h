// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Engine/TriggerBox.h"
#include "SpotFood.generated.h"

UCLASS()
class GC_UE4CPP_API ASpotFood : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpotFood();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshToPutFood;

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	UBoxComponent* BoxPutFood;

	UFUNCTION()
	bool GetHaveFood();
	
	UFUNCTION()
	void SetHaveFood(bool BFood);

	UFUNCTION()
	FVector GetSpotFoodLocation();

	UFUNCTION()
	FRotator GetSpotFoodRotation();

	
	
private:
	FVector BoxLocation;
	FRotator BoxRotation;
	FVector Location;
	FRotator Rotation;
	bool HaveFood = false;
};
