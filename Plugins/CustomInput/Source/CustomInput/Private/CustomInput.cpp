// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "CustomInput.h"
#include "CustomInputDevice.h"

#define LOCTEXT_NAMESPACE "FCustomInputModule"

TSharedPtr<class IInputDevice> FCustomInputModule::CreateInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
{
	UE_LOG(LogTemp, Display, TEXT("CustomInputDevice created!"));
	return MakeShareable(new FCustomInputDevice(InMessageHandler));
}

void FCustomInputModule::ShutdownModule()
{
	UE_LOG(LogTemp, Display, TEXT("CustomInputDevice shutdown!"));

	// Unregister our input device module
	IModularFeatures::Get().UnregisterModularFeature(IInputDeviceModule::GetModularFeatureName(), this);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCustomInputModule, CustomInput)