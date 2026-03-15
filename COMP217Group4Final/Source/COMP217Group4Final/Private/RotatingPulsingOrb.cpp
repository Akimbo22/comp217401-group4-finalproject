// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingPulsingOrb.h"

// Sets default values
ARotatingPulsingOrb::ARotatingPulsingOrb()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Root
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	// Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	// Light
	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	Light->SetupAttachment(Root);
	Light->Intensity = 5000.f;
	Light->bUseInverseSquaredFalloff = false;

	//Material
	//Material = CreateDefaultSubobject<UMaterial>(TEXT("Material"));
	//Material->Set

	// Default settings
	RotationSpeed = FRotator(0.f, 45.f, 0.f);
	PulseSpeed = 1.f;

}

// Called when the game starts or when spawned
void ARotatingPulsingOrb::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ARotatingPulsingOrb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Rotation
	AddActorLocalRotation(RotationSpeed * DeltaTime);


	if (Light)
	{
		// Light Pulse
		float NewIntensity = 3000.f + 2000.f * FMath::Sin(GetWorld()->GetTimeSeconds() * PulseSpeed);
		Light->SetIntensity(NewIntensity);

		// Light Color
		float Hue = FMath::Fmod(GetWorld()->GetTimeSeconds() * 50.f, 360.f);
		FLinearColor NewColor = FLinearColor::MakeFromHSV8((uint8)Hue, 255, 255);
		Light->SetLightColor(NewColor);
	}

}

void ARotatingPulsingOrb::ToggleLight(bool bEnable)
{
	if (Light)
	{
		Light->SetVisibility(bEnable);
	}
}

void ARotatingPulsingOrb::SetRotationSpeed(FRotator NewSpeed)
{
	RotationSpeed = NewSpeed;
}

void ARotatingPulsingOrb::SetLightColor(FLinearColor NewColor)
{
	if (Light)
	{
		Light->SetLightColor(NewColor);
	}
}
