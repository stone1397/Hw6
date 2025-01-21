// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class SPARTAPROJECT_API ARotatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "RotatingPlatform|Component")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "RotatingPlatform|Component")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "RotatingPlatform|Property")
	float RotatingSpeed;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
