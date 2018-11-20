// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StudyJumpMechanicCharacter.h"
#include "JumpThenGlideCharacter.generated.h"

/**
 * 
 */
UCLASS()
class STUDYJUMPMECHANIC_API AJumpThenGlideCharacter : public AStudyJumpMechanicCharacter
{
	GENERATED_BODY()

	float DefaultGravityScale;

	bool bJumpInputIsPressed;

	bool bIsAbleToGlide;

public:

	AJumpThenGlideCharacter();

	UPROPERTY(BlueprintReadOnly, Category = Jump)
	bool bIsGliding;

	void Jump() override;

	void StopJumping() override;

	void NotifyJumpApex() override;

	void Landed(const FHitResult & Hit) override;
	
protected:

	UPROPERTY(BlueprintReadWrite, Category = Jump)
	float GlideGravityScale;
};
