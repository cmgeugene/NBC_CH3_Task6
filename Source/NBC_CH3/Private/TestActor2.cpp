// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor2.h"

// Sets default values
ATestActor2::ATestActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(RootComp);
	RotationSpeed = 0.0f;
	MovingSpeed = 0.0f;
	NewScale = FVector(2.0f);
	bIsIncreasing = true;
	/*FVector NewLocation(0.0f, 0.0f, 0.0f);
	FRotator NewRotation(0.0f, 0.0f, 0.0f);*/
}

// Called when the game starts or when spawned
void ATestActor2::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(100.0f, 100.0f, 100.0f));	
	
	
}

// Called every frame
void ATestActor2::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(MovingSpeed))
	{
		AddActorLocalOffset(FVector(0.0f, 0.0f, RotationSpeed * DeltaTime));
		FVector CurrentScale = GetActorScale3D();
		FVector MaximumScale = FVector(3.0f, 3.0f, 3.0f);
		FVector MinimumScale = FVector(1.0f, 1.0f, 1.0f);
		if (bIsIncreasing && CurrentScale.X <= MaximumScale.X && CurrentScale.Y <= MaximumScale.Y && CurrentScale.Z <= MaximumScale.Z) {
			CurrentScale += NewScale * DeltaTime;
			SetActorScale3D(CurrentScale);
			if (CurrentScale.X >= MaximumScale.X) { bIsIncreasing = false; }
		}
		else if (!bIsIncreasing && CurrentScale.X >= MinimumScale.X && CurrentScale.Y >= MinimumScale.Y && CurrentScale.Z >= MinimumScale.Z)
		{
			CurrentScale -= NewScale * DeltaTime;
			SetActorScale3D(CurrentScale);
			if (CurrentScale.X <= MinimumScale.X) { bIsIncreasing = true; }
		}
	}
}

