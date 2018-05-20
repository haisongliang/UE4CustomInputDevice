// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"
#include "IInputDeviceModule.h"

class FCustomInputModule : public IInputDeviceModule
{
public:

	/**
	* Singleton-like access to this module's interface.  This is just for convenience!
	* Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	*
	* @return Returns singleton instance, loading the module on demand if needed
	*/
	static inline FCustomInputModule& Get()
	{
		return FModuleManager::LoadModuleChecked< FCustomInputModule >("CustomInput");
	}

	/**
	* Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	*
	* @return True if the module is loaded and ready to use
	*/
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("CustomInput");
	}


	virtual TSharedPtr< class IInputDevice > CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler);

	//virtual void StartupModule() override; // This is not required as IInputDeviceModule handels it!
	virtual void ShutdownModule() override;

	TSharedPtr< class FCustomInputDevice > customInputDevice;
};