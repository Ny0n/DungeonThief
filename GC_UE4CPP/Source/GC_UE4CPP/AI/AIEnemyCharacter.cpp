// Fill out your copyright notice in the Description page of Project Settings.


#include "AIEnemyCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AAIEnemyCharacter::AAIEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Enemy = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GobelinMale"));
	Enemy->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AAIEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAIEnemyCharacter::CreateAndAttachFood() //Pick up item
{
	if (FoodBP != nullptr)
	{
		// spawn
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Owner = this;
		FRotator Rotator;
		FoodActor = GetWorld()->SpawnActor<APickUp>(FoodBP, GetActorLocation(), Rotator, SpawnParameters);

		// attach to ia
		FoodActor->MyMesh->SetEnableGravity(false);
		FoodActor->MyMesh->SetSimulatePhysics(false);
		FoodActor->MyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		FoodActor->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepWorldTransform);
		FoodActor->SetIsPickUp(true);
		FoodActor->SetActorLocation(GetActorLocation() + 40 * GetActorForwardVector() + FVector(0,0,-30));
		FoodActor->SetActorScale3D(FVector(0.25,0.25,0.25));
		FoodActor->SetActorRotation(FRotator(0,-45,0));
		
		bCarrying = true;
		GetCharacterMovement()->MaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed/2.0f;
	}
}

void AAIEnemyCharacter::DropFoodOnSpot(ASpotFood* TargetSpot) // Put the food on the spot
{
	if (FoodActor != nullptr)
	{
		FoodActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

		TargetSpot->SetHaveFood(true);
		FoodActor->SetIsPickUp(false);
		
		FoodActor->MyMesh->SetEnableGravity(false);
		FoodActor->MyMesh->SetSimulatePhysics(false);
		FoodActor->MyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		FoodActor->SetActorLocation(TargetSpot->GetSpotFoodLocation() + FVector(0,0,10));
		FoodActor->SetActorScale3D(FVector(0.75,0.75,0.75));
		FoodActor->SetActorRotation(FRotator(0,0,0));

		bCarrying = false;
		GetCharacterMovement()->MaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed*2.0f;
	}
}


