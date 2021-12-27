// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapGenerator.generated.h"

class AFloorManager;
class AFloor;

UCLASS()
class AMapGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapGenerator();
	void GenerateMap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	int NumOfFloors = 20;

	UPROPERTY(EditDefaultsOnly)
	TMap<FString, TSubclassOf<AFloor>> FloorTypes;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AFloorManager> ManagerToSpawn;

	UFUNCTION()
	void SetFloorTypeSafe(int index, FString Type);

	//UClass ManagerToSpawn;

	UPROPERTY(BlueprintReadOnly, BlueprintGetter=GetManagersArray)
	TArray<AFloorManager*> FloorManagers;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintGetter)
	TArray<AFloorManager*> GetManagersArray();

};
