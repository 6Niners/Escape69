// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "Escape69_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BUILDINGESCAPE_API UEscape69_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	

public:
	
	UEscape69_GameInstance(const FObjectInitializer& ObjectInitializer);


private:

	UFUNCTION(Exec)
	void HostServer();

	UFUNCTION(Exec)
	void JoinServer(FString IP);

};
