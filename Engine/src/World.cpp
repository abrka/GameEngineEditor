#include "World.h"
#include "Entity.h"
#include <fstream>
#include <iostream>
#include <string>
#include "EngineComponents.h"


std::unique_ptr<Engine::Entity> Engine::World::CreateEntity()
{
	//Entity* CreatedEntity = new Entity{ this, m_Registry.create() };

	//remove commenent to get back m_Entites feature
	//m_Entities.push_back(CreatedEntity);

	return std::make_unique<Entity>(this, m_Registry.create());
}

std::unique_ptr<Engine::Entity> Engine::World::CreateEntity(json& EntityJson)
{

	//Entity* CreatedEntity = new Entity{ this, m_Registry.create(), EntityJson };

	//remove commenent to get back m_Entites feature
	//m_Entities.push_back(CreatedEntity);

	return std::make_unique<Entity>(this, m_Registry.create(), EntityJson);
}

void Engine::World::RemoveEntityFromRegistry(Engine::Entity& Entity)
{

	m_Registry.destroy(Entity.m_EntityHandle);

}

std::vector<Engine::Entity*> Engine::World::GetAllEntities()
{
	std::vector<Engine::Entity*> AllEntities;
	auto EntityView = m_Registry.view<EntityMarker>();
	for (auto Entity : EntityView) {
		EntityMarker& EntMarker = m_Registry.get<EntityMarker>(Entity);
		AllEntities.push_back(EntMarker.Owner);
	}
	return AllEntities;
}

Engine::Entity* Engine::World::FindEntityParentFromUUID(Engine::Entity* Ent)
{
	std::vector<Entity*> AllEntities = GetAllEntities();

    auto It = std::find_if(AllEntities.begin(), AllEntities.end(),
		[Ent](Entity* OtherEnt) {
			return OtherEnt->m_UUID == Ent->ParentUUID;
		});

	assert(It != AllEntities.end() && "Couldnt find any entity with the same parent uuid");

	return *It;
}

void Engine::World::SaveScene(std::string OutFilePath)
{
	json SceneJson = R"({
					"Entities" : [
											
					] 
					})"_json;


	//old method for getting all entites
	/*auto EntityView = m_Registry.view<EntityMarker>();
	for (auto Entity : EntityView) {
		
		EntityMarker& EntMarker = m_Registry.get<EntityMarker>(Entity);
		SceneJson.at("Entities").push_back(*EntMarker.Owner);

	}*/

	for (Engine::Entity* Ent : GetAllEntities()) {
		SceneJson.at("Entities").push_back(*Ent);
	}

	std::ofstream OutFile{ OutFilePath };
	OutFile << std::setw(4) << SceneJson << std::endl;
}

void Engine::World::DestroyAllEntities()
{

	RootEntity.reset();

	/*auto EntityView = m_Registry.view<EntityMarker>();
	EntityView.each([](EntityMarker& Marker) {
		delete Marker.Owner;
		});*/

	/*for (auto* Ent : m_Entities)
	{
		delete Ent;
	}*/
}

bool Engine::World::IsRootEntity(Engine::Entity& Ent)
{
	xg::Guid EmptyUUID;
	return Ent.ParentUUID == EmptyUUID;
}

void Engine::World::LoadScene(std::string InFilePath)
{
	json InJson;
	std::ifstream InFile{ InFilePath };
	InFile >> InJson;

	

	DestroyAllEntities();

	xg::Guid EmptyUUID;
	std::vector<std::unique_ptr<Engine::Entity>> TempEntityStorage;
	 
	//first create all entities 
	for (json& EntJson : InJson.at("Entities")) {

		
		//at first everything is added to a temporary storage. the parents and chidlren are set later
		TempEntityStorage.push_back(CreateEntity(EntJson));

		if (IsRootEntity(*TempEntityStorage.back())) {

			RootEntity = std::move(TempEntityStorage.back());
			//after std::move the root entity element in TempEnitiyStorage becomes nullptr. so we remove any nullptr from the Storage to remove the RootEntityElement
			TempEntityStorage.erase(std::remove(TempEntityStorage.begin(), TempEntityStorage.end(), nullptr), TempEntityStorage.end());
		}
		
	}


	//and then set their parent and children pointers

	for (std::unique_ptr<Entity>& Ent : TempEntityStorage) {

		
		// if there is a valid parent uuid set parent pointer
		if (Ent->ParentUUID != EmptyUUID) {
		
			Ent->Parent = FindEntityParentFromUUID(Ent.get());
			Ent->Parent->Children.push_back(std::move(Ent));

		}
		//else set parent to nothing
		else {
			Ent->Parent = nullptr;
		}
	};

	TempEntityStorage.clear();
}
