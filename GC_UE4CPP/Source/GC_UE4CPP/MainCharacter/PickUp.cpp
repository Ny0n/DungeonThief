// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

// Sets default values
APickUp::APickUp()


{
	PrimaryActorTick.bCanEverTick = true;
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
	MyMesh->SetSimulatePhysics(true);
	RootComponent = MyMesh;

	bHolding = false;
	bGravity = true;

}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

void APickUp::PickUp()
{	
}

bool APickUp::GetIsPickUP()
{
	return IsPickUp;
}

void APickUp::SetIsPickUp(bool BPickUp)
{
	IsPickUp = BPickUp;
}

