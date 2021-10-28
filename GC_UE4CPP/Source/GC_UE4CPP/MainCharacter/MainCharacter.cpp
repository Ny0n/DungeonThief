// Fill out your copyright notice in the Description page of Project Settings.
//		UE_LOG(LogTemp, Warning, TEXT("spotenregistré"));


#include "MainCharacter.h"
#include "../Food/PickUp.h"
#include "../Food/SpotFood.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GC_UE4CPP/GC_UE4CPPGameModeBase.h"
#include "GC_UE4CPP/AI/AIEnemyCharacter.h"
#include "GC_UE4CPP/UI/InterfaceCreation.h"
#include "Kismet/KismetMathLibrary.h"
#include "Perception/AISense_Sight.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

	BoomArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera boom"));
	BoomArm->SetupAttachment(RootComponent);
	BoomArm->TargetArmLength = 400;
	BoomArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(BoomArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 540, 0);
	
	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule->InitCapsuleSize(55.f, 96.0f);
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule->SetupAttachment(RootComponent);

	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &AMainCharacter::OnOverlapBegin);
	TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &AMainCharacter::OnOverlapEnd);

	SetupStimuli();
}

void AMainCharacter::SetupStimuli()
{
	StimulusComponent = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>("Stimulus");
	StimulusComponent->RegisterForSense(TSubclassOf<UAISense_Sight>());
	StimulusComponent->RegisterWithPerceptionSystem();
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	check(GEngine != nullptr);

	// References to the default GameModeBase classes
	GameModeBase = Cast<AGC_UE4CPPGameModeBase>(GetWorld()->GetAuthGameMode());
	HUDBase = Cast<AInterfaceCreation>(GetWorld()->GetFirstPlayerController()->GetHUD());
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	Start = Camera->GetComponentLocation();
	ForwardVector = Camera->GetForwardVector();
	End = ((ForwardVector * 200.f) + Start);

	if (!GameModeBase->bPlaying)
	{
		GetCharacterMovement()->MaxWalkSpeed = 0.0f;
		PrimaryActorTick.bCanEverTick = false;
	}
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMainCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMainCharacter::LookUpAtRate);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Scroll", this, &AMainCharacter::ZoomInOut);
	
	

	// Bind action event
	PlayerInputComponent->BindAction("Action_E", IE_Pressed, this, &AMainCharacter::OnAction);

	// HUD test
	PlayerInputComponent->BindAction("Action_Num1", IE_Pressed, this, &AMainCharacter::Num1Pressed);
	PlayerInputComponent->BindAction("Action_Num2", IE_Pressed, this, &AMainCharacter::Num2Pressed);
	PlayerInputComponent->BindAction("Action_Num3", IE_Pressed, this, &AMainCharacter::Num3Pressed);

}

//*********************************** Pick up ***********************************************//

//**************** Overlap ****************//

void AMainCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if(!IsCarrying()) 
    {
    	CurrentItem = Cast<APickUp>(OtherActor);
        if (CurrentItem !=nullptr)
        {
        	bTouchItem = true;
        }
    }
	if (!bTouchSpot)
	{
		CurrentSpotFood = Cast<ASpotFood>(OtherActor);
		if(CurrentSpotFood != nullptr)
		{
			bTouchSpot = true;
		}
	}

	if (Cast<AAIEnemyCharacter>(OtherActor))
		GameModeBase->Defeat();

	CurrentChair = Cast<AChairAction>(OtherActor);
	if(CurrentChair != nullptr)
	{
		bChair = true;
		UE_LOG(LogTemp, Warning, TEXT("chair"));

	}	
}

void AMainCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	CurrentSpotFood = Cast<ASpotFood>(OtherActor);
	if (CurrentSpotFood != nullptr)
	{
		bTouchSpot = false;
		CurrentSpotFood = nullptr;
		if (!IsCarrying())
		{
			bTouchItem = false;
			CurrentItem = nullptr;
		}
	}
	if(!IsCarrying())
	{
		CurrentItem = Cast<APickUp>(OtherActor);
	}
	if (CurrentItem != nullptr)
	{
		if (!CurrentItem->GetIsPickUP())
		{
			bTouchItem = false;
		}
	}

	if(Cast<AChairAction>(OtherActor))
		bChair = false;
}
	

//**************** Action press E ****************//

void AMainCharacter::OnAction()
{
	if ( CurrentItem != nullptr && CurrentSpotFood !=nullptr )
	{
		if (IsCarrying() && !CurrentSpotFood->GetHaveFood()) // Put the food on the spot
		{
			ToggleItemDropDownSpot(CurrentSpotFood,CurrentItem);
			SetIsCarrying(false);
			
		}else if (!IsCarrying() && CurrentSpotFood->GetHaveFood()) // take the food on the spot
		{
			ToggleItemPickupSpot(CurrentSpotFood,CurrentItem);
			SetIsCarrying(true);
		}
	}else if (CurrentItem != nullptr && CurrentSpotFood ==nullptr)  
	{
		if (IsCarrying())                                 // drop Item
		{
			ToggleItemDropDown(CurrentItem);
			SetIsCarrying(false);
			CurrentItem = nullptr;
			bTouchItem = false;
		}
		else if (bTouchItem && !IsCarrying() && !CurrentItem->GetIsPickUP()) //Pick up item
		{
			ToggleItemPickup(CurrentItem);
			SetIsCarrying(true);
		}
	}
	if (bChair && !IsCarrying() && !IsSitting())
	{
		SitDownCharacter();
		UE_LOG(LogTemp, Warning, TEXT("e + chair"));
	}else if (IsSitting())
	{
		SitUpCharacter();
		UE_LOG(LogTemp, Warning, TEXT("e + chair fin"));
	}
	
}

//**************** Pick up and down ****************//

void AMainCharacter::ToggleItemPickup(APickUp* CurrentFood) //Pick up item
{
	if (CurrentFood != nullptr)
	{
		CurrentFood->SetIsPickUp(true);
		CurrentFood->MyMesh->SetEnableGravity(false);
		CurrentFood->MyMesh->SetSimulatePhysics(false);
		CurrentFood->MyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		CurrentFood->AttachToComponent(TriggerCapsule, FAttachmentTransformRules::KeepWorldTransform);
		CurrentFood->SetActorLocation(GetActorLocation() + 40* GetActorForwardVector() + FVector(0,0,-30));
		CurrentFood->SetActorScale3D(FVector(0.25,0.25,0.25));
		CurrentFood->SetActorRotation(FRotator(0,-45,0));
	}
}

void AMainCharacter::ToggleItemDropDown(APickUp* CurrentFood) //drop Item
{
	if (CurrentFood != nullptr)
	{
		CurrentFood->SetIsPickUp(false);
		CurrentFood->MyMesh->SetEnableGravity(true);
		CurrentFood->MyMesh->SetSimulatePhysics(true);
		CurrentFood->MyMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		CurrentFood->DetachRootComponentFromParent(true);
		CurrentFood->SetActorLocation(GetActorLocation() +110* GetActorForwardVector()); 
		CurrentFood->SetActorRotation(GetActorRotation()+FRotator(0,0,0));
		CurrentFood->SetActorScale3D(FVector(0.5,0.5,0.5));
	}
}

void AMainCharacter::ToggleItemPickupSpot(ASpotFood* CurrentSpot, APickUp* CurrentFood) // take the food on the spot
{
	if (CurrentFood != nullptr && CurrentSpot !=nullptr)
	{

		CurrentSpot->SetHaveFood(false);
		CurrentFood->SetIsPickUp(true);
		CurrentFood->AttachToComponent(TriggerCapsule, FAttachmentTransformRules::KeepWorldTransform);
		CurrentFood->SetActorLocation(GetActorLocation() + 40* GetActorForwardVector() + FVector(0,0,-30));
		CurrentFood->SetActorScale3D(FVector(0.25,0.25,0.25));
		CurrentFood->SetActorRotation(FRotator(0,-45,0));
	}
}

