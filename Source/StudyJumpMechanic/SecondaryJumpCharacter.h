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

	bool bSecondaryButtonIsPressed;

	void SetupPlayerInputComponent(UInputComponent * PlayerInputComponent) override;

	float DefaultJumpZVelocity;

public:
	ASecondaryJumpCharacter();

	// (option A) is meant to be used for animBP, use this IF character has different jump start animation
	void Jump() override;

	// (option B) is meant to be used for animBP, use this IF character has same jump start animtaion but has different jump animation while in the air
	//void OnJumped_Implementation() override;

	void Landed(const FHitResult & Hit) override;
	
protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Secondary / Heavy Jump")
	float SecondaryJumpZVelocity;

	// is meant to be used for animBP (optional)
	UPROPERTY(BlueprintReadOnly, Category = "Jump")
	float bIsInSecondaryJump;

	void SecondaryInputPressed();

	void SecondaryInputReleased();

};
