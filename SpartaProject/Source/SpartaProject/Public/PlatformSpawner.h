// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformSpawner.generated.h"

UCLASS()
class SPARTAPROJECT_API APlatformSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SpawnRandomPlatforn();

	// Spawn�� Platform���� ���� (����, ����, ����)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlatformSpawner|Property")
	TArray<TSubclassOf<AActor>> PlatformClasses;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlatformSpawner|Property")
	int32 NumberOfPlatformsToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlatformSpawner|Property")
	FVector SpawnAreaMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlatformSpawner|Property")
	FVector SpawnAreaMax;
	

};
