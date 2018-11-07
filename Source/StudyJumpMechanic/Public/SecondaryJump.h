// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Character.h"
#include "SecondaryJump.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STUDYJUMPMECHANIC_API USecondaryJump : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USecondaryJump();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//ACharacter* character =

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
