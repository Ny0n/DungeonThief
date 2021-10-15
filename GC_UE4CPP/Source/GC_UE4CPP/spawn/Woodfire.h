// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PointLightComponent.h"
#include "GameFramework/Actor.h"

#include "Woodfire.generated.h"

UCLASS()
class GC_UE4CPP_API AWoodfire : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWoodfire();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RootMesh;
	
	UPROPERTY(EditAnywhere)
	UPointLightComponent* FireLight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
