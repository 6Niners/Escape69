// Private Closed Project, sharing or editing the source code is prohibited 
//and will be faced with legal action, claiming the project is yours will end you up in jail.

#include "PressurePlate.h"

// Sets default values
APressurePlate::APressurePlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APressurePlate::BeginPlay()
{
	Super::BeginPlay();
	
	triggerBox = FindComponentByClass<UBoxComponent>();

	if (HasAuthority()) {

		SetReplicates(true);
		SetReplicateMovement(true);
	}


	if (triggerBox) {

		triggerBox->OnComponentBeginOverlap.AddDynamic(this, &APressurePlate::OnOverlapBegin);
		triggerBox->OnComponentEndOverlap.AddDynamic(this, &APressurePlate::OnOverlapEnd);
	}
	else {

		GEngine->AddOnScreenDebugMessage(1, 5.0, FColor::Yellow, TEXT("Trigger box not attached"));
	}
}

// Called every frame
void APressurePlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void APressurePlate::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if (stopMovement < 1) {

		actorLocation = GetActorLocation();
		actorLocation += FVector(0, 0, -5);
		SetActorLocation(actorLocation);
		stopMovement++;
	}

	for (AMovingPlatform* platform : platformsArray) {

		platform->incrementPlatformsToTrigger();
	}

	
}



void APressurePlate::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {

	if (shouldRebound) {

		actorLocation = GetActorLocation();
		actorLocation += FVector(0, 0, 5);
		SetActorLocation(actorLocation);
	}

	for (AMovingPlatform* platform : platformsArray) {

		platform->decrementPlatformsToTrigger();
	}
}