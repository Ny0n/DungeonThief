// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
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
	UBoxComponent* RightBoxColider;

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	UBoxComponent* LeftBoxColider;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* staticTable;


	FVector RightLocation;
	FVector LeftLocation;
	FRotator RightRotation;
	FRotator LeftRotation;
	
	
};
