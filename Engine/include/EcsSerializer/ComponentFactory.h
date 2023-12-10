#pragma once

#include <string>
#include <map>
#include "Component.h"
#include <memory>

namespace Engine {

	class Entity;

	class ComponentFactory {

	public:
		ComponentFactory();
		

		void AddComponentFromType(std::string Type, nlohmann::json& CompJson, Engine::Entity& TargetEntity);

	private:

		using ComponentMap = std::map<std::string, std::unique_ptr<Component>>;
		ComponentMap CompMap;

		template<typename T>
		void RegisterComponent() {
			auto Comp = static_cast<std::unique_ptr<Component>>(std::make_unique<T>());
			CompMap[Comp->ComponentType] = std::move(Comp);
		};

		void RegisterAllComponents();
	};
}