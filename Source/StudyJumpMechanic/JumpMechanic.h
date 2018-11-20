// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JumpMechanic.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STUDYJUMPMECHANIC_API UJumpMechanic : public UActorComponent
{
	GENERATED_BODY()

	class ACharacter* MyCharacter;
	//class UCharacterMovementComponent* MyMovement;


public:	
	UJumpMechanic();

	UFUNCTION(BlueprintCallable, Category = "Power")
	void SetJumpZVelocity(float JumpZ);

protected:
	virtual void BeginPlay() override;


public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FORCEINLINE class ACharacter* GetMyCharacter() const { return MyCharacter; }
	
	//FORCEINLINE class UCharacterMovementComponent* GetMyMovement() const { return MyMovement; }
};
