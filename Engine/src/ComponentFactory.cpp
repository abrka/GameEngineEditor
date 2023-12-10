#include "ComponentFactory.h"
#include "Entity.h"
#include "EngineComponents.h"
#include "Component.h"
#include <string>



void Engine::ComponentFactory::RegisterAllComponents()
{
	RegisterComponent<Name>();
	RegisterComponent<Position>();
	RegisterComponent<EntityMarker>();

}


Engine::ComponentFactory::ComponentFactory()
{
	RegisterAllComponents();
}



void Engine::ComponentFactory::AddComponentFromType(std::string Type, nlohmann::json& CompJson, Engine::Entity& TargetEntity)
{
	CompMap.at(Type)->AddComponentToEntity(TargetEntity).InitFromJson(CompJson);
}



