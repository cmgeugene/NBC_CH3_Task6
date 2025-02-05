// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerActor.h"

ATimerActor::ATimerActor()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(RootComp);
	TogglePhysics = StaticMeshComp->IsSimulatingPhysics();	// SimulatePhysics�� ���� ���¸� bool�� ��ȯ
	ToggleVisibility = StaticMeshComp->IsVisible();			// Visible�� ���� ���¸� bool�� ��ȯ
	TimerTerm = 3;
}

void ATimerActor::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(Timer, this, &ATimerActor::ToggleVisiblityandPhysics, TimerTerm, true);

}

void ATimerActor::ToggleVisiblityandPhysics()
{
	// ȣ��ø��� �÷��װ� ����, ������ ���¸� ������.
	TogglePhysics = !TogglePhysics;
	ToggleVisibility = !ToggleVisibility;
	StaticMeshComp->SetVisibility(!ToggleVisibility);
	StaticMeshComp->SetSimulatePhysics(!TogglePhysics);
}

void ATimerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

