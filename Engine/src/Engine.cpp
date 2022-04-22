#include "Engine.h"
#include "utils/Logger.h"

namespace engine 
{

	Engine::Engine(sf::RenderWindow& window) : m_Window(window), m_FPS(0), m_ElapsedTime(0.0f), m_Shape(100.0f) 
	{
		engine::Logger::Init();

		m_Shape.setFillColor(sf::Color::Yellow);
	}

	void Engine::Update(const sf::Time& time)
	{
		FPS(time);
	}

	void Engine::Render() 
	{
		m_Window.draw(m_Shape);
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