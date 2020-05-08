// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
	GlobalStartLocation = GetActorLocation();
	GlobalTLocation = GetTransform().TransformPosition(TLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	if (platformsToTrigger > 0) {

		if (HasAuthority())
		{

			FVector Location = GetActorLocation();
			float JourneyLength = (GlobalTLocation - GlobalStartLocation).Size();
			float JourneyTravelled = (Location - GlobalStartLocation).Size();

			if (loop)
			{
				if (JourneyTravelled >= JourneyLength)
				{
					FVector Swap = GlobalStartLocation;
					GlobalStartLocation = GlobalTLocation;
					GlobalTLocation = Swap;
				}
			}


			FVector Direction = (GlobalTLocation - GlobalStartLocation).GetSafeNormal();
			Location += Speed * DeltaTime * Direction;

			if (Triggered)
			{
				SetActorLocation(Location);
			}
		}
	}
}



void AMovingPlatform::incrementPlatformsToTrigger() {
	
	platformsToTrigger++;
}



void AMovingPlatform::decrementPlatformsToTrigger() {

	platformsToTrigger--;
}
