// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(RootComp);

	bCanMove = true;
	bIsRepeated = true;
	OriginLocation = FVector(0.0f, 0.0f, 0.0f);
	MoveDistance = 0.0f;
	MovingVelocity = FVector(0.0f, 0.0f, 0.0f);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	OriginLocation = GetActorLocation();
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bCanMove)
	{
		float DistanceMoved = FVector::Dist(OriginLocation, GetActorLocation());
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation += (MovingVelocity * DeltaTime);
		if (DistanceMoved <= MoveDistance) 
		{
			SetActorLocation(CurrentLocation);
		}
		else if (bIsRepeated && DistanceMoved > MoveDistance)
		{
			MovingVelocity = -MovingVelocity;
			OriginLocation = GetActorLocation();
		}
		
	}
}

