// Fill out your copyright notice in the Description page of Project Settings.


#include "HFCharacter.h"

// Called when the game starts or when spawned
void AHFCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHFCharacter::MoveForward(float value)
{
	FRotator ControlRot = GetControlRotation();
	
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;
	//UE_LOG(LogTemp, Warning, TEXT("Character Rotation: %s"), *ControlRot.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("Character Rotation Vector: %s"), *ControlRot.Vector().ToString());
	AddMovementInput(ControlRot.Vector(), value);
	
}

void AHFCharacter::MoveRight(float value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);
	AddMovementInput(RightVector, value);

	/*ControlRot.Yaw += 90.0f;
	AddMovementInput(ControlRot.Vector(), value);*/
}

// Called every frame
void AHFCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHFCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// 为角色输入组件绑定输入轴MoveForward，实现前后移动功能
	PlayerInputComponent->BindAxis("MoveForward", this, &AHFCharacter::MoveForward);

	// 为角色输入组件绑定输入轴MoveRight，实现左右移动功能
	PlayerInputComponent->BindAxis("MoveRight", this, &AHFCharacter::MoveRight);

	// 为角色组件绑定输入轴Turn，实现转向功能
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);

	// 为角色组件绑定输入轴LookUp，实现上下视角改变
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

