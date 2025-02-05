
#include "Item.h"

DEFINE_LOG_CATEGORY(LogSparta);

// Sets default values
AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	AudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComp"));
	AudioComp->SetupAttachment(SceneRoot);

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	CollisionBox->SetupAttachment(StaticMeshComp);
	CollisionBox->SetBoxExtent(FVector(50.f, 50.f, 50.f));
	CollisionBox->SetRelativeLocation(FVector(0.f, 0.f, 50.f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Potion_A.SM_Potion_A"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Brick_Clay_New.M_Brick_Clay_New"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<USoundCue> AudioAsset(TEXT("/Game/Resources/Audio/Pickup_Coin_A_Cue.Pickup_Coin_A_Cue"));
	if (AudioAsset.Succeeded())
	{
		AudioComp->SetSound(AudioAsset.Object);
	}

	RotationSpeed = 90.0f;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(300.0f, 200.0f, 100.0f));
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));	// pitch, yaw, roll
	SetActorScale3D(FVector(2.0f, 1.0f, 2.0f));		// y축 ,  z축,  x축
	SetActorScale3D(FVector(2.0f));					// 전체 스케일도 가능

	//FVector NewLocation(300.0f, 200.0f, 100.0f);	// 각각 변수에 로케이션, 로테이션, 스케일 저장
	//FRotator NewRotation(0.0f, 90.0f, 0.0f);
	//FVector NewScale(2.0f);

	//FTransform NewTransform(NewRotation, NewLocation, NewScale);	// 그 변수들을 트랜스폼 변수에 합침
	//SetActorTransform(NewTransform);								// 트랜스폼에서 한 번에 설정
}													

void AItem::Tick(float Deltatime)
{	
	
	// Deltatime = 1초를 프레임으로 나눈 시간 = 각 프레임마다 걸리는 시간
	// 프레임은 각자 환경마다 다른데, deltatime을 곱하여 같은 시간에 동일한 결과를 얻도록 하는 것

	Super::Tick(Deltatime);
	
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * Deltatime, 0.0f));
	}
	
}

