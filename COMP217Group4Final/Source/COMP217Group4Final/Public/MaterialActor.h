// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MaterialActor.generated.h"

UCLASS()
class COMP217GROUP4FINAL_API AMaterialActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMaterialActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UMaterialInterface* BaseMaterial;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UMaterialInstanceDynamic* DynamicMaterial;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material Parameters")
	float Roughness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material Parameters")
	float Metallic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material Parameters")
	float EmissiveStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material Parameters")
	FLinearColor BaseColor;

	UFUNCTION(BlueprintCallable, Category = "Material")
	void UpdateMaterialParameters();

};
