#include "CustomInput.h"
#include "CustomInputDevice.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"
#include "core.h"

const FKey TestKey("TestKey");
const FKey TestAxis("TestAXIS");

FCustomInputDevice::FCustomInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
	:MessageHandler(InMessageHandler)
{
	EKeys::AddKey(FKeyDetails(TestKey, FText::FromString("TestKey"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(TestAxis, FText::FromString("TestAXIS"), FKeyDetails::FloatAxis));
} 

FCustomInputDevice::~FCustomInputDevice()
{
}

void FCustomInputDevice::Tick(float DeltaTime)
{
}

void FCustomInputDevice::SendControllerEvents()
{
	//在此触发输入和输出事件
	MessageHandler->OnControllerAnalog(TestAxis.GetFName(), 0, FMath::FRandRange(0, 1));
	
	// if ()
	// {
	// 	MessageHandler->OnControllerButtonPressed(TestKey.GetFName(), 0, false);
	// }
	// else
	// {
	// 	MessageHandler->OnControllerButtonReleased(TestKey.GetFName(), 0, false);
	// }
}

void FCustomInputDevice::SetMessageHandler(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler)
{
	MessageHandler = InMessageHandler;
}

bool FCustomInputDevice::Exec(UWorld * InWorld, const TCHAR * Cmd, FOutputDevice & Ar)
{
	return false;
}

void FCustomInputDevice::SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value)
{
}

void FCustomInputDevice::SetChannelValues(int32 ControllerId, const FForceFeedbackValues & values)
{
}
