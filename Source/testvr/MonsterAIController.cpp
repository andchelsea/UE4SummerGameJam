// Fill out your copyright notice in the Description page of Project Settings.

#include "MonsterAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
//#include "BehaviorTree/Blackboard/BlackboardKeyType_Enum.h"
#include "Monster.h"
#include "VRPlayer.h"

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

	mOwner = Cast<AMonster>(InPawn);

	if (mOwner&&mOwner->BehaviorTree)
	{
		mBlackboard->InitializeBlackboard(*mOwner->BehaviorTree->BlackboardAsset);

		StallID = mBlackboard->GetKeyID("Stall");
		ExitPosID = mBlackboard->GetKeyID("RandomizedExitPoint");
		StateEnum = mBlackboard->GetKeyID("CurrentState");

		mBlackboard->SetValue<UBlackboardKeyType_Vector>(StallID, mOwner->StallLocation);
		//mBlackboard->SetValue<UBlackboardKeyType_Enum>(StateEnum, AIstate::Entering);
		mBehaviortree->StartTree(*mOwner->BehaviorTree);
	}
}

void AMonsterAIController::BeginInactiveState()
{
}

void AMonsterAIController::AngerMonster()
{
}


