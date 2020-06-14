// Private Closed Project, sharing or editing the source code is prohibited 
//and will be faced with legal action, claiming the project is yours will end you up in jail.

#include "DoorRotate.h"

// Sets default values for this component's properties
UDoorRotate::UDoorRotate()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorRotate::BeginPlay()
{
	Super::BeginPlay();
	
	if (!TriggerVolume) {

		UE_LOG(LogTemp, Error, TEXT("Trigger Volume has not been initialized"))
	}

	Owner = GetOwner();
}


// Called every frame
void UDoorRotate::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (ReturnTotalMassOnTrigger() > TriggerMass) {

		OpenDoor();
	}
	else {

		CloseDoor();
	}
}



void UDoorRotate::OpenDoor () {
	
	OpenDoorRequest.Broadcast();
}




void UDoorRotate::CloseDoor() {
	
	CloseDoorRequest.Broadcast();
}




float UDoorRotate::ReturnTotalMassOnTrigger() {

	float TotalMass = 0;

	TArray<AActor*> ActorsOnTriggerVolume;


	if (TriggerVolume) {

		TriggerVolume->GetOverlappingActors(ActorsOnTriggerVolume);
	} 
	else {
		return TotalMass;
	}


	for (AActor* Actor : ActorsOnTriggerVolume) {

		float ActorMass = Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();

		TotalMass += ActorMass;

		UE_LOG(LogTemp, Warning, TEXT("%s mass is %f"), *(Actor->GetName()), ActorMass);
	}
	
	

	return TotalMass;
}