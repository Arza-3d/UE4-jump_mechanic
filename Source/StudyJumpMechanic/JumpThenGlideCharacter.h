// Part of jump mechanic study in https://arza-3d.github.io/UE4-jump-mechanic/

#pragma once

#include "CoreMinimal.h"
#include "StudyJumpMechanicCharacter.h"
#include "JumpThenGlideCharacter.generated.h"

/**
 *  Character class with built-in jump then glide
 */
UCLASS()
class STUDYJUMPMECHANIC_API AJumpThenGlideCharacter : public AStudyJumpMechanicCharacter
{
	GENERATED_BODY()

	float DefaultGravityScale;

	bool bJumpInputIsPressed;

	bool bIsAbleToGlide;

public:

	AJumpThenGlideCharacter();

	void Jump() override;

	void StopJumping() override;

	void NotifyJumpApex() override;

	void Landed(const FHitResult & Hit) override;
	
protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Jump Then Glide")
	float GlideGravityScale;

	// is meant to be used for animBP (optional)
	UPROPERTY(BlueprintReadOnly, Category = "Jump Then Glide")
	bool bIsGliding;

};
