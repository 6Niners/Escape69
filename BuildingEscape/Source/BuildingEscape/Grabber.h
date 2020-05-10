// Private Closed Project, sharing or editing the source code is prohibited 
//and will be faced with legal action, claiming the project is yours will end you up in jail.
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
	float Reach = 200;

	UInputComponent* InputComponent = nullptr;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UFUNCTION(BlueprintCallable)
	void UpdatePhysicsObjectLocation();

	UFUNCTION(BlueprintCallable)
	void Grab();

	UFUNCTION(BlueprintCallable)
	void Release();

	void AttachInputComponent();
	void AttachPhysicsHandle();

	UFUNCTION(BlueprintCallable)
	FVector ReturnTraceLineStart();

	UFUNCTION(BlueprintCallable)
	FVector ReturnTraceLineEnd();

	UFUNCTION(BlueprintCallable)
	FHitResult ReturnFirstTracePhysicsObject();
};
