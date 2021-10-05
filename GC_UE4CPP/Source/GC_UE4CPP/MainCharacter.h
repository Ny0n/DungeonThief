// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HoloLens/AllowWindowsPlatformTypes.h"
#include "MainCharacter.generated.h"

UCLASS()
class GC_UE4CPP_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* BoomArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
<<<<<<< HEAD
	float horizontal = FInputAxisBinding("Horizontal_Axis").AxisValue;
=======

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override; 

	void MoveForward(float Value);
	void MoveRight(float Value);

	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);

	float TurnRate;
	float LookRate;

>>>>>>> 304a1d3fd68ccafbbb9a0cbb39ba86b746b5b663
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input

};
