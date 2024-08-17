// Shoot Them Up Game, All Right Reserved


#include "STUHealthPercentDecorator.h"
#include "AIController.h"
#include "STUUtils.h"
#include "Components/STUHealthComponent.h"


USTUHealthPercentDecorator::USTUHealthPercentDecorator()
{
	NodeName = "Health Percent";
}

bool USTUHealthPercentDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	const auto Controller = OwnerComp.GetAIOwner();
	if(!Controller) return false;

	const auto HealthComponent = StuUtils::GetSTUPlayerComponent<USTUHealthComponent>(Controller->GetPawn());
	if(!HealthComponent || HealthComponent->IsDead()) return false;

	return HealthComponent->GetHealthPercent() <= HealthPercent;
	
	
}