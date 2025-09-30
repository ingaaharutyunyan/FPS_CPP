#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "APoison.generated.h"

class APlayerController; //forward declaration
UCLASS()
class FPSCPP_API UPoison : public UActorComponent 
{
    GENERATED_BODY()

public:
    UPoison();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY()
    TWeakObjectPtr<APlayerController> OwningController;

    float TimeSinceLastDamage;
    float DamageInterval;
};