// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Engine/Engine.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();




protected:
	// Called when the game starts
	virtual void BeginPlay() override;




public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		


private:
	
	UPROPERTY(EditAnywhere)
	float Reach = 100;

	UInputComponent* InputComponent = nullptr;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	void Grab();
	void Release();
	void AttachInputComponent();
	void AttachPhysicsHandle();

	FVector ReturnTraceLineStart();
	FVector ReturnTraceLineEnd();
	FHitResult ReturnFirstTracePhysicsObject();
};
