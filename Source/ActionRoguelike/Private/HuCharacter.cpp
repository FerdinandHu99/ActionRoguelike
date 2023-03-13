// Fill out your copyright notice in the Description page of Project Settings.


#include "HuCharacter.h"

// Sets default values
AHuCharacter::AHuCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

}
// 输入轴MoveForward绑定的函数
void AHuCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

// Called when the game starts or when spawned
void AHuCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHuCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHuCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 移动组件绑定输入轴MoveForward、Turn
	PlayerInputComponent->BindAxis("MoveForward", this, &AHuCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}

