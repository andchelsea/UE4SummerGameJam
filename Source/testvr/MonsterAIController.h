// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MonsterAIController.generated.h"

/**

UENUM(BlueprintType)
enum class AIstate : uint8
{
	AI_Entering 	UMETA(DisplayName = "Entering"),
	AI_Waiting 		UMETA(DisplayName = "Waiting"),
	AI_Satisfied	UMETA(DisplayName = "Satisfied"),
	AI_Angry		UMETA(DisplayName = "Angry"),
	AI_Leaving		UMETA(DisplayName = "Leaving")
};
 class Weapon;
 */



UCLASS()
class TESTVR_API AMonsterAIController : public AAIController
{
	GENERATED_BODY()
		AMonsterAIController();

	//UBlackboardComponent* mBlackboard;
	//UBehaviorTreeComponent* mBehaviortree;

	virtual void Possess(class APawn* InPawn) override;
	virtual void BeginInactiveState() override;

public:
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	//AIstate mCurrentState;

	class Weapon* mDesiredWeapon;
};
