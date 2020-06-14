// All copyrights reserved. 6Niners organization.

#include "KnapSack.h"

#include "price.h"

// Sets default values for this component's properties
UKnapSack::UKnapSack()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UKnapSack::BeginPlay()
{
	Super::BeginPlay();
	knapsack Mystry;
	//first door
	Mystry.SetKnapsackMaxWeight(MaxWeight);
	Mystry.insert_items({ Item(item_price_1,item_weight_1), Item(item_price_2,item_weight_2), Item(item_price_3,item_weight_3), Item(item_price_4,item_weight_4), Item(item_price_5,item_weight_5), Item(item_price_6,item_weight_6), Item(item_price_7,item_weight_7), Item(item_price_8,item_weight_8), Item(item_price_9,item_weight_9), Item(item_price_10,item_weight_10),Item(item_price_11,item_weight_11),Item(item_price_12,item_weight_12)});
	Triggerprice = Mystry.knapSackMaxValue();
	// ...
	if (!TriggerVolume) {

		UE_LOG(LogTemp, Error, TEXT("Trigger Volume has not been initialized"))
	}

	Owner = GetOwner();
}


// Called every frame
void UKnapSack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (ReturnTotalMassOnTrigger() == Triggerprice) {

		OpenDoor();
	}
	else {

		CloseDoor();
	}
	// ...
}

void UKnapSack::OpenDoor() {

	OpenDoorRequest1.Broadcast();
}




void UKnapSack::CloseDoor() {

	CloseDoorRequest1.Broadcast();
}




float UKnapSack::ReturnTotalMassOnTrigger() {

	float TotalMass = 0;

	TArray<AActor*> ActorsOnTriggerVolume;


	if (TriggerVolume) {

		TriggerVolume->GetOverlappingActors(ActorsOnTriggerVolume);
	}
	else {
		return TotalMass;
	}


	for (AActor* Actor : ActorsOnTriggerVolume) {
		float ActorMass;
		
		if (Actor->FindComponentByClass<Uprice>() == NULL) {}
		else {
			ActorMass = Actor->FindComponentByClass<Uprice>()->Price;
		}

		TotalMass += ActorMass;

		UE_LOG(LogTemp, Warning, TEXT("%s price is %f"), *(Actor->GetName()), ActorMass);
	}



	return TotalMass;
}
