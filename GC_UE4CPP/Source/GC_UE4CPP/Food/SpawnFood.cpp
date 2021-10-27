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
	BoxColider = CreateDefaultSubobject<UBoxComponent>(TEXT("RightBox"));

	staticTable -> SetupAttachment(RootComponent);
	BoxColider -> SetupAttachment(staticTable);

	//save Position and rotation of the box
	Location=FVector(0,0,200);
	Rotation=FRotator(0,0,0);

	//Set Position and rotation of the box
	BoxColider-> SetRelativeScale3D(FVector(4,5,1));
	BoxColider -> SetRelativeLocation(Location);
	BoxColider -> SetRelativeRotation(Rotation);
	
	

}

// Called when the game starts or when spawned
void ASpawnFood::BeginPlay()
{
	Super::BeginPlay();
	BoxColider->OnComponentBeginOverlap.AddDynamic(this, &ASpawnFood::OnOverlapBegin);
	Spawn();
}

void ASpawnFood::Spawn()
{
	GetWorld()->SpawnActor<AActor>(ActorTOSpawn,GetActorLocation()+ Location, GetActorRotation() + Rotation);
}
UFUNCTION()
		void ASpawnFood::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult)
{
	FoodSpawn = Cast<APickUp>(OtherActor);
	if (FoodSpawn !=nullptr && !FoodSpawn->IsPickUp)
	{
		FoodSpawn->MyMesh->SetEnableGravity(false);
		FoodSpawn->MyMesh->SetSimulatePhysics(false);
		FoodSpawn->MyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		FoodSpawn->SetActorLocation(GetActorLocation() + FVector(0,0,100) ); 
		FoodSpawn->SetActorRotation(GetActorRotation()+FRotator(0,0,0));
		FoodSpawn->SetActorScale3D(FVector(1,1,1));
		SetHaveFood(true);
	}
}
bool ASpawnFood::GetHaveFood()
{
	return HaveFood;
}

void ASpawnFood::SetHaveFood(bool food)
{
	HaveFood = food;
}


