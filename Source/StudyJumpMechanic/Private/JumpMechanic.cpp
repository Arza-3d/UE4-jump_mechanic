// Fill out your copyright notice in the Description page of Project Settings.

#include "JumpMechanic.h"


// Sets default values for this component's properties
UJumpMechanic::UJumpMechanic()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UJumpMechanic::BeginPlay()
{
	Super::BeginPlay();
	//UKismetSystemLibrary::PrintString(this, "printStringTest", true, true, ,5.0F);
	//float jumpHeight = 300.0f;
	//AActor *MyCharacter = AActor::GetOwner;
	//UCharacterMovementComponent::JumpZVelocity = Sqrt(2 * UCharacterMovementComponent.GetGravityZ() * UCharacterMovementComponent.GravityScale * jumpHeight);
	
}


// Called every frame
void UJumpMechanic::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

