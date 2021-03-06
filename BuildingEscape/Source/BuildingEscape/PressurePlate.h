// Private Closed Project, sharing or editing the source code is prohibited 
//and will be faced with legal action, claiming the project is yours will end you up in jail.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h" 
#include "MovingPlatform.h"
#include "PressurePlate.generated.h"

UCLASS()
class BUILDINGESCAPE_API APressurePlate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APressurePlate();
	UPROPERTY(BlueprintReadWrite, Category = "Switch Variables", EditAnywhere) bool Triggered = 0;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	UFUNCTION() void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION() void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere) TArray<AMovingPlatform*> platformsArray;

	UBoxComponent* triggerBox = nullptr;
	FVector actorLocation;

	UPROPERTY(EditAnywhere) bool shouldRebound = true;

	int stopMovement = 0;
};
