
#include "SpawnActor.h"
#include "Components/BoxComponent.h"


ASpawnActor::ASpawnActor()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);
	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
	SpawnVolume->SetupAttachment(RootComp);
	MaxLocation = FVector(0.0f, 0.0f, 0.0f);
	MinLocation = FVector(0.0f, 0.0f, 0.0f);
	MaxRotation = FRotator(0.0f, 0.0f, 0.0f);
	MinRotation = FRotator(0.0f, 0.0f, 0.0f);
	SpawnAmount = 0;
	ShouldSpawnActors = true;
}

void ASpawnActor::BeginPlay()
{
	Super::BeginPlay();
	if (ShouldSpawnActors)
	{
		for (int i = 0; i < SpawnAmount; ++i) { SpawnActor(); }
	}
}

void ASpawnActor::SpawnActor()
{
	FVector SpawnLocation = FVector(FMath::RandRange(MinLocation.X, MaxLocation.X), 
									FMath::RandRange(MinLocation.Y, MaxLocation.Y), 
									FMath::RandRange(MinLocation.Z, MaxLocation.Z));
	FRotator SpawnRotation = FRotator(FMath::FRandRange(MinRotation.Pitch, MaxRotation.Pitch), 
									  FMath::FRandRange(MinRotation.Yaw, MaxRotation.Yaw), 
									  FMath::FRandRange(MinRotation.Roll, MaxRotation.Roll));
	
	GetWorld()->SpawnActor<AActor>(ActorToSpawn, SpawnLocation, SpawnRotation);
}

void ASpawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

