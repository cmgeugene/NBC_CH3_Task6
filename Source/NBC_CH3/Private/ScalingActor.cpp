// Fill out your copyright notice in the Description page of Project Settings.


#include "ScalingActor.h"

// Sets default values
AScalingActor::AScalingActor()
{
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(RootComp);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ScalingSpeed = FVector(0.0f, 0.0f, 0.0f);
	MaximumScale = FVector(0.0f, 0.0f, 0.0f);
	MinimumScale = FVector(1.0f, 1.0f, 1.0f);	// 최소 스케일 1 고정
	bIsIncreasing = true;
	bCanTransforming = true;
}

// Called when the game starts or when spawned
void AScalingActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(300.0f, 300.0f, 300.0f));
}

// Called every frame
void AScalingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bCanTransforming)
	{
		FVector CurrentScale = GetActorScale3D();
		if (bIsIncreasing && CurrentScale.X <= MaximumScale.X)
		{
			CurrentScale += ScalingSpeed * DeltaTime;
			SetActorScale3D(CurrentScale);
			if (CurrentScale.X >= MaximumScale.X) { bIsIncreasing = false; }
		}
		else if (!bIsIncreasing && CurrentScale.X >= MinimumScale.X)
		{
			CurrentScale -= ScalingSpeed * DeltaTime;
			SetActorScale3D(CurrentScale);
			if (CurrentScale.X <= MinimumScale.X) { bIsIncreasing = true; }
		}
	}
}

