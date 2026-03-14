// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "RotatingPulsingOrb.generated.h"

UCLASS()
class COMP217LAB3_API ARotatingPulsingOrb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatingPulsingOrb();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UPointLightComponent* Light;

	// Rotation Speed & Light Pulse Speed
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FRotator RotationSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float PulseSpeed;


	// Functions
	UFUNCTION(BlueprintCallable)
	void ToggleLight(bool bEnable);

	UFUNCTION(BlueprintCallable)
	void SetRotationSpeed(FRotator NewSpeed);

	UFUNCTION(BlueprintCallable)
	void SetLightColor(FLinearColor NewColor);

};
