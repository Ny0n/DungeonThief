// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

// Sets default values
APickUp::APickUp()
{
	PrimaryActorTick.bCanEverTick = false;
	
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
	MyMesh -> SetupAttachment(RootComponent);

	BoxMesh = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box"));
	BoxMesh ->SetupAttachment(MyMesh);

	BoxMesh -> SetRelativeScale3D(FVector(2,2,2));
	BoxMesh -> SetRelativeLocation(FVector(0,0,0));
	
	MyMesh->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

bool APickUp::GetIsPickUP()
{
	return IsPickUp;
}

void APickUp::SetIsPickUp(bool BPickUp)
{
	IsPickUp = BPickUp;
}
