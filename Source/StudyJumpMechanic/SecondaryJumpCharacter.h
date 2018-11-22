// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StudyJumpMechanicCharacter.h"
#include "SecondaryJumpCharacter.generated.h"

/**
 * 
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

	// is meant to be used for animBP, use this if character has different jump start animation
	void Jump() override;

	// is meant to be used for animBP, use this if character has same jump start animtaion but has different jump animation while in the air
	//void OnJumped_Implementation() override;

	void Landed(const FHitResult & Hit) override;
	
protected:

	UPROPERTY(BlueprintReadWrite, Category = "Jump")
	float SecondaryJumpZVelocity;

	// is meant to be used for animBP
	UPROPERTY(BlueprintReadOnly, Category = "Jump")
	float bIsInSecondaryJump;

	void SecondaryInputPressed();

	void SecondaryInputReleased();

};
