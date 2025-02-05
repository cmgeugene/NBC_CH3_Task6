// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor2.generated.h"

UCLASS()
class NBC_CH3_API ATestActor2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item|TransformSpeed")
	float RotationSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item|TransformSpeed")
	float MovingSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item|ActorTransform")
	FVector NewScale;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* RootComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;
	bool bIsIncreasing;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

};
