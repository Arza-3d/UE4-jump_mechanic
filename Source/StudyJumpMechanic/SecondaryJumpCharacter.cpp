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

// for animBP (optional)
void ASecondaryJumpCharacter::Jump()
{
	if (bSecondaryButtonIsPressed)
	{
		bIsInSecondaryJump = true;
	}

	Super::Jump();
}

// for animBP (optional)
void ASecondaryJumpCharacter::Landed(const FHitResult & Hit)
{
	bIsInSecondaryJump = false;
	OnLanded(Hit); 
	LandedDelegate.Broadcast(Hit);
}
