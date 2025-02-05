// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "TimerActor.generated.h"

UCLASS()
class NBC_CH3_API ATimerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimerActor();
	void ToggleVisiblityandPhysics();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platform Settings")
	USceneComponent* RootComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	UStaticMeshComponent* StaticMeshComp;

	FTimerHandle Timer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	int TimerTerm;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	bool TogglePhysics;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	bool ToggleVisibility;
	
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
