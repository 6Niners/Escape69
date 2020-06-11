// Private Closed Project, sharing or editing the source code is prohibited 
//and will be faced with legal action, claiming the project is yours will end you up in jail.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Engine/Engine.h"
#include "Components/EditableTextBox.h"
#include "MainMenu_Code.generated.h"

/**
 * 
 */
UCLASS()
class BUILDINGESCAPE_API UMainMenu_Code : public UUserWidget
{
	GENERATED_BODY()
	

public:

	virtual bool Initialize() override;
	void setupMenu(UUserWidget* widget);
	void disableMenu();

	UFUNCTION()
	void HostServer();
	
	UFUNCTION()
	void JoinServer();

	UFUNCTION()
	void LoadJoinMenu();

	UFUNCTION()
	void RemoveJoinMenu();

	UFUNCTION()
	void loadKnapSack();

	UFUNCTION()
	void loadSoulCave();

private:

	UPROPERTY(meta = (BindWidget))
	UButton* HostBtn;

	UPROPERTY(meta = (BindWidget))
	UButton* JoinBtn;

	UPROPERTY(meta = (BindWidget))
	UButton* CancelBtn;

	UPROPERTY(meta = (BindWidget))
	UButton* JoinIPBtn;

	UPROPERTY(meta = (BindWidget))
	UButton* KnapSackBtn;

	UPROPERTY(meta = (BindWidget))
	UButton* SoulCaveBtn;

	UPROPERTY(meta = (BindWidget))
	UWidget* JoinMenuFull;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* IPTextBox;
};
