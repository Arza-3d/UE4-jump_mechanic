// Part of jump mechanic study in https://arza-3d.github.io/UE4-jump-mechanic/

#pragma once

#include "CoreMinimal.h"
#include "StudyJumpMechanicCharacter.h"
#include "SprintJumpCharacter.generated.h"

/**
 * Character class with built-in sprint jump ability
 */
UCLASS()
class STUDYJUMPMECHANIC_API ASprintJumpCharacter : public AStudyJumpMechanicCharacter
{
	GENERATED_BODY()

	float GradientJumpToSpeed;

	float DefaultMaxWalkSpeed;

	void SetupPlayerInputComponent(UInputComponent * PlayerInputComponent) override;

public:
	ASprintJumpCharacter();

	void Jump() override;

	void OnJumped_Implementation() override;

	void Landed(const FHitResult & Hit) override;

protected:

	// this value should be higher than CharacterMovement.MaxWalkSpeed
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Sprint Jump")
	float MaxSprintSpeed;

	// this value should be higher than CharacterMovement.JumpZVelocity
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Sprint Jump")
	float SprintJumpZVelocity;

	void Sprint();

	void StopSprinting();

	float GetXYSpeed();

	// for animBP
	UPROPERTY(BlueprintReadOnly, Category = "Sprint Jump")
	float DefaultJumpZVelocity;

	// for animBP
	UPROPERTY(BlueprintReadOnly, Category = "Sprint Jump")
	bool bIsSprinting;

	// for animBP
	UPROPERTY(BlueprintReadOnly, Category = "Sprint Jump")
	bool bIsInSprintJump;

};
