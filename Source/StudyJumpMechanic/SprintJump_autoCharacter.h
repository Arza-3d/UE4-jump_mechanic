// Part of jump mechanic study in https://arza-3d.github.io/UE4-jump-mechanic/

#pragma once

#include "CoreMinimal.h"
#include "StudyJumpMechanicCharacter.h"
#include "SprintJump_autoCharacter.generated.h"

/**
 * Character class with built-in auto-sprint jump
 */
UCLASS()
class STUDYJUMPMECHANIC_API ASprintJump_autoCharacter : public AStudyJumpMechanicCharacter
{
	GENERATED_BODY()

	float DefaultJumpZVelocity;

	float GradientJumpToSpeed;

public: 

	ASprintJump_autoCharacter();

	void Jump() override;

	void Landed(const FHitResult & Hit) override;

protected:

	// this value should be higher than CharacterMovement.JumpZVelocity
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Auto Sprint Jump")
	float MaxJumpZVelocity;

	float GetXYSpeed();

};
