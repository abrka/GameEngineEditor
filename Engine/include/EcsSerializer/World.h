#pragma once

#include "entt/entt.hpp"
//#include <vector>
#include "ComponentFactory.h"


namespace Engine {

	using json = nlohmann::json;

	class World
	{
		friend class Entity;

	public:
		World() {};
		entt::registry m_Registry{};
		//std::vector<Entity*> m_Entities{};
		ComponentFactory m_CompFactory{};
		std::unique_ptr<Entity> RootEntity = CreateEntity();

		std::unique_ptr<Entity> CreateEntity();
		std::unique_ptr<Entity> CreateEntity(json& EntityJson);
		void RemoveEntityFromRegistry(Engine::Entity& Entity);
		std::vector<Entity*> GetAllEntities();
		Engine::Entity* FindEntityParentFromUUID(Engine::Entity* Ent);

		void SaveScene(std::string OutFilePath);
		void DestroyAllEntities();
		bool IsRootEntity(Engine::Entity& Ent);
		void LoadScene(std::string InFilePath);
	};
	
}
