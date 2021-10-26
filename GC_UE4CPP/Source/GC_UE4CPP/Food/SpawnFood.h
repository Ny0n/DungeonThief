// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "PickUp.h"
#include "SpawnFood.generated.h"

UCLASS()
class GC_UE4CPP_API ASpawnFood : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnFood();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere , BlueprintReadWrite, Category= "meshToSpawn")
	TSubclassOf<AActor> ActorTOSpawn;

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	UBoxComponent* BoxColider;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* staticTable;

	UPROPERTY(EditAnywhere)
	class APickUp* FoodSpawn;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);
	
	void Spawn();
	float HaveFood = false;
	bool GetHaveFood();
	void SetHaveFood(bool Food);
	
	FVector Location;
	FRotator Rotation;
	
	
};
