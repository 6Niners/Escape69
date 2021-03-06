// Private Closed Project, sharing or editing the source code is prohibited 
//and will be faced with legal action, claiming the project is yours will end you up in jail.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "Engine/World.h"
#include "DoorRotate.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UDoorRotate : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorRotate();



protected:
	// Called when the game starts
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FDoorRequest OpenDoorRequest;

	UPROPERTY(BlueprintAssignable)
	FDoorRequest CloseDoorRequest;



private:

	void OpenDoor();
	void CloseDoor();
	float ReturnTotalMassOnTrigger();
	
	AActor* Owner = nullptr;

	UPROPERTY(EditAnywhere)
	float TriggerMass = 45.0;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* TriggerVolume = nullptr;

	
};
