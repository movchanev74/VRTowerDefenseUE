#pragma once

#include "CoreMinimal.h"
#include "Grippables/GrippableStaticMeshActor.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "GASGrippableStaticMeshActor.generated.h"

UCLASS()
class LYRAGAME_API AGASGrippableStaticMeshActor : public AGrippableStaticMeshActor, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGASGrippableStaticMeshActor(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Implement IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

private:
	// Ability System Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities", meta = (AllowPrivateAccess = "true"))
	UAbilitySystemComponent* AbilitySystemComponent;

	// Attributes (you can define a custom attribute set here)
	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities", meta = (AllowPrivateAccess = "true"))
	// UYourCustomAttributeSet* AttributeSet;
};
