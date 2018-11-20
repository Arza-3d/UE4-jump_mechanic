// The base actor component for jump mechanic,
// will deal with basic jump mechanic function

#include "JumpMechanic.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine.h"


UJumpMechanic::UJumpMechanic()
{

	PrimaryComponentTick.bCanEverTick = false;

}


void UJumpMechanic::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* MyCharacter = Cast<ACharacter>(GetOwner());
	//UCharacterMovementComponent* MyMovement = MyCharacter->GetCharacterMovement();

}


void UJumpMechanic::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UJumpMechanic::SetJumpZVelocity(float JumpZ)
{
	if (MyCharacter) {
		MyCharacter->GetCharacterMovement()->JumpZVelocity = JumpZ;
	}
	

	//FString JumpZText = (FString) MyMovement->JumpZVelocity;

	//if (MyMovement->JumpZVelocity)
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("OK"));
	
}

