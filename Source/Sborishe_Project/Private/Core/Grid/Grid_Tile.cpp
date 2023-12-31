// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Grid/Grid_Tile.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AGrid_Tile::AGrid_Tile()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComp");
	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>("TileMesh");
	TileMesh->SetupAttachment(RootComponent);
}

