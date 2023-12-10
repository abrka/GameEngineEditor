#pragma once

#include "ReflectedVar.h"
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <iostream>

namespace Engine {

	class Entity;
	

	class Component {	

	public:
		Component( std::string _ComponentType) :  ComponentType(_ComponentType) { };
		virtual ~Component() {};

		const std::string ComponentType{ "none component" };
		Entity* Owner = nullptr;
		std::vector<Reflect::Var> ExportedProperties;

		virtual Component& AddComponentToEntity(Entity& Target) = 0;
		virtual nlohmann::json ToJsonC() = 0;
		virtual void InitFromJson(nlohmann::json& _json) = 0;

		nlohmann::json ToJsonDebug() {
			auto ret = nlohmann::json{
				{"ComponentType", ComponentType}
			};
			return ret;
		};
		
		
	};

	
}