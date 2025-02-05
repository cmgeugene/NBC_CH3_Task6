// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnActor.generated.h"

UCLASS()
class NBC_CH3_API ASpawnActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnActor();
	void SpawnActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	USceneComponent* RootComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings")
	class UBoxComponent* SpawnVolume;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings")
	TSubclassOf<AActor> ActorToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings|Location Range")
	FVector MaxLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings|Location Range")
	FVector MinLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings|Rotation Range")
	FRotator MaxRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings|Rotation Range")
	FRotator MinRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings")
	int SpawnAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings")
	bool ShouldSpawnActors;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
