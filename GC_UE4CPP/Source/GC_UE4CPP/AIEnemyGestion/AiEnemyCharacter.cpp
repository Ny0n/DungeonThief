// Fill out your copyright notice in the Description page of Project Settings.


#include "AIEnemyCharacter.h"

// Sets default values
AAIEnemyCharacter::AAIEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Enemy = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gobelin_Male"));
	Enemy -> SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AAIEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}



