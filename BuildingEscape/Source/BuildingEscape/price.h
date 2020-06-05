// All copyrights reserved. 6Niners organization.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "price.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API Uprice : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	Uprice();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable, Category = "My Functions")
		int GetPrice();
	
	UFUNCTION(BlueprintCallable, Category = "My Functions")
		void SetPrice(int P);
	
	UPROPERTY(EditAnywhere)
		int Price = 50;

		
};
