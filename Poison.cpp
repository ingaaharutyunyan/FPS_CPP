
#include "APoison.h"
#include "FPSCPPCharacter.h"
#include "Engine/Engine.h"

UPoison::UPoison()
{
    PrimaryActorTick.bCanEverTick = true;

    OwningCharacter = nullptr;
    TimeSinceLastDamage = 0.0f;
    DamageInterval = 1.0f;
}

void UPoison::BeginPlay()
{
    Super::BeginPlay();

    OwningController = Cast<APlayerController>(GetOwner());
    OwningController->GetPawn();
}

void UPoison::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (Character)
    {
        TimeSinceLastDamage += DeltaTime;

        if (TimeSinceLastDamage >= DamageInterval)
        {
            // Use the UpdateHealth function instead of directly modifying hp
            Character->UpdateHealth(-1.0f);

            // Debug message
            /*if (GEngine)
            {
                FString DamageMessage = FString::Printf(TEXT("Poison damage! HP: %.1f"), Character->hp);
                GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, DamageMessage);
            }

            UE_LOG(LogTemp, Warning, TEXT("Poison damage applied. Current HP: %.1f"), Character->hp);*/

            // Reset timer
            TimeSinceLastDamage = 0.0f;
        }
    }
}