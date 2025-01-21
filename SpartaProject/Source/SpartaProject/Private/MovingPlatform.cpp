// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_AssetPlatform.SM_AssetPlatform"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MovingSpeed = 100.0f;
	MovingRange = 500.0f;
	
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	// �����ڰ� �ƴ� BeginPlay()���� �ʱ�ȭ �ϴ� ���� ����
	FirstLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FMath::IsNearlyZero(MovingSpeed))
	{
		return; // �̵��ӵ��� 0�� ��� ���� �ߴ�
	}
	const FVector CurrentLocation = GetActorLocation();
	if ((FirstLocation.Y + MovingRange <= CurrentLocation.Y) || (FirstLocation.Y - MovingRange >= CurrentLocation.Y))
	{
		MovingSpeed = -MovingSpeed; // ���� ����
	}	

	AddActorLocalOffset(FVector(0, MovingSpeed * DeltaTime, 0)); // �̵�
}



