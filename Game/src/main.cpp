#include "imgui.h"
#include "imgui-SFML.h"

#include "Engine/src/Engine.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Engine", sf::Style::Default, settings);
	ImGui::SFML::Init(window);

	sf::Clock clock;
	sf::Time elapsed;

	engine::Engine sfmlEngine{ window };
	while (window.isOpen())
	{
		elapsed = clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);
			switch (event.type) 
			{
				case sf::Event::Closed:
					window.close();
				break;

				case sf::Event::KeyPressed:
					sfmlEngine.ProcessInput(event);
				break;

				default: break;
			};
		}
		
		ImGui::SFML::Update(window, elapsed);
		sfmlEngine.Update(elapsed);

		window.clear(sf::Color::Yellow);
		sfmlEngine.Render();
		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();

	return 0;
}