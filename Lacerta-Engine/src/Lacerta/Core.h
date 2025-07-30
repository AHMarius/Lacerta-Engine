#pragma once
#ifdef LCT_PLATFORM_WINDOWS
	#ifdef LCT_BUILD_DLL
#		define LCT_API __declspec(dllexport)
#else
#		define LCT_API __declspec(dllimport)
	#endif // LCT_BUILD_DLL
#else
#	error Lacerta Engine only supports Windows platform at the moment.
#endif // !LCT_PLATFORM_WINDOWS
