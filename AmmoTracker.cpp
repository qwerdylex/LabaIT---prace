#include "AmmoTracker.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"



UAmmoTracker::UAmmoTracker()
{
	
	PrimaryComponentTick.bCanEverTick = true;

	
}



void UAmmoTracker::BeginPlay()
{
	Super::BeginPlay();
	
}


void UAmmoTracker::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

int32 UAmmoTracker::GetAmmo() const
{
	int32 Ammo1 = 10;

	AActor* Owner = GetOwner();
	if (!Owner) return Ammo1;

	FProperty* Prop = Owner->GetClass()->FindPropertyByName(FName("Ammo1"));

	if (FIntProperty* IntProp = CastField<FIntProperty>(Prop))
	{
		Ammo1 = IntProp->GetPropertyValue_InContainer(Owner);
	}

	if (!Prop)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Ammo1 NOT FOUND"));
	}

	return Ammo1;
}

void UAmmoTracker::SetAmmoBool(bool bHaveAmmo)
{
	APawn* PawnOwner = Cast<APawn>(GetOwner());
	if (!PawnOwner) return;

	AAIController* AIController = Cast<AAIController>(PawnOwner->GetController());
	if (!AIController) return;

	UBlackboardComponent* Blackboard = AIController->GetBlackboardComponent();
	if (!Blackboard) return;

	Blackboard->SetValueAsBool("HaveAmmo", bHaveAmmo);
}


void UAmmoTracker::OnShotFired(int32 Ammo1)
{
	
	bool bHaveAmmo = Ammo1 > 0;

	SetAmmoBool(bHaveAmmo);


	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage
		(
			-1,
			2.0f,
			FColor::Green,
			FString::Printf
			(
				TEXT("Ammo: %d"), Ammo1
			)
		);

	}

	if (Ammo1 <= 0)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage
			(
				-1,
				3.0f,
				FColor::Red,
				TEXT("NPC is out of ammo!")
			);
		}
	}

	}

int32 UAmmoTracker::GetAmmoFromBP()
{
	AActor* Owner = GetOwner();
	if (!Owner) return 0;

	UFunction* Func = Owner->FindFunction(FName("GetAmmo1"));

	if (Func)
	{
		int32 Ammo = 0;
		Owner->ProcessEvent(Func, &Ammo);
		return Ammo;
	}

	return 0;
}
