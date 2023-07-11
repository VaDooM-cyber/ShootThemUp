// Shoot Them Up Games, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUCoreTypes.h"
#include "STUPlayerHUDWidget.generated.h"


UCLASS()
class SHOOTTHEMUP_API USTUPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, category = "UI")
		float GetHealthPercent() const;

	UFUNCTION(BlueprintCallable, category = "UI")
		bool GetWeaponUIData(FWeaponUIData& UIData) const;
	
};
