#include "GASGrippableStaticMeshActor.h"

AGASGrippableStaticMeshActor::AGASGrippableStaticMeshActor(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    // Create the Ability System Component
    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

    if (AbilitySystemComponent)
    {
        //HealthSet = CreateDefaultSubobject<ULyraHealthSet>(TEXT("HealthSet"));
        CombatSet = CreateDefaultSubobject<ULyraCombatSet>(TEXT("CombatSet"));
        //CombatSet = CreateDefaultSubobject<ULyraCombatSet>(TEXT("CombatSet"));
        //AbilitySystemComponent->InitStats(ULyraCombatSet::StaticClass(), nullptr);
    }
}

void AGASGrippableStaticMeshActor::BeginPlay()
{
	Super::BeginPlay();
}

UAbilitySystemComponent* AGASGrippableStaticMeshActor::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}