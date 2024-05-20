// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CPlayer.generated.h"

UCLASS()
class SHOOTING_API ACPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// StaticMeshComponent �߰�
	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UStaticMeshComponent* BodyMesh = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Component")
	class USceneComponent* FirePosition = nullptr;

	float h;
	float v;
	// �¿��Է�ó���Լ�
	void Horizontal(float value);
	// �����Է�ó���Լ�
	void Vertical(float value);

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ACBullet> BulletFactory;
	// ����ڰ� �߻��ư�� ������ �Ѿ��� �߻��ϰ� �ʹ�.
	void Fire();

	UPROPERTY(EditAnywhere, Category = "Settings")
	int BulletCount = 0;

	UPROPERTY(EditAnywhere, Category = "Settings")
	float Distance = 0;


};
