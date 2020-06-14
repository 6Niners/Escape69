// All copyrights reserved. 6Niners organization.


#include "GameOverOverlay.h"

void UGameOverOverlay::setupGameOverOverlay() {

	APlayerController* playerController = GetWorld()->GetFirstPlayerController();
	
	this->AddToViewport();
	playerController->bShowMouseCursor = false;
}