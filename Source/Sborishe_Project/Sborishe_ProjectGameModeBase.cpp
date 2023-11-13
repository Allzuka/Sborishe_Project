// Copyright Epic Games, Inc. All Rights Reserved.


#include "Sborishe_ProjectGameModeBase.h"
#include "Core/Player/CameraPawn.h"
#include "Core/Player/Base_PlayerController.h"


ASborishe_ProjectGameModeBase::ASborishe_ProjectGameModeBase()
{
	DefaultPawnClass = ACameraPawn::StaticClass();
	PlayerControllerClass = ABase_PlayerController::StaticClass();

}
