// Fill out your copyright notice in the Description page of Project Settings.


#include "MaterialActor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
AMaterialActor::AMaterialActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	RootComponent = MeshComponent;

	Roughness = 0.5f;
	Metallic = 0.0f;
	EmissiveStrength = 0.0f;
	BaseColor = FLinearColor::White;
}

// Called when the game starts or when spawned
void AMaterialActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (BaseMaterial) {
		DynamicMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, this);

		if (DynamicMaterial) {
			MeshComponent->SetMaterial(0, DynamicMaterial);
			UpdateMaterialParameters();
		}
	}
}

// Called every frame
void AMaterialActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateMaterialParameters();
}

void AMaterialActor::UpdateMaterialParameters() {
	if (!DynamicMaterial) return;

	DynamicMaterial->SetScalarParameterValue(TEXT("Roughness"), Roughness);
	DynamicMaterial->SetScalarParameterValue(TEXT("Metallic"), Metallic);
	DynamicMaterial->SetScalarParameterValue(TEXT("EmmissiveStrength"), EmmissiveStrength);

	DynamicMaterial->SetVectorParameterValue(TEXT("BaseColor"), BaseColor);
}

