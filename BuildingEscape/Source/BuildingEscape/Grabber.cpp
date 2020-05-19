// Private Closed Project, sharing or editing the source code is prohibited 
//and will be faced with legal action, claiming the project is yours will end you up in jail.

#include "Grabber.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	AttachInputComponent();
	AttachPhysicsHandle();

}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//DrawDebugLine(GetWorld(), ReturnTraceLineStart(), ReturnTraceLineEnd(), FColor::Red, false, 0.0, 0, 5.0);

	UpdatePhysicsObjectLocation();
	
}



void UGrabber::UpdatePhysicsObjectLocation() {

	if (!PhysicsHandle) {
		return;
	}
	else if (PhysicsHandle->GetGrabbedComponent()) {

		PhysicsHandle->SetTargetLocation(ReturnTraceLineEnd());
	}
}



void UGrabber::AttachInputComponent() {

	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent) {

		InputComponent->BindAction("Grab", EInputEvent::IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", EInputEvent::IE_Released, this, &UGrabber::Release);
	}
}



void UGrabber::AttachPhysicsHandle() {

	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (!PhysicsHandle) {

		UE_LOG(LogTemp, Error, TEXT("%s is missing a physics component"), *(GetOwner()->GetName()))
	}
}



void UGrabber::Grab() {

	GEngine->AddOnScreenDebugMessage(0, 2.0, FColor::Red, TEXT("grab called"));

	// reference to Hit object
	FHitResult HitResult = ReturnFirstTracePhysicsObject();
	UPrimitiveComponent* ComponentToGrab = HitResult.GetComponent();
	AActor* HitActor = HitResult.GetActor();

	//if Physics Object is hit
	if (HitActor) {
		//grab component
		PhysicsHandle->GrabComponent(
			ComponentToGrab,
			NAME_None,
			HitActor->GetActorLocation(),
			true
		);
	}		
}



void UGrabber::Release() {

	if (!PhysicsHandle) {
		return;
	}
	else {

		PhysicsHandle->ReleaseComponent();
	}
}



FHitResult UGrabber::ReturnFirstTracePhysicsObject() {

	FHitResult Hit;

	bool Trace = GetWorld()->LineTraceSingleByObjectType(
		Hit,
		ReturnTraceLineStart(),
		ReturnTraceLineEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		FCollisionQueryParams(FName(TEXT("")), false, GetOwner())
	);

	return Hit;
}



FVector UGrabber::ReturnTraceLineStart() {

	FVector ViewPointLocation;
	FRotator ViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);
	
	return ViewPointLocation;
}



FVector UGrabber::ReturnTraceLineEnd() {

	FVector ViewPointLocation;
	FRotator ViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);

	return ViewPointLocation + ViewPointRotation.Vector() * Reach;
}