#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/dist_sink.h>
#include <spdlog/sinks/msvc_sink.h>
#include <spdlog/sinks/ostream_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <memory>

namespace engine
{

	class Logger 
	{

		public:
			Logger() = delete;
			Logger(const Logger& other) = delete;
			Logger(Logger&& other) noexcept = delete;

			Logger& operator=(const Logger& other) = delete;
			Logger& operator=(Logger&& other) noexcept = delete;

			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetLogger() noexcept { return m_Logger; }

		private:
			static std::shared_ptr<spdlog::logger> m_Logger;
	};

}

#ifdef LOG_ENABLED

#define LOG_TRACE(...)	engine::Logger::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)	engine::Logger::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)	engine::Logger::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)	engine::Logger::GetLogger()->error(__VA_ARGS__)
#define LOG_DEBUG(...)	engine::Logger::GetLogger()->debug(__VA_ARGS__)

#else

#define LOG_TRACE(...)
#define LOG_INFO(...)
#define LOG_WARN(...)
#define LOG_ERROR(...)
#define LOG_DEBUG(...)

#endif
