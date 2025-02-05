// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScalingActor.generated.h"

UCLASS()
class NBC_CH3_API AScalingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScalingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	USceneComponent* RootComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Component")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item|Transform")
	FVector ScalingSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item|Transform")
	FVector MaximumScale;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Transform")
	FVector MinimumScale;
	bool bIsIncreasing;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item|Boolean")
	bool bCanTransforming;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
