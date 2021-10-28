// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "PickUp.generated.h"

UCLASS()
class GC_UE4CPP_API APickUp : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	APickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MyMesh;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UBoxComponent* BoxMesh;

	UFUNCTION()
	bool GetIsPickUP();

	UFUNCTION()
	void SetIsPickUp(bool BPickUp);
	
private:
	bool IsPickUp = false;
	
};
