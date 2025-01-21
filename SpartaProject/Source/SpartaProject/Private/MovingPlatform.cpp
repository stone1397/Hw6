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
	// 생성자가 아닌 BeginPlay()에서 초기화 하는 것이 안전
	FirstLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FMath::IsNearlyZero(MovingSpeed))
	{
		return; // 이동속도가 0일 경우 로직 중단
	}
	const FVector CurrentLocation = GetActorLocation();
	if ((FirstLocation.Y + MovingRange <= CurrentLocation.Y) || (FirstLocation.Y - MovingRange >= CurrentLocation.Y))
	{
		MovingSpeed = -MovingSpeed; // 방향 반전
	}	

	AddActorLocalOffset(FVector(0, MovingSpeed * DeltaTime, 0)); // 이동
}



