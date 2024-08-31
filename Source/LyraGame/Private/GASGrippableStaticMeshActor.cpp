#include "GASGrippableStaticMeshActor.h"

AGASGrippableStaticMeshActor::AGASGrippableStaticMeshActor(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    // Create the Ability System Component
    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

void AGASGrippableStaticMeshActor::BeginPlay()
{
	Super::BeginPlay();
}

UAbilitySystemComponent* AGASGrippableStaticMeshActor::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}