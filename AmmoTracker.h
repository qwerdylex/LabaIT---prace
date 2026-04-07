#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AmmoTracker.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOJPROJEKT_API UAmmoTracker : public UActorComponent
{
	GENERATED_BODY()

public:	

	UAmmoTracker();
	UFUNCTION(BlueprintCallable)
	void OnShotFired(int32 Ammo1);
	void SetAmmoBool(bool bHaveAmmo);
	UFUNCTION(BlueprintCallable)
	int32 GetAmmoFromBP();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	int32 GetAmmo() const;
		
};
