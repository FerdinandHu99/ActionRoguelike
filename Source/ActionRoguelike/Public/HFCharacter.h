// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Logging/LogMacros.h"
#include "HFCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class ACTIONROGUELIKE_API AHFCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	// Sets default values
	AHFCharacter()
	{
		// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
		PrimaryActorTick.bCanEverTick = true;

		SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
		SpringArmComp->SetupAttachment(RootComponent);
		SpringArmComp->bUsePawnControlRotation = true;

		CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
		CameraComp->SetupAttachment(SpringArmComp);

		GetCharacterMovement()->bOrientRotationToMovement = true;

		bUseControllerRotationYaw = false;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 为角色增加一个弹簧臂组件
	UPROPERTY(VisibleAnywhere);
	USpringArmComponent* SpringArmComp;

	// 为角色增加一个摄像头组件
	UPROPERTY(VisibleAnywhere);
	UCameraComponent* CameraComp;

	// 角色前向移动
	void MoveForward(float value);

	// 角色左右移动
	void MoveRight(float value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
