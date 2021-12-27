// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <UserTexturesTester/Public/Enums.h>
#include "Floor.generated.h"

enum EFloorLightingType;

UCLASS()
class USERTEXTURESTESTER_API AFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloor();

	UPROPERTY(BlueprintReadWrite)
	TEnumAsByte<EFloorLightingType> FloorLightingType = NotLighted;

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent)
	FVector GetFloorSize();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
