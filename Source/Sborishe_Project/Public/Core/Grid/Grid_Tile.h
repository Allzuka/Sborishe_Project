 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid_Tile.generated.h"

UENUM()
enum class Tile_Type : uint8
{
	INVALID,
	GRASS,
	WATER,
	MAX UMETA(Hidden)
};

class UStaticMeshComponent;

UCLASS()
class SBORISHE_PROJECT_API AGrid_Tile : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tile")
		Tile_Type TileType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tile")
		UStaticMeshComponent* TileMesh;

public:	
	// Sets default values for this actor's properties
	AGrid_Tile();


};
