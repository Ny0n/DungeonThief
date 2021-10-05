// Fill out your copyright notice in the Description page of Project Settings.


#include "WoodfireComponent.h"

#include "Components/LightComponent.h"

// Sets default values for this component's properties
UWoodfireComponent::UWoodfireComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<ULightComponent>(FName("PointLight"));
	
	if (GetOwner() != nullptr)
	{
		UStaticMeshComponent* StaticMeshComponent = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
		PointLight->SetupAttachment(StaticMeshComponent);
	}
}


// Called when the game starts
void UWoodfireComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWoodfireComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

