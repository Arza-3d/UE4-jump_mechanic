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

	float DefaultJumpZVelocity;

	void SetupPlayerInputComponent(UInputComponent * PlayerInputComponent) override;

public:
	ASprintJumpCharacter();

	void Jump() override;

	void OnJumped_Implementation() override;

	void Landed(const FHitResult & Hit) override;

protected:

	UPROPERTY(EditAnywhere, Category = Jump)
	float MaxSprintSpeed;

	UPROPERTY(EditAnywhere, Category = Jump)
	float SprintJumpZVelocity;

	// is meant to be used for animBP:
	UPROPERTY(BlueprintReadOnly, Category = Jump)
	bool bIsSprinting;

	// is meant to be used for animBP:
	UPROPERTY(BlueprintReadOnly, Category = Jump)
	bool bIsInSprintJump;

	void Sprint();

	void StopSprinting();

	float GetXYSpeed();

};
