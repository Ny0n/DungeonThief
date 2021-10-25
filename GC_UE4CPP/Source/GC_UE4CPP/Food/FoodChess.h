// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "PickUp.h"
#include "../GC_UE4CPPGameModeBase.h"

#include "FoodChess.generated.h"


UCLASS()
class GC_UE4CPP_API AFoodChess : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFoodChess();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshToPutFood;

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	UBoxComponent* BoxPutFood;

	UPROPERTY()
	AGC_UE4CPPGameModeBase* GameModeBase;

	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
};
