// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Unit_Base.generated.h"

UCLASS()
class SBORISHE_PROJECT_API AUnit_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnit_Base();

protected:


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tile")
		UStaticMeshComponent* Base_Mesh;

};
