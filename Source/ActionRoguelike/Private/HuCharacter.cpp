// Fill out your copyright notice in the Description page of Project Settings.


#include "HuCharacter.h"

// Sets default values
AHuCharacter::AHuCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}
