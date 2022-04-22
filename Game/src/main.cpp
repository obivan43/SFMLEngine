#include "imgui.h"
#include "imgui-SFML.h"

#include "Engine/src/Engine.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Engine");
	ImGui::SFML::Init(window);

	sf::Clock clock;
	sf::Time elapsed;

	engine::Engine gameEngine{ window };
	while (window.isOpen())
	{
		elapsed = clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		ImGui::SFML::Update(window, elapsed);
		gameEngine.Update(elapsed);

		ImGui::Begin("window");
		ImGui::Text("Hello");
		ImGui::End();

		window.clear();
		gameEngine.Render();
		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();

	return 0;
}