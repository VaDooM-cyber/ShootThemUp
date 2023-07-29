// Shoot Them Up Games, All Rights Reserved.


#include "Weapon/Components/STUWeaponFXComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "Kismet/GameplayStatics.h"
#include "Components/DecalComponent.h"


USTUWeaponFXComponent::USTUWeaponFXComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

	
}

void USTUWeaponFXComponent::BeginPlay()
{
	Super::BeginPlay();

	
	
}

void USTUWeaponFXComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}

void USTUWeaponFXComponent::PlayImpactVFX(const FHitResult& Hit)
{
	auto ImpactEffect = DefaultIpmactData;

	if (Hit.PhysMaterial.IsValid())
	{
		const auto PhysMat = Hit.PhysMaterial.Get();
		if (ImpactDataMap.Contains(PhysMat))
		{
			ImpactEffect = ImpactDataMap[PhysMat];
		}
	}

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(),	//
							 ImpactEffect.NiagaraEffect,		//
							 Hit.ImpactPoint,					//
							 Hit.ImpactNormal.Rotation());		//

	auto DecalComponent = UGameplayStatics::SpawnDecalAtLocation(GetWorld(),	//
								ImpactEffect.DecalData.Material,				//
								ImpactEffect.DecalData.Size,					//
								Hit.ImpactPoint,								//
								Hit.ImpactNormal.Rotation());					//

	DecalComponent->SetFadeOut(ImpactEffect.DecalData.LifeTime, ImpactEffect.DecalData.FadeOutTime);

}

