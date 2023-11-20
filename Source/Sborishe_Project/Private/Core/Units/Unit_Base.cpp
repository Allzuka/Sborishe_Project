// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Units/Unit_Base.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AUnit_Base::AUnit_Base()
{

	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComp");
	Base_Mesh = CreateDefaultSubobject<UStaticMeshComponent>("TileMesh");
	Base_Mesh->SetupAttachment(RootComponent);

}


