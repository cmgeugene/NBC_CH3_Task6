// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerActor.h"

ATimerActor::ATimerActor()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(RootComp);
	TogglePhysics = StaticMeshComp->IsSimulatingPhysics();	// SimulatePhysics의 현재 상태를 bool로 반환
	ToggleVisibility = StaticMeshComp->IsVisible();			// Visible의 현재 상태를 bool로 반환
	TimerTerm = 3;
}

void ATimerActor::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(Timer, this, &ATimerActor::ToggleVisiblityandPhysics, TimerTerm, true);

}

void ATimerActor::ToggleVisiblityandPhysics()
{
	// 호출시마다 플래그가 반전, 반전된 상태를 적용함.
	TogglePhysics = !TogglePhysics;
	ToggleVisibility = !ToggleVisibility;
	StaticMeshComp->SetVisibility(!ToggleVisibility);
	StaticMeshComp->SetSimulatePhysics(!TogglePhysics);
}

void ATimerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

