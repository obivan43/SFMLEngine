#include "Logger.h"

namespace engine 
{

	std::shared_ptr<spdlog::logger> Logger::m_Logger;

	void Logger::Init() 
	{
		auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		auto msvc_sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();
		auto dist_sink = std::make_shared<spdlog::sinks::dist_sink_st>();

		dist_sink->add_sink(msvc_sink);
		dist_sink->add_sink(console_sink);

		m_Logger = std::make_shared<spdlog::logger>("SFML engine", dist_sink);
	}

}
