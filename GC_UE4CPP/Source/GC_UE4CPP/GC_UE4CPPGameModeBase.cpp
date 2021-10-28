// Copyright Epic Games, Inc. All Rights Reserved.


#include "GC_UE4CPPGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "MainCharacter/MainCharacter.h"

AGC_UE4CPPGameModeBase::AGC_UE4CPPGameModeBase()
{
	
}

void AGC_UE4CPPGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActorReferencer::StaticClass(), OutActors);
	ActorReferencer = Cast<AActorReferencer>(OutActors[0]);

	HUDBase = Cast<AInterfaceCreation>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if (HUDBase != nullptr)
		HUDBase->InitWidgets();
	
	Play();
	SpawnRandomFood();
	InitAI();
}

void AGC_UE4CPPGameModeBase::InitAI()
{
	// 2 initial AI
	SpawnAI();
	SpawnAIWithDelay(1);

	// one more after a minute
	SpawnAIWithDelay(60.0f);
}

void AGC_UE4CPPGameModeBase::SpawnRandomFood()
{
	if (FoodBP != nullptr)
	{
		// spawn
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Owner = this;
		const FVector Location = FVector(0, 0, 0);
		const FRotator Rotator;
		APickUp* FoodActor = GetWorld()->SpawnActor<APickUp>(FoodBP, Location, Rotator, SpawnParameters);

		// find random food spot
		const int Index = UKismetMathLibrary::RandomInteger(ActorReferencer->FoodSpots.Num());
		ASpotFood* TargetSpot = Cast<ASpotFood>(ActorReferencer->FoodSpots[Index]);

		if (TargetSpot != nullptr)
		{
			// link food to spot
			FoodActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
			TargetSpot->SetHaveFood(true);
			FoodActor->SetIsPickUp(false);
			FoodActor->MyMesh->SetEnableGravity(false);
			FoodActor->MyMesh->SetSimulatePhysics(false);
			FoodActor->MyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			FoodActor->SetActorLocation(TargetSpot->GetSpotFoodLocation() + FVector(0,0,10));
			FoodActor->SetActorScale3D(FVector(0.75,0.75,0.75));
			FoodActor->SetActorRotation(FRotator(0,0,0));
		
			// one new food
			FoodNb = FoodNb + 1;
		}
	}
}

void AGC_UE4CPPGameModeBase::SpawnAI()
{
	ActiveAI = ActiveAI + 1;
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;
	const FVector Location = ActorReferencer->ExitDoor->GetActorLocation();
	const FRotator Rotator = ActorReferencer->ExitDoor->GetActorRotation();
	AAIEnemyCharacter* SpawnedAI = GetWorld()->SpawnActor<AAIEnemyCharacter>(EnemyCharacter, Location, Rotator, SpawnParameters);

	if (FoodNb < MaxFoodInGame)
	{
		SpawnedAI->CreateAndAttachFood();
		FoodNb = FoodNb + 1;
	}
}

void AGC_UE4CPPGameModeBase::SpawnAIWithDelay(const float Delay)
{
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AGC_UE4CPPGameModeBase::SpawnAI, Delay, false);
}

void AGC_UE4CPPGameModeBase::RemoveAI()
{
	ActiveAI = ActiveAI - 1;
	if (ActiveAI <= 0)
	{
		SpawnAI();
	}
	else
	{
		SpawnAIWithDelay(UKismetMathLibrary::RandomFloatInRange(0.0f, 5.0f));
	}
}

void AGC_UE4CPPGameModeBase::DropPlayerFood()
{
	// drop the player's food
	AMainCharacter* Player = Cast<AMainCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Player != nullptr && Player->bCarrying)
		Player->ToggleItemDropDown(Player->CurrentItem);
}

void AGC_UE4CPPGameModeBase::Victory()
{
	bVictory = true;
	bDefeat = false;
	bPlaying = false;

	HUDBase->ShowEndHUD(true);
	DropPlayerFood();
}

void AGC_UE4CPPGameModeBase::Defeat()
{
	bVictory = false;
	bDefeat = true;
	bPlaying = false;

	HUDBase->ShowEndHUD(false);
	DropPlayerFood();
}

void AGC_UE4CPPGameModeBase::Play()
{
	bVictory = false;
	bDefeat = false;
	bPlaying = true;

	HUDBase->ShowPlayHUD();
}

void AGC_UE4CPPGameModeBase::AddFood()
{
	FoodCurrentQuantity = UKismetMathLibrary::Min(FoodCurrentQuantity + 1, FoodMaxQuantity);
	if (FoodCurrentQuantity == 5 )
	{
		Victory();
	}
	FoodNb = FoodNb - 1;
}
