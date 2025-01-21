// Fill out your copyright notice in the Description page of Project Settings.


#include "FadeOutPlatform.h"

// Sets default values
AFadeOutPlatform::AFadeOutPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_AssetPlatform.SM_AssetPlatform"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	TimeLimit = 5.0f;
}

// Called when the game starts or when spawned
void AFadeOutPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	// TimeLimit 이후 Destroy 호출
	GetWorldTimerManager().SetTimer(
		FadeOutHandle,
		this,
		&AFadeOutPlatform::FadeOut,
		TimeLimit,
		false
	);
}

// Called every frame
void AFadeOutPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void  AFadeOutPlatform::FadeOut()
{
	Destroy();
}