void AMainCharacter::ToggleItemDropDownSpot(ASpotFood* CurrentSpot, APickUp* CurrentFood) // Put the food on the spot
{
	if (CurrentFood != nullptr && CurrentSpot !=nullptr)
	{
		CurrentFood->DetachRootComponentFromParent(true);

		CurrentSpot->SetHaveFood(true);
		CurrentFood->SetIsPickUp(false);
	
		CurrentFood->MyMesh->SetEnableGravity(false);
		CurrentFood->MyMesh->SetSimulatePhysics(false);
		CurrentFood->MyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		CurrentFood->SetActorLocation(CurrentSpot->GetSpotFoodLocation() + FVector(0,0,10));
		CurrentFood->SetActorScale3D(FVector(0.75,0.75,0.75));
		CurrentFood->SetActorRotation(FRotator(0,0,0));
		CurrentSpotFood=CurrentSpot;
	}
}

//**************** Sit Down ****************//

void AMainCharacter::SitDownCharacter()
{
	if(CurrentChair != nullptr && !IsSitting())
	{
		this -> SetActorLocation( CurrentChair->GetActorLocation() + FVector(0,75,100) );
		this -> SetActorRotation( FRotator(0,90,0));
		//GetWorld()->GetFirstPlayerController()->ServerCamera(GetViewModeName());
		SetIsSitting(true);
		
	}
}
void AMainCharacter::SitUpCharacter()
{
	if(IsSitting())
	{
		SetIsSitting(false);
	}
}

//********************************** MOVE ************************************************//


void AMainCharacter::MoveForward(float Value)
{
	if (!IsSitting())
	{
		if (IsCarrying())
		{
			Value = Value / 2.0;
		}
		if (Controller != nullptr && Value != 0.0) {
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator Yaw(0, Rotation.Yaw, 0);
			const FVector direction = FRotationMatrix(Yaw).GetUnitAxis(EAxis::X);
			AddMovementInput(direction, Value);
		}
	}
}

void AMainCharacter::MoveRight(float Value)
{
	if (!IsSitting())
	{
		if (IsCarrying())
		{
			Value = Value / 2.0;
		}
		if (Controller != nullptr && Value != 0.0) {
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator Yaw(0, Rotation.Yaw, 0);
			const FVector direction = FRotationMatrix(Yaw).GetUnitAxis(EAxis::Y);
			AddMovementInput(direction, Value);
		}
	}
}

void AMainCharacter::TurnAtRate(float Rate)
{
	if (!IsSitting())
	{
		AddControllerYawInput(Rate * GetWorld()->GetDeltaSeconds() * CameraTurnRate);
	}
}

void AMainCharacter::LookUpAtRate(float Rate)
{
	if (!IsSitting())
	{
		AddControllerPitchInput(Rate * GetWorld()->GetDeltaSeconds() * CameraTurnRate);
	}
}

void AMainCharacter::ZoomInOut(float Value)
{
	if (Value != 0)
		BoomArm->TargetArmLength = UKismetMathLibrary::FClamp(BoomArm->TargetArmLength + -Value * ZoomRate, 200, 800);
}

void AMainCharacter::Num1Pressed()
{
	GameModeBase->Victory();
}

void AMainCharacter::Num2Pressed()
{
	GameModeBase->Defeat();
}

void AMainCharacter::Num3Pressed()
{
	GameModeBase->AddFood();
}

bool AMainCharacter::IsCarrying()
{
	return bCarrying;
}

void AMainCharacter::SetIsCarrying(bool Value)
{
	bCarrying = Value;
}
bool AMainCharacter::IsSitting()
{
	return bSitDown;
}

void AMainCharacter::SetIsSitting(bool Value)
{
	bSitDown = Value;
}