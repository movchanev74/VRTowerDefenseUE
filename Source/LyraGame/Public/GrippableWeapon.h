// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GASGrippableStaticMeshActor.h"
#include "GrippableWeapon.generated.h"

/**
 * 
 */
UCLASS()
class LYRAGAME_API AGrippableWeapon : public AGASGrippableStaticMeshActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	FTransform GetMuuzleTransform();
};
