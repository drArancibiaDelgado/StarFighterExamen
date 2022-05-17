// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveTerrestreEnemiga01.h"


ANaveTerrestreEnemiga01::ANaveTerrestreEnemiga01()
{
	PrimaryActorTick.bCanEverTick = true;
	SpawnPoint =
		CreateDefaultSubobject<UParticleSystemComponent>("SpawnPoint");
	auto ParticleSystem =
		ConstructorHelpers::FObjectFinder<UParticleSystem>
		(TEXT("ParticleSystem'/Engine/Tutorial/ SubEditors / TutorialAssets / TutorialParticleSystem.TutorialParticleSystem'"));
			if (ParticleSystem.Object != nullptr)
			{
				SpawnPoint->SetTemplate(ParticleSystem.Object);
			}
	SpawnPoint->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
}

void ANaveTerrestreEnemiga01::BeginPlay()
{
	Super::BeginPlay();
	SpawnPoint->AttachTo(RootComponent);

}

void ANaveTerrestreEnemiga01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetActorLocation() + FVector(10, 0, 0));
}

void ANaveTerrestreEnemiga01::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}





