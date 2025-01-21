// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformSpawner.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
APlatformSpawner::APlatformSpawner()
{
 	//Tick 안 써줄 거니까 비활성화
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
	// 플랫폼 클래스 배열이 비어있는지 확인 -> 비어있을 경우 함수 종료
	if (PlatformClasses.Num() == 0)
	{
		return;
	}

	// 랜덤으로 인덱스 설정 후 클래스 선택
	int32 RandomIndex = FMath::RandRange(0, PlatformClasses.Num() - 1);
	TSubclassOf<AActor> SelectedClass = PlatformClasses[RandomIndex];

	// 설정된 인덱스 내부에 Platform이 없을 경우 -> 함수 종료
	if (!SelectedClass)
	{
		return;
	}
	
	// 위치와 회전을 랜덤으로 초기화
	FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(SpawnAreaMin,SpawnAreaMax);
	FRotator SpawnRotation = FRotator(0.0f, FMath::RandRange(0.0f, 360.0f), 0.0f);
	FActorSpawnParameters SpawnParams;

	// 액터 생성
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



