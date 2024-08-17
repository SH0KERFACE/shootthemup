// Shoot Them Up Game, All Right Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STUCoreTypes.h" 
#include "STUHealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTTHEMUP_API USTUHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	USTUHealthComponent();

	float GetHealth() const {return Health;}

	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetHealthPercent() const {return Health/MaxHealth;};
	
	UFUNCTION(BlueprintCallable, Category = "Health")
	bool IsDead() const {return FMath::IsNearlyZero(Health);}

	bool TryToAddHealth(float HealthAmount);
	bool IsHealthFull() const;
	
	FOnDeath OnDeath;
	FOnHealthChanged OnHealthChanged;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta=(ClampMin = "1", ClampMax = "1000"))
	float MaxHealth = 100.0f;

	UPROPERTY(EditAnywhere)
	float DamageCoef = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal")
	bool AutoHeal = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (EditCondition = "AutoHeal"))
	float HealUpdateTime = 1.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (EditCondition = "AutoHeal"))
	float HealDelay = 3.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (EditCondition = "AutoHeal"))
	float HealModifier = 5.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	TSubclassOf<UCameraShakeBase> CameraShake;
private:
	float Health = 0.0f;
	FTimerHandle HealTimerHandle;
	
    UFUNCTION()
	void OnTakeAnyDamage(AActor* DamageActor, float Damage, const  UDamageType* DamageType,
    					AController* InstigatorBy, AActor* DamageCauser);
   
     
	void HealUpdate();
	void SetHealth(float NewHealth);

	void PlayCameraShake();

	void Killed(AController* KillerController);
}; 