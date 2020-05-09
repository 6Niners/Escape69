// Fill out your copyright notice in the Description page of Project Settings.


#include "RespawnTrigger.h"

// Sets default values
ARespawnTrigger::ARespawnTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARespawnTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	respawnTrigger = FindComponentByClass<UBoxComponent>();

	if (respawnTrigger) {

		respawnTrigger->OnComponentBeginOverlap.AddDynamic(this, &ARespawnTrigger::OnOverlapBegin);
	}
	else {

		GEngine->AddOnScreenDebugMessage(1, 5.0, FColor::Yellow, TEXT("Trigger box not attached"));
	}
}

// Called every frame
void ARespawnTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}

void ARespawnTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	
	if (OtherActor) {

		OtherActor->SetActorLocation(respawnLocation);
	}

}



void ARespawnTrigger::OnOverlapEnd() {



}

