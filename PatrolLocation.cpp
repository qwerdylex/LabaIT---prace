#include "PatrolLocation.h"

// Sets default values for this component's properties
UPatrolLocation::UPatrolLocation()
{

	PrimaryComponentTick.bCanEverTick = true;

}

FVector UPatrolLocation::GetPatrolLocation()
{
	FVector Location = GetOwner()->GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("Dzieki dziala"));
	return Location;
}


// Called when the game starts
void UPatrolLocation::BeginPlay()
{
	Super::BeginPlay();
	FVector PatrolLocation = GetPatrolLocation();
}

void UPatrolLocation::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

