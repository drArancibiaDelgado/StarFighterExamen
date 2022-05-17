// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveTerrestre.h"
#include"NaveTerrestreEnemiga01.h"

ANaveTerrestre::ANaveTerrestre()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Engine/BasicShapes/Cone.Cone"));


	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);

	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BuildingMesh = CreateDefaultSubobject<UStaticMeshComponent>("BuildingMesh");
	SpawnPoint = CreateDefaultSubobject<UParticleSystemComponent>("SpawnPoint");
	SpawnInterval = 10;
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (MeshAsset.Object != nullptr)
	{
		BuildingMesh->SetStaticMesh(MeshAsset.Object);
		BuildingMesh->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	}
	auto ParticleSystem =
		ConstructorHelpers::FObjectFinder<UParticleSystem>
		(TEXT("ParticleSystem'/Engine/Tutorial/ SubEditors / TutorialAssets/ TutorialParticleSystem.TutorialParticleSystem'"));
	if (ParticleSystem.Object != nullptr)
	{
		SpawnPoint->SetTemplate(ParticleSystem.Object);
	}
	SpawnPoint->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
	UnitToSpawn = ANaveTerrestreEnemiga01::StaticClass();
}

void ANaveTerrestre::BeginPlay()
{
	Super::BeginPlay();
	RootComponent = BuildingMesh;
	SpawnPoint->AttachTo(RootComponent);
	SpawnPoint->SetRelativeLocation(FVector(150, 0, 0));
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ANaveTerrestreEnemiga01::SpawnUnit, SpawnInterval, true);
}

void ANaveTerrestre::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANaveTerrestre::SpawnUnit()
{
	FVector SpawnLocation = SpawnPoint->GetComponentLocation();
	GetWorld()->SpawnActor(UnitToSpawn, &SpawnLocation);
}

void ANaveTerrestre::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
}
