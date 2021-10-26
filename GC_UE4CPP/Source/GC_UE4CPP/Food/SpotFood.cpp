// Fill out your copyright notice in the Description page of Project Settings.


#include "SpotFood.h"

// Sets default values
ASpotFood::ASpotFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshToPutFood = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Table_Small"));
	MeshToPutFood -> SetupAttachment(RootComponent);
	
	BoxPutFood = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	BoxPutFood -> SetupAttachment(MeshToPutFood);

	BoxLocation=FVector(0,0,100);
	BoxRotation=FRotator(0,0,0);

	BoxPutFood-> SetRelativeScale3D(FVector(4,3,1));
	BoxPutFood -> SetRelativeLocation(BoxLocation);
	BoxPutFood -> SetRelativeRotation(BoxRotation);


	
	
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
	Location =GetActorLocation();
	return Location+BoxLocation;
}

FRotator ASpotFood::GetSpotFoodRotation()
{
	Rotation = GetActorRotation();
	return Rotation+BoxRotation;
}
/*
void ASpotFood::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("touché par"));
	FoodPickUp = Cast<APickUp>(OtherActor);
	if (FoodPickUp != nullptr)
	{
		if (!HaveFood && !FoodPickUp->GetIsPickUP())
		{
			FoodPickUp->MyMesh->SetEnableGravity(false);
			FoodPickUp->MyMesh->SetSimulatePhysics(false);
			FoodPickUp->MyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			
			FoodPickUp->SetActorLocation(this ->GetSpotFoodLocation() + FVector(0,0,10));

			FoodPickUp->SetActorScale3D(FVector(0.75,0.75,0.75));
			FoodPickUp->SetActorRotation(FRotator(0,0,0));
			SetHaveFood(true);
		}
	}
	
}
*/

