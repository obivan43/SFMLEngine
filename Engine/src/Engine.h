#pragma once

#include "SFML/Graphics.hpp"

namespace engine 
{

	class Engine 
	{
		public:
			Engine(sf::RenderWindow& window);

			sf::RenderWindow& GetWindow() { return m_Window; }

			void ProcessInput(const sf::Event& event);
			void Update(const sf::Time& time);
			void Render();

		private:
			void FPS(const sf::Time& time);

		private:
			sf::RenderWindow& m_Window;

			int32_t m_FPS;
			float m_ElapsedTime;
			int m_AppleCount;
	};

}
