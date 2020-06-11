// Private Closed Project, sharing or editing the source code is prohibited 
//and will be faced with legal action, claiming the project is yours will end you up in jail.

#include "LevelTransitionTrigger.h"

// Sets default values
ALevelTransitionTrigger::ALevelTransitionTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelTransitionTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	triggerBox = FindComponentByClass<UBoxComponent>();

	if (triggerBox) {

		triggerBox->OnComponentBeginOverlap.AddDynamic(this, &ALevelTransitionTrigger::OnOverlapBegin);
		triggerBox->OnComponentEndOverlap.AddDynamic(this, &ALevelTransitionTrigger::OnOverlapEnd);
	}


}

// Called every frame
void ALevelTransitionTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void ALevelTransitionTrigger::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) {

	APlayerController* controller = GetWorld()->GetFirstPlayerController();
	controller->ClientTravel(levelURL, ETravelType::TRAVEL_Absolute, true);
	
}


void ALevelTransitionTrigger::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex) {
	


}

