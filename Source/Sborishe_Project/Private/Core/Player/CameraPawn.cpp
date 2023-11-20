// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Player/CameraPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<UStaticMeshComponent>("DefaultSceneRootComponent");

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->TargetArmLength = 700;
	SpringArmComponent->SetupAttachment(SceneComponent);
	SpringArmComponent->SetCollisionProfileName(FName(TEXT("NoCollision")));

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	bUseControllerRotationYaw = true;


}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();

	NextCameraLocation = GetActorLocation();
	NextCameraZoomPosition = SpringArmComponent->TargetArmLength;
	
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveCameraHorizontal", this, &ACameraPawn::MoveCameraHorizontal);
	PlayerInputComponent->BindAxis("MoveCameraVertical", this, &ACameraPawn::MoveCameraVertical);
	PlayerInputComponent->BindAxis("CameraZoom", this, &ACameraPawn::CameraZoom);
	PlayerInputComponent->BindAxis("TurnCamera", this, &ACameraPawn::TurnCamera);
	PlayerInputComponent->BindAction("CameraRotate", IE_Pressed, this, &ACameraPawn::StartCameraRotate);
	PlayerInputComponent->BindAction("CameraRotate", IE_Released, this, &ACameraPawn::StopCameraRotate);
}

void ACameraPawn::MoveCameraHorizontal(float Amount)
{	
	ThisDeltaTime = GetWorld()->GetDeltaSeconds();
	NextCameraLocation = Amount * MoveSpeedCamera * GetActorRightVector() + NextCameraLocation;
	const FVector NewCameraLocation = FMath::VInterpTo(GetActorLocation(), NextCameraLocation, ThisDeltaTime, 2);
	SetActorLocation(NewCameraLocation);
}

void ACameraPawn::MoveCameraVertical(float Amount)
{
	ThisDeltaTime = GetWorld()->GetDeltaSeconds();
	NextCameraLocation = Amount * MoveSpeedCamera * GetActorForwardVector() + NextCameraLocation;
	const FVector NewCameraLocation = FMath::VInterpTo(GetActorLocation(), NextCameraLocation, ThisDeltaTime, 2);
	SetActorLocation(NewCameraLocation);
}

void ACameraPawn::CameraZoom(float Amount)
{
	ThisDeltaTime = GetWorld()->GetDeltaSeconds();
	NextCameraZoomPosition = Amount * SpeedZoomCamera * SpringArmComponent->TargetArmLength;
	const float NewCameraZoomPosition = SpringArmComponent->TargetArmLength + NextCameraZoomPosition;
	SpringArmComponent->TargetArmLength = FMath::FInterpTo(SpringArmComponent->TargetArmLength, FMath::Clamp(NewCameraZoomPosition, 300.f, 1000.f), ThisDeltaTime, 10);
}

void ACameraPawn::StartCameraRotate()
{
	isCameraRotate = true;
}

void ACameraPawn::StopCameraRotate()
{
	isCameraRotate = true;
}

void ACameraPawn::TurnCamera(float Amount)
{
	ThisDeltaTime = GetWorld()->GetDeltaSeconds();
	NextCameraRotation = Amount * RotationSpeedCamera * GetActorRotation() + NextCameraRotation;
	const FRotator NewCameraRotation = FMath::RInterpTo(GetActorRotation(), NextCameraRotation, ThisDeltaTime, 1);
	SetActorRotation(NewCameraRotation);
}


