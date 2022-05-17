// Fill out your copyright notice in the Description page of Project Settings.
//#include "Particles/ParticleSystemComponent.h"
#pragma once

#include "CoreMinimal.h"
#include "Nave.h"
#include "NaveTerrestre.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ANaveTerrestre : public ANave
{
	GENERATED_BODY()
public:
	ANaveTerrestre();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;



	UPROPERTY()
		UStaticMeshComponent* BuildingMesh;
	UPROPERTY()
		UParticleSystemComponent* SpawnPoint;
	UPROPERTY()
		UClass* UnitToSpawn;
	UPROPERTY()
		float SpawnInterval;
	UFUNCTION()
		void SpawnUnit();
	UFUNCTION()
		void EndPlay(const EEndPlayReason::Type EndPlayReason)
		override;
	UPROPERTY()
		FTimerHandle SpawnTimerHandle;
	
};
