// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnFood.h"

// Sets default values
ASpawnFood::ASpawnFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnFood::BeginPlay()
{
	Super::BeginPlay();
	
	const FVector Location = GetActorLocation();
	const FRotator Rotation = GetActorRotation();
	
	GetWorld() -> SpawnActor<AActor>(ActorTOSpawn , Location, Rotation);
	
}

