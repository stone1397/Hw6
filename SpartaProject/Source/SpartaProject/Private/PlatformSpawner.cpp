// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformSpawner.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
APlatformSpawner::APlatformSpawner()
{
 	//Tick �� ���� �Ŵϱ� ��Ȱ��ȭ
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APlatformSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	for (int32 i = 0; i < NumberOfPlatformsToSpawn; i++)
	{
		SpawnRandomPlatforn();
	}
}

void APlatformSpawner::SpawnRandomPlatforn()
{
	// �÷��� Ŭ���� �迭�� ����ִ��� Ȯ�� -> ������� ��� �Լ� ����
	if (PlatformClasses.Num() == 0)
	{
		return;
	}

	// �������� �ε��� ���� �� Ŭ���� ����
	int32 RandomIndex = FMath::RandRange(0, PlatformClasses.Num() - 1);
	TSubclassOf<AActor> SelectedClass = PlatformClasses[RandomIndex];

	// ������ �ε��� ���ο� Platform�� ���� ��� -> �Լ� ����
	if (!SelectedClass)
	{
		return;
	}
	
	// ��ġ�� ȸ���� �������� �ʱ�ȭ
	FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(SpawnAreaMin,SpawnAreaMax);
	FRotator SpawnRotation = FRotator(0.0f, FMath::RandRange(0.0f, 360.0f), 0.0f);
	FActorSpawnParameters SpawnParams;

	// ���� ����
	AActor* SpawnedPlatform = GetWorld()->SpawnActor<AActor>(
		SelectedClass,
		FTransform(SpawnRotation, SpawnLocation),
		SpawnParams
	);

	if (!SpawnedPlatform)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to spawn platform"));
	}
}



