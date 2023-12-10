#include "Entity.h"
#include "Component.h"
#include "EngineComponents.h"
#include <iostream>
#include "ComponentFactory.h"


namespace Engine {

	Entity::Entity(Engine::World* _Scene, entt::entity _EntityHandle) :
		m_UUID(xg::newGuid()), m_EntityHandle(_EntityHandle), m_World(_Scene)
	{
		AddDefaultComponents();
	}

	Entity::Entity(Engine::World* _Scene, entt::entity _EntityHandle, json& EntityJson) :
		m_UUID(xg::Guid{ EntityJson.at("UUID").get<std::string>() }),
		ParentUUID(xg::Guid{ EntityJson.at("ParentUUID").get<std::string>() }),
		m_EntityHandle(_EntityHandle),
		m_World(_Scene)
	{

		for (json& ChildrenUUIDsJson : EntityJson.at("ChildrenUUIDs")) {
			ChildrenUUID.push_back(xg::Guid{ ChildrenUUIDsJson.get<std::string>() });

		}
		for (json& CompJson : EntityJson.at("components")) {
			m_World->m_CompFactory.AddComponentFromType(CompJson.at("ComponentType"), CompJson, *this);

		}

	}

	void Entity::RemoveThisFromParentsChildren()
	{
		Parent->Children.erase(
			std::remove_if(Parent->Children.begin(), Parent->Children.end(),
				[this](std::unique_ptr<Engine::Entity>& Ent) {
					std::cout << (Ent.get() == this) << std::endl;
					return Ent.get() == this;
				}), Parent->Children.end());
	};

	void Entity::RemoveThisUUIDFromParentsChildrenUUID()
	{
		std::cout << Parent->DebugValue << std::endl;

		Parent->ChildrenUUID.erase(
			std::remove_if(Parent->ChildrenUUID.begin(), Parent->ChildrenUUID.end(),
				[this](xg::Guid& UUID) {
					return UUID == m_UUID;
				}), Parent->ChildrenUUID.end());
	
	};

	void Entity::RemoveFromParent()
	{
		RemoveThisUUIDFromParentsChildrenUUID();
		//RemoveThisFromParentsChildren();
		

		Parent = nullptr;
		xg::Guid EmtpyGuid;
		ParentUUID = EmtpyGuid;


	}


	void Entity::AddChild(std::unique_ptr<Entity>&& Child)
	{
		assert(Child != nullptr && "Child is nullptr");
		assert(Child.get() != this && "cannot add this entity as a child of this entity");

		if (Child->Parent != nullptr) {
			std::cout << "removed" << std::endl;
			Child->RemoveFromParent();
		}


		Child->Parent = this;
		Child->ParentUUID = m_UUID;
		Children.push_back(std::move(Child));
		//std::cout << Children.back()->m_UUID << std::endl;
		ChildrenUUID.push_back(Children.back()->m_UUID);


	};


	Entity::~Entity()
	{
		m_World->RemoveEntityFromRegistry(*this);
	}

	void Entity::AddDefaultComponents()
	{
		AddComponent<EntityMarker>();
	}



	void to_json(json& J, const Engine::Entity& E)
	{
		J = R"(
				{
				
				"ParentUUID":-1,
				"UUID":-1,
				"ChildrenUUIDs":[],
				"components":[]
				})"_json;

		J.at("UUID") = E.m_UUID.str();
		J.at("ParentUUID") = E.ParentUUID.str();

		for (auto& ChildUUID : E.ChildrenUUID) {
			J.at("ChildrenUUIDs").push_back(ChildUUID.str());
		}

		for (auto* Comp : E.m_Components)
		{
			J.at("components").push_back(Comp->ToJsonC());
		}

	}

};