// Fill out your copyright notice in the Description page of Project Settings.


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

	actorLocation = GetActorLocation();
	actorLocation += FVector(0, 0 , -10);
	SetActorLocation(actorLocation);

}



void APressurePlate::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {


	actorLocation = GetActorLocation();
	actorLocation += FVector(0, 0, 10);
	SetActorLocation(actorLocation);

}