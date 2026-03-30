#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolLocation.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOJPROJEKT_API UPatrolLocation : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPatrolLocation();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
		
public:

	UFUNCTION(BlueprintCallable, Category = "Patrol")
	FVector GetPatrolLocation();
};
