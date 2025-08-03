#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Lacerta {


	class LCT_API Logger
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCore() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClient() { return s_ClientLogger; }
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};


}
// Core log macros
#define LCT_CORE_TRACE(...)		::Lacerta::Logger::GetCore()->trace(__VA_ARGS__)
#define LCT_CORE_INFO(...)		::Lacerta::Logger::GetCore()->info(__VA_ARGS__)
#define LCT_CORE_WARN(...)		::Lacerta::Logger::GetCore()->warn(__VA_ARGS__)
#define LCT_CORE_ERROR(...)		::Lacerta::Logger::GetCore()->error(__VA_ARGS__)
#define LCT_CORE_FATAL(...)		::Lacerta::Logger::GetCore()->fatal(__VA_ARGS__)
// Client log macros
#define LCT_CLIENT_TRACE(...)	::Lacerta::Logger::GetClient()->trace(__VA_ARGS__)
#define LCT_CLIENT_INFO(...)	::Lacerta::Logger::GetClient()->info(__VA_ARGS__)
#define LCT_CLIENT_WARN(...)	::Lacerta::Logger::GetClient()->warn(__VA_ARGS__)
#define LCT_CLIENT_ERROR(...)	::Lacerta::Logger::GetClient()->error(__VA_ARGS__)
#define LCT_CLIENT_FATAL(...)	::Lacerta::Logger::GetClient()->fatal(__VA_ARGS__)

//if in distribution mode, disable logging
//#define LCT_CORE_INFO
//#define LCT_CORE_WARN
//#define LCT_CORE_ERROR
//#define LCT_CORE_FATAL
