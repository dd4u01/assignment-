#include "SpartaPlayerController.h"
#include "EnhancedInputSubSystems.h"

ASpartaPlayerController::ASpartaPlayerController()
	: InputMappingContext(nullptr), MoveAction(nullptr), /*JumpAction(nullptr),*/ LookAction(nullptr) /*SprintAction(nullptr)*/
{

}

void ASpartaPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// 플레이어의 입력을 관리하는 객체를 불러옴
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		// IMC를 관리하는 객체 불러옴
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem =
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				// IMC 객체가 있다면
				if (InputMappingContext)
				{
					// 가장 높은 우선순위를 부여
					SubSystem->AddMappingContext(InputMappingContext, 0);
				}
			}
	}
}