// Private Closed Project, sharing or editing the source code is prohibited 
//and will be faced with legal action, claiming the project is yours will end you up in jail.

#include "Escape69_GameInstance.h"

UEscape69_GameInstance::UEscape69_GameInstance(const FObjectInitializer& ObjectInitializer) {

	ConstructorHelpers::FClassFinder<UMainMenu_Code> MainMenu_BP(TEXT("/Game/MainMenu/MainMenu_BP"));

	if (MainMenu_BP.Class) {

		menuClass = MainMenu_BP.Class;
	}
}



void UEscape69_GameInstance::loadMainMenu() {

	UMainMenu_Code* menuWidget = CreateWidget<UMainMenu_Code>(this, menuClass);
	menuWidget->setupMenu(menuWidget);
}




void UEscape69_GameInstance::HostServer() {

	GEngine->AddOnScreenDebugMessage(1, 5.0, FColor::Green, TEXT("Hosting Server..."));
	GetWorld()->ServerTravel("/Game/Levels/Level_1?Listen");
}



void UEscape69_GameInstance::JoinServer(FString IP) {

	GEngine->AddOnScreenDebugMessage(1, 5.0, FColor::Green, FString::Printf(TEXT("Joining Game At IP: %s"), *IP));

	APlayerController* playerController = GetWorld()->GetFirstPlayerController();

	if (playerController != nullptr) {

		playerController->ClientTravel(IP, ETravelType::TRAVEL_Absolute);
	}
}
