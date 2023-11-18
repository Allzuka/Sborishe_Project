// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Grid/Grid_Tile.h"

// Sets default values
AGrid_Tile::AGrid_Tile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGrid_Tile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrid_Tile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

