// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodChess.h"

// Sets default values
AFoodChess::AFoodChess()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshToPutFood = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Chess for Food"));
	MeshToPutFood -> SetupAttachment(RootComponent);

	BoxPutFood = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	BoxPutFood -> SetupAttachment(MeshToPutFood);

	BoxPutFood-> SetRelativeScale3D(FVector(2,2,2));
	BoxPutFood -> SetRelativeLocation(FVector(0,0,30));
	BoxPutFood -> SetRelativeRotation(FRotator(0,0,0));
}

// Called when the game starts or when spawned
void AFoodChess::BeginPlay()
{
	Super::BeginPlay();
	BoxPutFood->OnComponentBeginOverlap.AddDynamic(this, &AFoodChess::OnBoxBeginOverlap);
	GameModeBase = Cast<AGC_UE4CPPGameModeBase>(GetWorld()->GetAuthGameMode());


}

void AFoodChess::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult)
{
	CurrentItem = Cast<APickUp>(OtherActor);
	
	
}

void AFoodChess::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CurrentItem != nullptr)
	{
		if (!CurrentItem->GetIsPickUP())
		{
			CurrentItem->Destroy();
			GameModeBase->AddFood();
			CurrentItem = nullptr;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("chess :: la food es tenu"));
		}
		
	}
}


