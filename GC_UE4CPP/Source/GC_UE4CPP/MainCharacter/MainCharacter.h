// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GC_UE4CPP/GC_UE4CPPGameModeBase.h"
#include "GC_UE4CPP/Food/PickUp.h"
#include "GC_UE4CPP/Food/SpotFood.h"
#include "GC_UE4CPP/UI/FoodProgressBar.h"
#include "GC_UE4CPP/UI/InterfaceCreation.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "MainCharacter.generated.h"

UCLASS()
class GC_UE4CPP_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* BoomArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	float CameraTurnRate = 45;

	UPROPERTY(EditAnywhere)
	float ZoomRate = 25;

	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
		class UCapsuleComponent* TriggerCapsule;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	UPROPERTY()
	AGC_UE4CPPGameModeBase* GameModeBase;

	UPROPERTY()
	AInterfaceCreation* HUDBase;

public:
	// Sets default values for this character's properties
	AMainCharacter();

	void Num1Pressed();
	void Num2Pressed();
	void Num3Pressed();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float horizontal = FInputAxisBinding("Horizontal_Axis").AxisValue;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void OnAction();

	void MoveForward(float Value);
	void MoveRight(float Value);

	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);
	void ZoomInOut(float Value);

	// toggle holding item pickup
	void ToggleItemPickup(APickUp* CurrentFood);

	void ToggleItemDropDown(APickUp* CurrentFood);

	void ToggleItemPickupSpot(ASpotFood* CurrentSpot, APickUp* CurrentFood);

	void ToggleItemDropDownSpot(ASpotFood* CurrentSpot, APickUp* CurrentFood);

	bool IsCarrying();
	void SetIsCarrying(bool Take);

	UPROPERTY()
	UAIPerceptionStimuliSourceComponent* StimulusComponent;
	void SetupStimuli();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Called to bind functionality to input
	UPROPERTY(EditAnywhere)
	class APickUp* CurrentItem;

	UPROPERTY(EditAnywhere)
	class ASpotFood* CurrentSpotFood;

	bool bTouchItem = false;
	bool bTouchSpot = false;
	bool bCarrying = false;
	
	FVector HoldingComp;

	FVector Start;
	FVector ForwardVector;
	FVector End;
};
