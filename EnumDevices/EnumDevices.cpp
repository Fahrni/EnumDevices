// EnumDevices.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "PelcoSDK/PelcoSDK.h"
#include "PelcoSDK/SystemCollection.h"
#include "PelcoSDK/System.h"
#include "PelcoSDK/Exception.h"

class PelcoSDKInitializer
{
public:
	PelcoSDKInitializer() : _hr(NOERROR)
	{
		// Always use COINIT_MULTITHREADED for the Pelco SDK
		_hr = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
		if (SUCCEEDED(_hr))
		{
			// Call PelcoSDK Startup()
			try	{ PelcoSDK::Startup(); }
			catch (PelcoSDK::Exception& /*ex*/) 
			{ 
				// Cannot continue
				::CoUninitialize();
				_hr = E_FAIL;
			}
		}
	}

	// Destructor for the class calls CoUnitialize
	virtual ~PelcoSDKInitializer()
	{
		if (SUCCEEDED(_hr))
		{
			// Call PelcoSDK Shutdown()
			try { PelcoSDK::Shutdown(); }
			catch (PelcoSDK::Exception& /*ex*/) { /* Add your logging code here */ }

			::CoUninitialize();
		}

		_hr = E_FAIL;
	}

	bool IsReady() { return SUCCEEDED(_hr); }
	
private:
	HRESULT _hr;
};

static void EnumDevices()
{
	// Create or get an existing system
	PelcoSDK::System system("admin:admin@pelcosystem://10.221.224.36:60001?alias=Clovis");

	// Get the Device Collection from the system
	PelcoSDK::DeviceCollection devices(system.GetDeviceCollection());

	// Iterate over the DeviceCollection and print out the device friendly name.
	devices.Reset();
	while (devices.MoveNext())
	{
		PelcoSDK::Device device(devices.Current());
		printf("Device Friendly Name: %s\n", device.GetFriendlyName().c_str());
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		PelcoSDKInitializer pelcoSDK;
		if (pelcoSDK.IsReady())
		{
			EnumDevices();
		}
	}
	catch (PelcoSDK::Exception& ex)
	{
		printf("EnumDevices caught an SDK Exception: %s\n", ex.Message().c_str());
	}
	return 0;
}

