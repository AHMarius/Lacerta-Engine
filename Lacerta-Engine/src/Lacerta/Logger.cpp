#include "Logger.h"
#include <memory>
#include <spdlog/sinks/stdout_color_sinks.h> 

namespace Lacerta
{
	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

	void Logger::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$"); // Set the logging pattern
		s_CoreLogger = spdlog::stdout_color_mt("LACERTA");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("CLIENT");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}