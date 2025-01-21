// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FadeOutPlatform.generated.h"

UCLASS()
class SPARTAPROJECT_API AFadeOutPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFadeOutPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FadeOutPlatform|Component")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FadeOutPlatform|Component")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FadeOutPlatform|Property")
	float TimeLimit;

	FTimerHandle FadeOutHandle;

	void FadeOut();




public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
