// Fill out your copyright notice in the Description page of Project Settings.

#include "MonsterAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
//#include "BehaviorTree/Blackboard/BlackboardKeyType_Enum.h"
#include "Monster.h"
#include "Item.h"
#include "time.h"

AMonsterAIController::AMonsterAIController()
	:mBlackboard(CreateOptionalDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoard")))
	, mBehaviortree(CreateOptionalDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTree")))
{
	AddInstanceComponent(mBlackboard);
	AddOwnedComponent(mBehaviortree);

	//bWantsPlayerState = true;
	PrimaryActorTick.bCanEverTick = true;

	srand(time(NULL));
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
	
	mDesiredWeapon = NewObject<AItem>();

	switch (rand()%3)//set weapon type
	{
		case 0:
			mDesiredWeapon->SetWeaponType(WeaponType::kSword);
			break;
		case 1:
			mDesiredWeapon->SetWeaponType(WeaponType::kAxe);
			break;
		case 2:
			mDesiredWeapon->SetWeaponType(WeaponType::kLance);
			break;
	}

	switch (rand() % 3)//set weapon material
	{
	case 0:
		mDesiredWeapon->SetMaterialType(MaterialType::kCopper);
		break;
	case 1:
		mDesiredWeapon->SetMaterialType(MaterialType::kGold);
		break;
	case 2:
		mDesiredWeapon->SetMaterialType(MaterialType::kIron);
		break;
	}
}

void AMonsterAIController::BeginInactiveState()
{
}

