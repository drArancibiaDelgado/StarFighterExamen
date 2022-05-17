// Fill out your copyright notice in the Description page of Project Settings.
//basado en el libro de unreal engine
#pragma once
#include "CoreMinimal.h"
#include "NaveTerrestre.h"
#include "NaveTerrestreEnemiga01.generated.h"
#include "Particles/ParticleSystemComponent.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ANaveTerrestreEnemiga01 : public ANaveTerrestre
{
	GENERATED_BODY()
public:
	ANaveTerrestreEnemiga01();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	UPROPERTY() 
		UParticleSystemComponent* SpawnPoint;

};

