#include <iostream>
#include <string>
#include "Entity.h"
#include "World.h"
#include "EngineComponents.h"
#include "Component.h"



static Engine::World NewScene{};


void UpdatePosition(Engine::World& World) {
	auto view = World.m_Registry.view<Engine::Position>();


	view.each([](Engine::Position& Pos) {
		Pos.X = 919;
		std::cout << Pos.X << " " << Pos.Y << std::endl;
		});
}



int main() {


	for (int i = 0; i < 4; i++)
	{

		std::unique_ptr<Engine::Entity> EcsEntity = NewScene.CreateEntity();

		std::string suffix = "";
		switch (i)
		{
		case (0): {
			suffix = "0";
			break;
		}
		case (1): {
			suffix = "1";
			break;
		}
		case (2): {
			suffix = "2";
			break;
		}
		case (3): {
			suffix = "3";
			break;
		}
		case (4): {
			suffix = "4";
			break;
		}

		default:
			break;
		}

		EcsEntity->AddComponent<Engine::Name>("my created entity " + suffix);
		EcsEntity->AddComponent<Engine::Position>(2.0, 4.0);
		NewScene.RootEntity->AddChild(std::move(EcsEntity));

		if (i == 1) {
			auto& AddedEntity = NewScene.RootEntity->Children.back();
			AddedEntity->AddChild(NewScene.CreateEntity());

		}


	}


	NewScene.SaveScene("nlohmann_data.json");

	NewScene.LoadScene("nlohmann_data.json");

	UpdatePosition(NewScene);


	return 0;
}
