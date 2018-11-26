// Part of jump mechanic study in https://arza-3d.github.io/UE4-jump-mechanic/

#include "SecondaryJumpCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ASecondaryJumpCharacter::ASecondaryJumpCharacter()
{
	bSecondaryButtonIsPressed = false;
	DefaultJumpZVelocity = GetCharacterMovement()->JumpZVelocity;
	SecondaryJumpZVelocity = 1200.0f;
}

void ASecondaryJumpCharacter::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	PlayerInputComponent->BindAction("SecondaryInput", IE_Pressed, this, &ASecondaryJumpCharacter::SecondaryInputPressed);
	PlayerInputComponent->BindAction("SecondaryInput", IE_Released, this, &ASecondaryJumpCharacter::SecondaryInputReleased);
}

void ASecondaryJumpCharacter::SecondaryInputPressed()
{
	GetCharacterMovement()->JumpZVelocity = SecondaryJumpZVelocity;
	bSecondaryButtonIsPressed = true;
}

void ASecondaryJumpCharacter::SecondaryInputReleased()
{
	GetCharacterMovement()->JumpZVelocity = DefaultJumpZVelocity;
	bSecondaryButtonIsPressed = false;
}

// (option A) is meant to be used for animBP, use this IF character has different jump start animation
void ASecondaryJumpCharacter::Jump()
{
	if (bSecondaryButtonIsPressed)
	{
		bIsInSecondaryJump = true;
	}

	Super::Jump();
}

/*
// (option B) is meant to be used for animBP, use this IF character has same jump start animation but different jump animation while in the air
void ASecondaryJumpCharacter::OnJumped_Implementation()
{
	if (bSecondaryButtonIsPressed)
	{
		bIsInSecondaryJump = true;
	}
}
*/

// is meant to be used for animBP, if you don't use different jump animation this is not needed
void ASecondaryJumpCharacter::Landed(const FHitResult & Hit)
{
	bIsInSecondaryJump = false;
	OnLanded(Hit); // the last two line is the default definition of this function from Character.h
	LandedDelegate.Broadcast(Hit); // broadcast to EventOnLanded blueprint
}
