// Fill out your copyright notice in the Description page of Project Settings.


#include "ChairAction.h"

#include "Camera/CameraComponent.h"

// Sets default values
AChairAction::AChairAction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
	MyMesh -> SetupAttachment(RootComponent);

	BoxMesh = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box"));
	BoxMesh ->SetupAttachment(MyMesh);

	BoxMesh -> SetRelativeScale3D(FVector(2,2,2));
	BoxMesh -> SetRelativeLocation(FVector(0,0,60));
	
	MyMesh->SetSimulatePhysics(true);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera -> SetupAttachment(MyMesh);
}

// Called when the game starts or when spawned
void AChairAction::BeginPlay()
{
	Super::BeginPlay();
	Camera->SetRelativeLocation(FVector(0,500,300));
	Camera -> SetRelativeRotation(FRotator(0,-20,-90));
	
}



