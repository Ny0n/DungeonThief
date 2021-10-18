// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "PickUp.h"
#include "Knight_Animation.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
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
	//HoldingComponent->RelativeLocation.X = 50.0f;
	HoldingComponent->SetupAttachment(HoldingComponent);

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

}

void AMainCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{

	if (!bHoldingItem)
	{		
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
	PlayerInputComponent->BindAxis("Animation", this, &AMainCharacter::ButtonPressed);

	// Bind action event
	PlayerInputComponent->BindAction("Action_E", IE_Pressed, this, &AMainCharacter::OnAction);

}

void AMainCharacter::ToggleItemPickup()
{
	if (CurrentItem)
	{
		bHoldingItem = !bHoldingItem;
		CurrentItem->PickUp();

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
		UE_LOG(LogTemp, Warning, TEXT("OnAction"));
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

void AMainCharacter::ButtonPressed(float Value)
{
	if (Value != 0)
	{
		UKnight_Animation* KnightAnim = Cast<UKnight_Animation>(GetMesh()->GetAnimInstance());
		if (IsValid(KnightAnim)) KnightAnim->PlayVictoryAnimation();
	}
}
