// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StudyJumpMechanicCharacter.h"
#include "SprintJump_autoCharacter.generated.h"

/**
 * 
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

	float MaxJumpZVelocity;

	float GetXYSpeed();

};
