// Fill out your copyright notice in the Description page of Project Settings.


#include "HFCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AHFCharacter::AHFCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void AHFCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHFCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
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

	// 为角色组件绑定输入轴Turn，实现转向功能
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}

