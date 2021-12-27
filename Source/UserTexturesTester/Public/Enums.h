// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Enums.generated.h"

UENUM(BlueprintType)
enum EFloorLightingType{
	WellLighted UMETA(DisplayName = "Well Lighted"),
	PartiallyLighted UMETA(DisplayName = "Partially Lighted"),
	BadLighted UMETA(DisplayName = "Bad Lighted"),
	NotLighted UMETA(DisplayName = "Not Lighted")
};

UENUM(BlueprintType)
enum EMusicType {
	MainTheme UMETA(DisplayName = "MainTheme Music"),
	Peaceful UMETA(DisplayName = "Peaceful Music"),
	Danger UMETA(DisplayName = "Danger Music"),
	//NotLighted UMETA(DisplayName = "Not Lighted")
};