// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HFCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class ACTIONROGUELIKE_API AHFCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHFCharacter();

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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
