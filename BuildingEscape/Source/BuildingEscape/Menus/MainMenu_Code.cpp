// Private Closed Project, sharing or editing the source code is prohibited 
//and will be faced with legal action, claiming the project is yours will end you up in jail.

#include "MainMenu_Code.h"


bool UMainMenu_Code::Initialize() {

	if (!Super::Initialize()) return false;

	HostBtn->OnClicked.AddDynamic(this, &UMainMenu_Code::HostServer);
	JoinBtn->OnClicked.AddDynamic(this, &UMainMenu_Code::LoadJoinMenu);
	CancelBtn->OnClicked.AddDynamic(this, &UMainMenu_Code::RemoveJoinMenu);
	JoinIPBtn->OnClicked.AddDynamic(this, &UMainMenu_Code::JoinServer);
	TutorialBtn->OnClicked.AddDynamic(this, &UMainMenu_Code::OpenTutorial);


	return true;
}



void UMainMenu_Code::setupMenu(UUserWidget* widget) {

	APlayerController* playerController = GetWorld()->GetFirstPlayerController();
	FInputModeUIOnly inputMode;

	inputMode.SetWidgetToFocus(widget->TakeWidget());

	widget->AddToViewport();
	RemoveJoinMenu();
	playerController->SetInputMode(inputMode);
	playerController->bShowMouseCursor = true;
}



void UMainMenu_Code::disableMenu() {

	APlayerController* playerController = GetWorld()->GetFirstPlayerController();
	FInputModeGameOnly inputMode;
	
	this->RemoveFromViewport();
	playerController->SetInputMode(inputMode);
	playerController->bShowMouseCursor = false;

}



void UMainMenu_Code::LoadJoinMenu() {

	if (JoinMenuFull) {

		JoinMenuFull->SetVisibility(ESlateVisibility::Visible);
	}
}



void UMainMenu_Code::RemoveJoinMenu() {

	if (JoinMenuFull) {

		JoinMenuFull->SetVisibility(ESlateVisibility::Hidden);
	}
}



void UMainMenu_Code::JoinServer() {

	FString IP = (IPTextBox->Text).ToString();

	GEngine->AddOnScreenDebugMessage(1, 5.0, FColor::Green, FString::Printf(TEXT("Joining Game At IP: %s"), *IP));

	APlayerController* playerController = GetWorld()->GetFirstPlayerController();

	if (playerController != nullptr) {

		disableMenu();
		playerController->ClientTravel(IP, ETravelType::TRAVEL_Absolute);
	}
}



void UMainMenu_Code::HostServer() {

	disableMenu();

	GEngine->AddOnScreenDebugMessage(1, 5.0, FColor::Green, TEXT("Hosting Server..."));
	GetWorld()->ServerTravel("/Game/Levels/Level_1?Listen");
}

void UMainMenu_Code::OpenTutorial()
{
	disableMenu();
	GetWorld()->ServerTravel("/Game/Levels/Tutorial?Listen");
}