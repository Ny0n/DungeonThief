// Fill out your copyright notice in the Description page of Project Settings.


#include "IA_mobility.h"

// Sets default values
AIA_mobility::AIA_mobility()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIA_mobility::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIA_mobility::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AIA_mobility::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

