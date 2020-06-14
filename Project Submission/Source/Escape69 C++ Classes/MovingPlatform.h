// Private Closed Project, sharing or editing the source code is prohibited 
//and will be faced with legal action, claiming the project is yours will end you up in jail.
#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class BUILDINGESCAPE_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	virtual void BeginPlay();
	virtual void Tick(float DeltaTime) override;
	AMovingPlatform();

	void incrementPlatformsToTrigger();
	void decrementPlatformsToTrigger();

	UPROPERTY(EditAnywhere) float Speed = 20;
	UPROPERTY(EditAnywhere) bool loop = 0;
	UPROPERTY(BlueprintReadWrite, Category="Switch Variables", EditAnywhere) bool Triggered = 0;
	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true)) FVector TLocation;

	FVector GlobalStartLocation;
	FVector GlobalTLocation;
	
	UPROPERTY(EditAnywhere)
	int platformsToTrigger = 1;
};
