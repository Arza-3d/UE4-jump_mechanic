// Part of jump mechanic study in https://arza-3d.github.io/UE4-jump-mechanic/

#include "SprintJumpCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"

ASprintJumpCharacter::ASprintJumpCharacter()
{
	DefaultMaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
	DefaultJumpZVelocity = GetCharacterMovement()->JumpZVelocity;
	MaxSprintSpeed = 1200.0f;
	SprintJumpZVelocity = 1200.0f;
	GradientJumpToSpeed = (SprintJumpZVelocity - DefaultJumpZVelocity) / (MaxSprintSpeed - DefaultMaxWalkSpeed);

	// these are meant to be used for AnimBP (optional):
	bIsSprinting = false;
	bIsInSprintJump = false;
}

void ASprintJumpCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	PlayerInputComponent->BindAction("SecondaryInput", IE_Pressed, this, &ASprintJumpCharacter::Sprint);
	PlayerInputComponent->BindAction("SecondaryInput", IE_Released, this, &ASprintJumpCharacter::StopSprinting);
}

float ASprintJumpCharacter::GetXYSpeed() 
{
	FVector ActorVelocity = GetCapsuleComponent()->GetPhysicsLinearVelocity();
	float xSpeedSquared = UKismetMathLibrary::Square(ActorVelocity.Component(0));
	float ySpeedSquared = UKismetMathLibrary::Square(ActorVelocity.Component(1));
	return UKismetMathLibrary::Sqrt(xSpeedSquared + ySpeedSquared);
}

void ASprintJumpCharacter::Sprint() 
{
	GetCharacterMovement()->MaxWalkSpeed = MaxSprintSpeed;
	bIsSprinting = true;
}

void ASprintJumpCharacter::StopSprinting() 
{
	GetCharacterMovement()->MaxWalkSpeed = DefaultMaxWalkSpeed;
	bIsSprinting = false;
}

void ASprintJumpCharacter::OnJumped_Implementation() 
{
	bIsInSprintJump = (bIsSprinting) ? true : false;
}

void ASprintJumpCharacter::Landed(const FHitResult & Hit)
{
	GetCharacterMovement()->JumpZVelocity = DefaultJumpZVelocity;
	bIsInSprintJump = false;
}

void ASprintJumpCharacter::Jump()
{
	if (GetXYSpeed() > DefaultMaxWalkSpeed && bIsSprinting)
	{
		float NewJumpZVelocity = ((GetXYSpeed() - DefaultMaxWalkSpeed) * GradientJumpToSpeed) + DefaultJumpZVelocity;
		GetCharacterMovement()->JumpZVelocity = NewJumpZVelocity;
	}
	else
	{
		GetCharacterMovement()->JumpZVelocity = DefaultJumpZVelocity;
	}

	Super::Jump();
}