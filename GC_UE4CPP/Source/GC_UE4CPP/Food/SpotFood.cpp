// Fill out your copyright notice in the Description page of Project Settings.


#include "SpotFood.h"

// Sets default values
ASpotFood::ASpotFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshToPutFood = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Table_Small"));
	MeshToPutFood->SetupAttachment(RootComponent);
	
	BoxPutFood = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	BoxPutFood->SetupAttachment(MeshToPutFood);

	BoxLocation=FVector(0,0,100);
	BoxRotation=FRotator(0,0,0);

	BoxPutFood-> SetRelativeScale3D(FVector(3,3,1));
	BoxPutFood->SetRelativeLocation(BoxLocation);
	BoxPutFood->SetRelativeRotation(BoxRotation);
}

// Called when the game starts or when spawned
void ASpotFood::BeginPlay()
{
	Super::BeginPlay();
}

bool ASpotFood::GetHaveFood()
{
	return HaveFood;
}
	
void ASpotFood::SetHaveFood(bool BFood)
{
	HaveFood = BFood;
}

FVector ASpotFood::GetSpotFoodLocation()
{
	Location = GetActorLocation();
	return Location+BoxLocation;
}

FRotator ASpotFood::GetSpotFoodRotation()
{
	Rotation = GetActorRotation();
	return Rotation+BoxRotation;
}
