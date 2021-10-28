// Fill out your copyright notice in the Description page of Project Settings.


#include "Woodfire.h"

#include "Components/LightComponent.h"

// Sets default values
AWoodfire::AWoodfire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("RootScene")));
	RootComponent = RootMesh;
	 
	FireLight = CreateDefaultSubobject<UPointLightComponent>(FName(TEXT("PointLight")));
	FireLight->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AWoodfire::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWoodfire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

