// Fill out your copyright notice in the Description page of Project Settings.


#include "CSpawn.h"
#include <CEnemy.h>

// Sets default values
ACSpawn::ACSpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACSpawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// ���� �ð��� �ѹ���
	CurrentTime += DeltaTime;

	if (CurrentTime > RespawnTime) {
		// ���� �����Ѵ�.
		FActorSpawnParameters param;
		param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		GetWorld()->SpawnActor<ACEnemy>(EnemyFactory, GetActorLocation(), FRotator::ZeroRotator, param);
		CurrentTime = 0;
	}
	
}

