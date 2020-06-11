// All copyrights reserved. 6Niners organization.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "InGameMenu.generated.h"

/**
 * 
 */
UCLASS()
class BUILDINGESCAPE_API UInGameMenu : public UUserWidget
{
	GENERATED_BODY()
	

public:

	virtual bool Initialize() override;

	UFUNCTION() void removeInGameMenu();
	UFUNCTION() void goToMainMenu();
	void setupInGameMenu();

private:

	UPROPERTY(meta = (BindWidget)) UButton* InGameCancelBtn;
	UPROPERTY(meta = (BindWidget)) UButton* InGameQuitBtn;

};
