#pragma once

#include "SDL.h"
#include <SDL_image.h>
#include "glm/vec2.hpp"
#include "Component.h"
#include "World.h"
#include <filesystem>

namespace Engine {
	class WImage : public Component
	{

	public:
		WImage();
		~WImage();

		SDL_Texture* Texture{ NULL };
		std::filesystem::path TexturePath{"none"};


		double Angle{};
		SDL_Point* Center{ NULL };
		glm::vec2 WorldPosition{ 0.0,0.0 };
		glm::vec2 Size{ 0.0,0.0 };
		glm::vec2 Scale{ 1.0,1.0 };
		SDL_RendererFlip Flip = SDL_FLIP_NONE;
		SDL_Rect* Clip{ NULL };


		virtual Component& AddComponentToEntity(Entity& Target) override;
		virtual void RemoveThisComponentFromEntity(Entity& Target) override;
		virtual nlohmann::json ToJsonC() override;
		virtual void InitFromJson(nlohmann::json& _json) override;

	};

	SDL_Point GetSizeOfTexture(SDL_Texture* texture);
	void LoadTexture(WImage& Image, SDL_Renderer* RendererHandle);
	void DestroyTexture(WImage& Image);
	void RenderImage(World& EcsWorld, SDL_Renderer* mRenderer);
}