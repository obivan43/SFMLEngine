#include "Engine.h"
#include "imgui.h"
#include "utils/Logger.h"

#include <string>

namespace engine 
{

	Engine::Engine(sf::RenderWindow& window) : m_Window(window), m_FPS(0), m_ElapsedTime(0.0f)
	{
		m_AppleCount = 0;
		engine::Logger::Init();
	}

	void Engine::ProcessInput(const sf::Event& e) 
	{
		switch (e.key.code)
		{
		case sf::Keyboard::Up:
			LOG_INFO("Up pressed");
			break;
		case sf::Keyboard::Down:
			LOG_INFO("Down pressed");
			break;
		case sf::Keyboard::Left:
			LOG_INFO("Left pressed");
			break;
		case sf::Keyboard::Right:
			LOG_INFO("Right pressed");
			break;
		}
	}

	void Engine::Update(const sf::Time& time)
	{
		FPS(time);
	}

	void Engine::Render() 
	{
		std::string str = std::to_string(m_AppleCount);
		ImGui::Text(str.c_str());
	}

	void Engine::FPS(const sf::Time& time)
	{
		m_ElapsedTime += time.asSeconds();
		++m_FPS;

		if (m_ElapsedTime > 1.0f) {
			LOG_INFO("FPS: {}", m_FPS);

			m_ElapsedTime = 0.0f;
			m_FPS = 0;
		}
	}

}