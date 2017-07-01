// Fill out your copyright notice in the Description page of Project Settings.

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "VRPlayer.h"
#include "MonsterAIController.h"

AMonsterAIController::AMonsterAIController()
	:mBlackboard(CreateOptionalDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoard")))
	, mBehaviortree(CreateOptionalDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTree")))
{
	AddInstanceComponent(mBlackboard);
	AddOwnedComponent(mBehaviortree);

	//bWantsPlayerState = true;
	PrimaryActorTick.bCanEverTick = true;
}

void AMonsterAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

	//mOwner = Cast<AMonsterAIController>(InPawn);
}

void AMonsterAIController::BeginInactiveState()
{
}

void AMonsterAIController::AngerMonster()
{
}


