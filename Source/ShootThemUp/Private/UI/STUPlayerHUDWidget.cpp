// Shoot Them Up Games, All Rights Reserved.

#include "UI/STUPlayerHUDWidget.h"
#include "Components/STUWeaponComponent.h"
#include "Components/STUHealthComponent.h"
#include "STUUtils.h"


float USTUPlayerHUDWidget::GetHealthPercent() const
{

	const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(GetOwningPlayerPawn());
	if (!HealthComponent) return 0.0f;

	return HealthComponent->GetHealthPercent();

}

bool USTUPlayerHUDWidget::GetWeaponCurrentUIData(FWeaponUIData& UIData) const
{

	const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(GetOwningPlayerPawn());
	if (!WeaponComponent) return false;

	return WeaponComponent->GetWeaponUIData(UIData);

}

bool USTUPlayerHUDWidget::GetWeaponCurrentAmmoData(FAmmoData& AmmoData) const
{

	const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(GetOwningPlayerPawn());
	if (!WeaponComponent) return false;

	return WeaponComponent->GetWeaponAmmoData(AmmoData);

}

bool USTUPlayerHUDWidget::IsPlayerAlive() const
{

	const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(GetOwningPlayerPawn());
	return HealthComponent && !HealthComponent->IsDeath();

}

bool USTUPlayerHUDWidget::IsPlayerSpectating() const
{

	const auto Controller = GetOwningPlayer();
	return Controller && Controller->GetStateName() == NAME_Spectating;

}