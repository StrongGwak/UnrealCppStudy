// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyFSM.generated.h"

UENUM(BlueprintType)
enum class EEnemyState : uint8
{
	IDLE = 0 UMETA(DisplayName=Idle),
	MOVE,
	ATTACK,
	DAMAGE,
	DIE	
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TPSGCC_API UEnemyFSM : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemyFSM();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(BlueprintReadOnly)
	EEnemyState mState = EEnemyState::IDLE;

	void IdleState();

	//------- Move ---------
	//필요속성 : 타겟, 이동속도
	UPROPERTY()
	class AEnemy* Me;
	UPROPERTY()
	class ATPSGCCCharacter* Target = nullptr;
	UPROPERTY(EditAnywhere, Category = "Settings")
	float Speed = 500;
	void MoveState();

	//------- Attack ---------
	UPROPERTY(EditAnywhere, Category = "Settings")
	float AttackRange = 200;
	UPROPERTY(EditAnywhere, Category = "Settings")
	float AttackTime = 2;
	void AttackState();

	// 피격이벤트
	void OnDamageProcess();
	void DamageState();
	void DieState();

	float CurrentTime = 0;
	float IdleTime = 2.0f;

};
