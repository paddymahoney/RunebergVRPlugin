// Copyright (C) 2016  Runeberg (github: 1runeberg, UE4 Forums: runeberg)

#pragma once

#include "Components/ActorComponent.h"
#include "VRPawnComponent_Targetter.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VR_CPP_API UVRPawnComponent_Targetter : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UVRPawnComponent_Targetter();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	// See if targetting system is active / visible
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VR")
	bool IsTargetting = false;

	// Starting Distance Offset of Teleport Marker (Mesh or Particle System)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VR")
	float RespawnDistance = 0.0f;
	
	// Minimum range for teleport
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VR")
	int MinRange = 125;

	// Maximum range for teleport
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VR")
	int MaxRange = 1000;

	// Marker Location
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VR")
	FVector MarkerLocation = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VR")
	FRotator MarkerRotation = FRotator::ZeroRotator;

	UFUNCTION(BlueprintCallable, Category = "VR")
	void SpawnMarker(USceneComponent* TargettingSource, float Distance, bool FixedRotation = true, bool AtFloor = true, UParticleSystem* UseThisParticleSystem = nullptr, UStaticMesh* UseThisStaticMesh = nullptr);

	// Move Marker
	UFUNCTION(BlueprintCallable, Category = "VR")
		void MoveMarker(USceneComponent* TargettingSource = nullptr, bool MoveForward = false, bool MoveRight = false, bool MoveBack = false, bool MoveLeft = false, int Rate = 25);
	// Remove marker
	UFUNCTION(BlueprintCallable, Category = "VR")
	void RemoveMarker();

	// Teleport
	UFUNCTION(BlueprintCallable, Category = "VR")
	void TeleportObject(AActor* ObjectToTeleport, USceneComponent* TargettingSource = nullptr, bool ReSpawnMarker = true);

private:
	// Location indicators for targettign marker
	bool IsMarkerAtFloor = false;
	bool IsMarkerRotationFixed = false;

	// Spawned visible components for targetting marker
	UParticleSystemComponent* ParticleSystemComponent = nullptr;
	UStaticMeshComponent* StaticMeshComponent = nullptr;
};