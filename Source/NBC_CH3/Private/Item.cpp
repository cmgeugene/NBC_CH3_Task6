
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
	SetActorScale3D(FVector(2.0f, 1.0f, 2.0f));		// y�� ,  z��,  x��
	SetActorScale3D(FVector(2.0f));					// ��ü �����ϵ� ����

	//FVector NewLocation(300.0f, 200.0f, 100.0f);	// ���� ������ �����̼�, �����̼�, ������ ����
	//FRotator NewRotation(0.0f, 90.0f, 0.0f);
	//FVector NewScale(2.0f);

	//FTransform NewTransform(NewRotation, NewLocation, NewScale);	// �� �������� Ʈ������ ������ ��ħ
	//SetActorTransform(NewTransform);								// Ʈ���������� �� ���� ����
}													

void AItem::Tick(float Deltatime)
{	
	
	// Deltatime = 1�ʸ� ���������� ���� �ð� = �� �����Ӹ��� �ɸ��� �ð�
	// �������� ���� ȯ�渶�� �ٸ���, deltatime�� ���Ͽ� ���� �ð��� ������ ����� �򵵷� �ϴ� ��

	Super::Tick(Deltatime);
	
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * Deltatime, 0.0f));
	}
	
}

