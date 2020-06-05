// All copyrights reserved. 6Niners organization.


#include "price.h"

// Sets default values for this component's properties
Uprice::Uprice()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void Uprice::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void Uprice::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int Uprice::GetPrice() {
	{return Price;}
}



void Uprice::SetPrice(int P){
	{Price=P;}
}