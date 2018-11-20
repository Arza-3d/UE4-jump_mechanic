// Fill out your copyright notice in the Description page of Project Settings.

#include "SprintJump_autoCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"

ASprintJump_autoCharacter::ASprintJump_autoCharacter()
{
	DefaultJumpZVelocity = GetCharacterMovement()->JumpZVelocity;
	MaxJumpZVelocity = 1200.0f;
	GradientJumpToSpeed = (MaxJumpZVelocity - DefaultJumpZVelocity) / GetCharacterMovement()->MaxWalkSpeed;
}

float ASprintJump_autoCharacter::GetXYSpeed()
{
	FVector ActorVelocity = GetCapsuleComponent()->GetPhysicsLinearVelocity();
	float xSpeedSquared = UKismetMathLibrary::Square(ActorVelocity.Component(0));
	float ySpeedSquared = UKismetMathLibrary::Square(ActorVelocity.Component(1));
	return UKismetMathLibrary::Sqrt(xSpeedSquared + ySpeedSquared);
}

void ASprintJump_autoCharacter::Jump() 
{
	float NewJumpZVelocity = GradientJumpToSpeed * GetXYSpeed() + DefaultJumpZVelocity;
	GetCharacterMovement()->JumpZVelocity = NewJumpZVelocity;
	Super::Jump();
}

void ASprintJump_autoCharacter::Landed(const FHitResult & Hit)
{
	GetCharacterMovement()->JumpZVelocity = DefaultJumpZVelocity;
}