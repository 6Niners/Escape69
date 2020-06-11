// All copyrights reserved. 6Niners organization.


#include "InGameMenu.h"


bool UInGameMenu::Initialize() {

	if (!Super::Initialize()) return false;

	InGameCancelBtn->OnClicked.AddDynamic(this, &UInGameMenu::removeInGameMenu);
	InGameQuitBtn->OnClicked.AddDynamic(this, &UInGameMenu::goToMainMenu);

	return true;
}



void UInGameMenu::setupInGameMenu(){

	APlayerController* playerController = GetWorld()->GetFirstPlayerController();
	FInputModeUIOnly inputMode;

	inputMode.SetWidgetToFocus(this->TakeWidget());
	
	this->AddToViewport();

	playerController->SetInputMode(inputMode);
	playerController->bShowMouseCursor = true;
}



void UInGameMenu::removeInGameMenu() {

	APlayerController* playerController = GetWorld()->GetFirstPlayerController();
	FInputModeGameOnly inputMode;

	this->RemoveFromViewport();
	playerController->SetInputMode(inputMode);
	playerController->bShowMouseCursor = false;

}

void UInGameMenu::goToMainMenu() {GetWorld()->ServerTravel("/Game/MainMenu/MainMenu_Level");}
