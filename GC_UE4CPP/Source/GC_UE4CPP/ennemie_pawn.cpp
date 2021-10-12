// Fill out your copyright notice in the Description page of Project Settings.


#include "ennemie_pawn.h"

// Sets default values
Aennemie_pawn::Aennemie_pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Aennemie_pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Aennemie_pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Aennemie_pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

