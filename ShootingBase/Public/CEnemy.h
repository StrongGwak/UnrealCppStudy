// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CEnemy.generated.h"

UCLASS()
class SHOOTING_API ACEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// StaticMeshComponent 추가
	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UStaticMeshComponent* BodyMesh = nullptr;

	FVector Direction;

	UPROPERTY(EditAnywhere)
	float Speed = 500;
	// 태어날때 타켓 방향을 구하고 그 방향으로 계속 이동하고 싶다.
	void FindTargetDirection();
	void MoveToTaget();

	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, Category = "Bullet")
	TSubclassOf<class ACBullet> BulletFactory;
	// 사용자가 발사버튼을 누르면 총알을 발사하고 싶다.
	void Fire();

	UPROPERTY(EditAnywhere, Category = "Bullet")
	int32 BulletCount = 6;
	UPROPERTY(EditAnywhere, Category = "Bullet")
	float Distance = 100;

	float CurrentTime = 0;
	UPROPERTY(EditAnywhere, Category = "Bullet")
	float CreateTime = 0.25f;
	int32 CurrentBulletCount = 0;
	int i = 0;

};
