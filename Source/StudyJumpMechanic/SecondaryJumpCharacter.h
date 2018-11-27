// Part of jump mechanic study in https://arza-3d.github.io/UE4-jump-mechanic/

#pragma once

#include "CoreMinimal.h"
#include "StudyJumpMechanicCharacter.h"
#include "SecondaryJumpCharacter.generated.h"

/**
 * Character class with built-in secondary jump / heavy jump
 */
UCLASS()
class STUDYJUMPMECHANIC_API ASecondaryJumpCharacter : public AStudyJumpMechanicCharacter
{
	GENERATED_BODY()

	void SetupPlayerInputComponent(UInputComponent * PlayerInputComponent) override;

	bool bSecondaryButtonIsPressed;

	float DefaultJumpZVelocity;

public:
	ASecondaryJumpCharacter();

	// for animBP (optional)
	void Jump() override;

	void Landed(const FHitResult & Hit) override;

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Secondary / Heavy Jump")
	float SecondaryJumpZVelocity;

	// for animBP (optional)
	UPROPERTY(BlueprintReadOnly, Category = "Secondary / Heavy Jump")
	bool bIsInSecondaryJump;

	void SecondaryInputPressed();

	void SecondaryInputReleased();

};
