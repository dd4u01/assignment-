#include "SpartaPlayerController.h"
#include "EnhancedInputSubSystems.h"

ASpartaPlayerController::ASpartaPlayerController()
	: InputMappingContext(nullptr), MoveAction(nullptr), /*JumpAction(nullptr),*/ LookAction(nullptr) /*SprintAction(nullptr)*/
{

}

void ASpartaPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// �÷��̾��� �Է��� �����ϴ� ��ü�� �ҷ���
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		// IMC�� �����ϴ� ��ü �ҷ���
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem =
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				// IMC ��ü�� �ִٸ�
				if (InputMappingContext)
				{
					// ���� ���� �켱������ �ο�
					SubSystem->AddMappingContext(InputMappingContext, 0);
				}
			}
	}
}