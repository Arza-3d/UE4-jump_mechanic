// Part of jump mechanic study in https://arza-3d.github.io/UE4-jump-mechanic/

#include "JumpThenGlideCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AJumpThenGlideCharacter::AJumpThenGlideCharacter()
{
	DefaultGravityScale = GetCharacterMovement()->GravityScale;
	GlideGravityScale = 0.08f;
	bJumpInputIsPressed = false;
	bIsAbleToGlide = false;

	// is meant to be used with animBP (optional)
	bIsGliding = false;
}

void AJumpThenGlideCharacter::Landed(const FHitResult & Hit)
{
	bIsAbleToGlide = false;
	GetCharacterMovement()->bNotifyApex = false;
	GetCharacterMovement()->GravityScale = DefaultGravityScale;
	bIsGliding = false;
	OnLanded(Hit); // the last two line is the default definition of this function from Character.h
	LandedDelegate.Broadcast(Hit); // broadcast to EventOnLanded blueprint
}

void AJumpThenGlideCharacter::Jump()
{
	bJumpInputIsPressed = true;

	if (GetCharacterMovement()->IsFalling())
	{
		if (bIsAbleToGlide && bJumpInputIsPressed) {
			GetCharacterMovement()->GravityScale = GlideGravityScale;
			bIsGliding = true;
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
	bIsGliding = false;
	Super::StopJumping();
}

void AJumpThenGlideCharacter::NotifyJumpApex()
{
	bIsAbleToGlide = true;
	if (bJumpInputIsPressed) {
		GetCharacterMovement()->GravityScale = GlideGravityScale;
		bIsGliding = true;
	}
}
