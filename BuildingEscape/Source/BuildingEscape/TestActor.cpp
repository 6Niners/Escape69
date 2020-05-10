// Private Closed Project, sharing or editing the source code is prohibited 
//and will be faced with legal action, claiming the project is yours will end you up in jail.


#include "TestActor.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (HasAuthority()) {

		SetReplicateMovement(true);
		SetReplicates(true);
	}
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

