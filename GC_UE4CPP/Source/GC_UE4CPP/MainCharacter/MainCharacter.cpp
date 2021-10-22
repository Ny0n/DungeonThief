// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "PickUp.h"
#include "KnightAnimation.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GC_UE4CPP/GC_UE4CPPGameModeBase.h"
#include "GC_UE4CPP/UI/InterfaceCreation.h"
#include "Kismet/KismetMathLibrary.h"

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

	HoldingComponent = CreateDefaultSubobject<USceneComponent>(TEXT("HoldingComponent"));
	HoldingComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	HoldingComponent->SetupAttachment(RootComponent);

	bBeginPlay = false;
	CurrentItem = NULL;

	

	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule->InitCapsuleSize(55.f, 96.0f);;
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule->SetupAttachment(RootComponent);

	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &AMainCharacter::OnOverlapBegin);
	TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &AMainCharacter::OnOverlapEnd);

	
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

//**********************************************************************************//

void AMainCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{

	if (!bHoldingItem)
	{		
		CurrentItem = Cast<APickUp>(OtherActor);
		bBeginPlay = true; 
	}
	else
	{
		
		CurrentItem = NULL;
	}

	if (OtherActor && (OtherActor != this) && OtherComp) {
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("OverlapBegin"));
		}
	}
	

}

void AMainCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("OverlapEnd"));
		bBeginPlay = false; 
	}

}

void AMainCharacter::ToggleItemPickup()
{
	UE_LOG(LogTemp, Warning, TEXT("ToggleItemPickup"));
	if (CurrentItem)
	{
		UE_LOG(LogTemp, Warning, TEXT("bHoldingItem"));
		HoldingComp = TriggerCapsule->GetComponentLocation();
		
		bHolding = !bHolding;
		bGravity = !bGravity;

		CurrentItem->MyMesh->SetEnableGravity(bGravity);
		CurrentItem->MyMesh->SetSimulatePhysics(bHolding ? false : true);
		CurrentItem->MyMesh->SetCollisionEnabled(bHolding ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryAndPhysics);

		CurrentItem->AttachToComponent(TriggerCapsule, FAttachmentTransformRules::KeepWorldTransform);
		SetActorLocation(TriggerCapsule->GetComponentLocation());

		if (!bHoldingItem)
		{
			CurrentItem = NULL;
		}
	}
}

void AMainCharacter::OnAction()
{
	
	if (bBeginPlay)
	{
		
		ToggleItemPickup();
	}
}

void AMainCharacter::MoveForward(float Value)
{
	
	if (Controller != NULL && Value != 0.0) {
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator Yaw(0, Rotation.Yaw, 0);
		const FVector direction = FRotationMatrix(Yaw).GetUnitAxis(EAxis::X);
		AddMovementInput(direction, Value);
	}
}

void AMainCharacter::MoveRight(float Value)
{
	if (Controller != NULL && Value != 0.0) {
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator Yaw(0, Rotation.Yaw, 0);
		const FVector direction = FRotationMatrix(Yaw).GetUnitAxis(EAxis::Y);
		AddMovementInput(direction, Value);
	}
}

void AMainCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * GetWorld()->GetDeltaSeconds() * CameraTurnRate);
}

void AMainCharacter::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * GetWorld()->GetDeltaSeconds() * CameraTurnRate);
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
