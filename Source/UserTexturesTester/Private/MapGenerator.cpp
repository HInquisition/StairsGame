// Fill out your copyright notice in the Description page of Project Settings.


#include "MapGenerator.h"
#include "FloorManager.h"
#include <UserTexturesTester/Public/Enums.h>
#include "Floor.h"


// Sets default values
AMapGenerator::AMapGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMapGenerator::GenerateMap()
{
	const FActorSpawnParameters SpawnParams;
	FVector Location = FVector(0,0,0);


	for (size_t i = 0; i < NumOfFloors; i++)
	{
		//GetWorld()->SpawnActor(ManagerToSpawn, Location, Rotation, SpawnParams);
		AFloorManager* Manager = GetWorld()->SpawnActor<AFloorManager>(ManagerToSpawn,SpawnParams);
		FloorManagers.Add(Manager);
		Manager->FloorNumber = i;
		

		Manager->FloorType = FloorTypes["Standart"];

		

		if (i % 7 == 0 && i != 0) {
			//Manager->FloorType = FloorTypes["Sus"];
		}
		if (i % 4 == 0 && i != 0) {
			//Manager->FloorType = FloorTypes["StandartWithEnemy"];
		}

		
	}
	
	FloorManagers[0]->FloorType = FloorTypes["Start"];
	FloorManagers[49]->FloorType = FloorTypes["Respawn"];
	FloorManagers[99]->FloorType = FloorTypes["Respawn"];
	FloorManagers[149]->FloorType = FloorTypes["End"];

	
	SetFloorTypeSafe(rand() % 8 + 15, "ShadowScreamer");
	SetFloorTypeSafe(rand() % 20 + 30, "ShadowScreamer");
	SetFloorTypeSafe(rand() % 40 + 60, "Shadow");
	SetFloorTypeSafe(rand() % 40 + 60, "Shadow");
	SetFloorTypeSafe(rand() % 40 + 100, "Shadow");
	SetFloorTypeSafe(rand() % 10 + 100, "EnemyBack");
	SetFloorTypeSafe(rand() % 40 + 50, "EnemyBack");
	SetFloorTypeSafe(rand() % 40 + 100, "Mannequin");
	SetFloorTypeSafe(rand() % 40 + 70, "Shy");
	SetFloorTypeSafe(rand() % 10 + 55, "Shy");
	SetFloorTypeSafe(rand() % 40 + 100, "Shy");
	SetFloorTypeSafe(rand() % 20 + 60, "StandartWithEnemy");
	SetFloorTypeSafe(rand() % 40 + 60, "StandartWithEnemy");
	SetFloorTypeSafe(rand() % 40 + 100, "StandartWithEnemy");

	SetFloorTypeSafe(1, "Test");


	SetFloorTypeSafe(rand() % 20 + 25, "CP");
	SetFloorTypeSafe(rand() % 40 + 50, "CP");
	SetFloorTypeSafe(rand() % 20 + 100, "CP");
	SetFloorTypeSafe(rand() % 10 + 5, "Blocked");
	SetFloorTypeSafe(rand() % 20 + 25, "Blocked");
	SetFloorTypeSafe(rand() % 20 + 50, "Blocked");
	SetFloorTypeSafe(rand() % 30 + 90, "Blocked");
	SetFloorTypeSafe(rand() % 10 + 20, "Holes");
	SetFloorTypeSafe(rand() % 20 + 60, "Holes");
	SetFloorTypeSafe(rand() % 50 + 50, "Hook");
	
	SetFloorTypeSafe(rand() % 30 + 10, "Walls1");
	SetFloorTypeSafe(rand() % 40 + 50, "Walls1");
	SetFloorTypeSafe(rand() % 40 + 50, "Walls2");
	SetFloorTypeSafe(rand() % 40 + 100, "Walls2");
	SetFloorTypeSafe(rand() % 40 + 100, "Walls2");

	SetFloorTypeSafe(rand() % 30 + 40, "Chairs");
	SetFloorTypeSafe(rand() % 30 + 50, "Food");
	SetFloorTypeSafe(rand() % 30 + 90, "Food");
	SetFloorTypeSafe(rand() % 25 + 25, "DeadExpidition");
	SetFloorTypeSafe(rand() % 20 + 50, "DeadPig");
	SetFloorTypeSafe(rand() % 8 + 35, "Deer1");
	//SetFloorTypeSafe(rand() % 10 + 65, "Deer1");
	SetFloorTypeSafe(rand() % 20 + 75, "Deer2");

	// Floor Type Selected
	for (size_t i = 0; i < NumOfFloors; i++)
	{
		AFloorManager* Manager = FloorManagers[i];
		Location[2] -= (Manager->GenerateFloor(Location))[2];

		if (i < 11) {
			Manager->FloorRef->FloorLightingType = WellLighted;
		}
		else {
			if (rand() % 5 == 0) { Manager->FloorRef->FloorLightingType = BadLighted; }
			else if (rand() % 8 == 0) { Manager->FloorRef->FloorLightingType = PartiallyLighted; }
		}
		Manager->OffsetZ = -Location[2];
	}

}

// Called when the game starts or when spawned
void AMapGenerator::BeginPlay()
{
	Super::BeginPlay();
	GenerateMap();
}


void AMapGenerator::SetFloorTypeSafe(int index, FString Type)
{
	if(FloorManagers.IsValidIndex(index) && FloorTypes.Contains(Type)){
		if (FloorManagers[index]->FloorType == FloorTypes["Standart"]) {
			FloorManagers[index]->FloorType = FloorTypes[Type];
		}
		else {
			SetFloorTypeSafe(index + 1, Type);
		}
	}
	else {
		if(!FloorManagers.IsValidIndex(index)){
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "FUCK INDEX");
			UE_LOG(LogTemp, Warning, TEXT("FUCK INDEX"));
		}
		if (!FloorTypes.Contains(Type)) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "FUCK TYPE");
			UE_LOG(LogTemp, Warning, TEXT("FUCK TYPE"));
		}
	}
}

// Called every frame
void AMapGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<AFloorManager*> AMapGenerator::GetManagersArray()
{
	return FloorManagers;
}


