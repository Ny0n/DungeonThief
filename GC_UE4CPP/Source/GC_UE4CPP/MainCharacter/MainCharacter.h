// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GC_UE4CPP/GC_UE4CPPGameModeBase.h"
#include "GC_UE4CPP/Food/PickUp.h"
#include "GC_UE4CPP/Food/SpotFood.h"
#include "GC_UE4CPP/Props/ChairAction.h"
#include "GC_UE4CPP/UI/FoodProgressBar.h"
#include "GC_UE4CPP/UI/InterfaceCreation.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "MainCharacter.generated.h"

UCLASS()
class GC_UE4CPP_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	// Anim blueprint variables
	bool bCarrying = false;
	bool bSitDown = false;
	bool bMove = false;

	UPROPERTY(EditAnywhere)
	class APickUp* CurrentItem;

	UPROPERTY(EditAnywhere)
	class ASpotFood* CurrentSpotFood;

	UPROPERTY(EditAnywhere)
	class AChairAction* CurrentChair;

	bool IsCarrying();
	void SetIsCarrying(bool Take);
	bool IsSitting();
	void SetIsSitting(bool Take);

	void ToggleItemDropDown(APickUp* CurrentFood); // public so that the GameModeBase can access it

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* BoomArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraChair;

	UPROPERTY(EditAnywhere)
	float CameraTurnRate = 150;

	UPROPERTY(EditAnywhere)
	float ZoomRate = 25;

	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
	class UCapsuleComponent* TriggerCapsule;

	UPROPERTY()
	AGC_UE4CPPGameModeBase* GameModeBase;

	UPROPERTY()
	AInterfaceCreation* HUDBase;

	UPROPERTY()
	UAIPerceptionStimuliSourceComponent* StimulusComponent; // AI detection

	// Called to bind functionality to input

	bool bTouchItem = false;
	bool bTouchSpot = false;
	bool bChair = false;
	
	FVector HoldingComp;
	FVector Start;
	FVector ForwardVector;
	FVector End;

	// input action functions
	void Num1Pressed();
	void Num2Pressed();
	void Num3Pressed();
	
	void OnAction();

	void MoveForward(float Value);
	void MoveRight(float Value);

	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);
	void ZoomInOut(float Value);

	// toggle chair
	void SitDownCharacter();
	void SitUpCharacter();

	// toggle holding item pickup
	void ToggleItemPickup(APickUp* CurrentFood);
	void ToggleItemPickupSpot(ASpotFood* CurrentSpot, APickUp* CurrentFood);
	void ToggleItemDropDownSpot(ASpotFood* CurrentSpot, APickUp* CurrentFood);

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
	
	void SetupStimuli();
};
