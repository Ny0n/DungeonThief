// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnFood.h"

#include "ChaosInterfaceWrapperCore.h"

// Sets default values
ASpawnFood::ASpawnFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create 2 box and a mesh
	staticTable = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("donnut"));
	RightBoxColider = CreateDefaultSubobject<UBoxComponent>(TEXT("RightBox"));
	LeftBoxColider = CreateDefaultSubobject<UBoxComponent>(TEXT("LeftBox"));

	staticTable -> SetupAttachment(RootComponent);
	RightBoxColider -> SetupAttachment(staticTable);
	LeftBoxColider -> SetupAttachment(staticTable);

	//save Position and rotation of the box
	RightLocation=FVector(0,80,100);
	LeftLocation=FVector(0,-80,100);
	RightRotation=FRotator(0,0,0);
	LeftRotation=FRotator(0,0,0);

	//Set Position and rotation of the box
	RightBoxColider-> SetRelativeScale3D(FVector(4,2,1));
	RightBoxColider -> SetRelativeLocation(RightLocation);
	RightBoxColider -> SetRelativeRotation(RightRotation);
	
	LeftBoxColider-> SetRelativeScale3D(FVector(4,2,1));
	LeftBoxColider -> SetRelativeLocation(LeftLocation);
	LeftBoxColider -> SetRelativeRotation(LeftRotation);

}

// Called when the game starts or when spawned
void ASpawnFood::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("SPawn"));	
	SpawnLeft();
	SpawnRight();
}

void ASpawnFood::SpawnLeft()
{
	GetWorld()->SpawnActor<AActor>(ActorTOSpawn,GetActorLocation()+ LeftLocation, GetActorRotation() + LeftRotation);
}
void ASpawnFood::SpawnRight()
{
	GetWorld()->SpawnActor<AActor>(ActorTOSpawn,GetActorLocation()+ RightLocation, GetActorRotation() + RightRotation);
}

