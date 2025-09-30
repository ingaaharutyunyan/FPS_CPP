#include "AHealth_Restore.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/Engine.h"
#include "FPSCPPCharacter.h"

AHealth_Restore::AHealth_Restore()
{
    PrimaryActorTick.bCanEverTick = false;

    CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
    RootComponent = CollisionBox;

    CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AHealth_Restore::OnOverlapBegin);
}

void AHealth_Restore::BeginPlay()
{
    Super::BeginPlay();
}

void AHealth_Restore::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    if (!OtherActor || OtherActor == this) return;

    // Display debug message in the editor
    if (GEngine)
    {
        FString DebugMessage = FString::Printf(TEXT("collided with object: %s"), *OtherActor->GetName());
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, DebugMessage);
    }

    // Also log to output log
    UE_LOG(LogTemp, Warning, TEXT("collided with object: %s"), *OtherActor->GetName());

    // Health restoration logic
    AFPSCPPCharacter* Character = Cast<AFPSCPPCharacter>(OtherActor);
    if (Character && Character->hp < 100.0f)
    {
        // Use the UpdateHealth function
        Character->UpdateHealth(HealthToRestore);

        // Destroy the health restore actor after use
        Destroy();
    }
}