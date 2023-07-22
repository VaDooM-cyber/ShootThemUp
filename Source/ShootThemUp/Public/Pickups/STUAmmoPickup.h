// Shoot Them Up Games, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "STUBasePickup.h"
#include "STUAmmoPickup.generated.h"

class ASTUBaseWeapon;

UCLASS()
class SHOOTTHEMUP_API ASTUAmmoPickup : public ASTUBasePickup
{
	GENERATED_BODY()

private:

	virtual bool GivePickupTo(APawn* PlayerPawn) override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Puckup", meta = (ClampMin = "1.0", ClampMax = "10.0"))
		int32 ClipsAmount = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Puckup")
		TSubclassOf<ASTUBaseWeapon> WeaponType;
	
};
