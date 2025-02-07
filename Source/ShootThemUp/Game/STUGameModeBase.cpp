// Shoot Them Up Game, All Right Reserved


#include "STUGameModeBase.h"

#include "AIController.h"
#include "STUGameStateBase.h"
#include "Player/STUBaseCharacter.h"
#include "Player/STUPlayerController.h"




ASTUGameModeBase::ASTUGameModeBase()
{
    DefaultPawnClass = ASTUBaseCharacter::StaticClass();
    PlayerControllerClass = ASTUPlayerController::StaticClass();
}



UClass* ASTUGameModeBase::GetDefaultPawnClassForController_Implementation(AController* InController)
{
   if(InController && InController->IsA<AAIController>())
   {
       return AIPawnClass;
   }
    return Super::GetDefaultPawnClassForController_Implementation(InController);
    
}


