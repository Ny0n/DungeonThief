// Fill out your copyright notice in the Description page of Project Settings.


#include "AIEnemy.h"

// Sets default values
AAIEnemy::AAIEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Enemy = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("donnut"));
	Enemy -> SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AAIEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}
