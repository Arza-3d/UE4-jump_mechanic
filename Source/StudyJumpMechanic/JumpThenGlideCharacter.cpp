// Fill out your copyright notice in the Description page of Project Settings.

#include "JumpThenGlideCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AJumpThenGlideCharacter::AJumpThenGlideCharacter()
{
	DefaultGravityScale = GetCharacterMovement()->GravityScale;
	GlideGravityScale = 0.08f;
	bJumpInputIsPressed = false;
	bIsAbleToGlide = false;
}

void AJumpThenGlideCharacter::Landed(const FHitResult & Hit)
{
	bIsAbleToGlide = false;
	GetCharacterMovement()->bNotifyApex = false;
	GetCharacterMovement()->GravityScale = DefaultGravityScale;
}

void AJumpThenGlideCharacter::Jump()
{
	bJumpInputIsPressed = true;

	if (GetCharacterMovement()->IsFalling())
	{
		if (bIsAbleToGlide && bJumpInputIsPressed) {
			GetCharacterMovement()->GravityScale = GlideGravityScale;
		}
	}
	else
	{
		Super::Jump();
		GetCharacterMovement()->bNotifyApex = true;
	}
}

void AJumpThenGlideCharacter::StopJumping()
{
	bJumpInputIsPressed = false;
	GetCharacterMovement()->GravityScale = DefaultGravityScale;
	Super::StopJumping();
}

void AJumpThenGlideCharacter::NotifyJumpApex()
{
	bIsAbleToGlide = true;
	if (bJumpInputIsPressed) {
		GetCharacterMovement()->GravityScale = GlideGravityScale;
	}
}