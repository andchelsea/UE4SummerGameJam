// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MonsterAIController.generated.h"

UCLASS()
class TESTVR_API AMonsterAIController : public AAIController
{
	GENERATED_BODY()
		AMonsterAIController();

	class UBlackboardComponent* mBlackboard;
	class UBehaviorTreeComponent* mBehaviortree;

	virtual void Possess(class APawn* InPawn) override;
	virtual void BeginInactiveState() override;

	class AMonster* mOwner;

	//Blackboard variables
	uint8 StallID;
	uint8 ExitPosID;
	uint8 StateEnum;

public:
	UFUNCTION(BlueprintCallable)
		void AngerMonster();

	class Weapon* mDesiredWeapon;
};
