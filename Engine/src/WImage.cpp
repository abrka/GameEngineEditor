#include "WImage.h"
#include <stdio.h>
#include "Entity.h"




//void Engine::WImage::Render()
//{
//	if (mRenderer == NULL) {
//		printf("renderer is null");
//		return;
//	}
//
//	/*SDL_Rect RenderQuad = { ((WorldPosition.X - Cam.WorldPosition.X)* Cam.Scale.Y)+ Cam.Size.X/2 ,
//							((WorldPosition.Y- Cam.WorldPosition.Y)* Cam.Scale.Y)+Cam.Size.Y/ 2,
//							Size.X* Scale.X * Cam.Scale.X,
//							Size.Y*Scale.Y* Cam.Scale.Y };*/
//
//	SDL_Rect RenderQuad = RenderingUtils::WorldToScreen(Scale, Cam, WorldPosition,Size );
//
//	//Set clip rendering dimensions
//	if (Clip != NULL)
//	{
//		RenderQuad.w = Clip->w;
//		RenderQuad.h = Clip->h;
//	}
//
//	SDL_RenderCopyEx(mRenderer, Texture, Clip, &RenderQuad, Angle,Center,Flip );
//}



Engine::WImage::WImage(): Component("WImage")
{
	ExportedProperties.push_back(Reflect::Var{ &TexturePath, Reflect::Type::FilePathType, "Texture Path"});
	
}

Engine::WImage::~WImage()
{
	DestroyTexture(*this);
}



SDL_Point Engine::GetSizeOfTexture(SDL_Texture* texture)
{
	SDL_Point size;
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
	return size;
}

void Engine::LoadTexture(WImage& Image, SDL_Renderer* RendererHandle)
{
	Image.Texture = IMG_LoadTexture(RendererHandle, Image.TexturePath.string().c_str());

	// if the default size is not provided use size of texture
	if (Image.Size.x == 0 or Image.Size.y == 0) {
		SDL_Point TextureSize = GetSizeOfTexture(Image.Texture);
		Image.Size.x = TextureSize.x;
		Image.Size.y = TextureSize.y;
	}

	if (Image.Texture == NULL) {
		printf("couldnt load texture %s \n", SDL_GetError());
	}
}

void Engine::DestroyTexture(WImage& Image)
{
	SDL_DestroyTexture(Image.Texture);
	Image.Texture = NULL;
}

void Engine::RenderImage(Engine::World& EcsWorld, SDL_Renderer* mRenderer)
{
	auto view = EcsWorld.m_Registry.view<Engine::WImage>();
	for (auto ent : view)
	{
		auto& ImageComp = view.get<Engine::WImage>(ent);

		if (mRenderer == NULL) {
			printf("renderer is null");
			return;
		}

		SDL_Rect RenderQuad{ ImageComp.WorldPosition.x, ImageComp.WorldPosition.y, ImageComp.Size.x, ImageComp.Size.y };

		//Set clip rendering dimensions
		if (ImageComp.Clip != NULL)
		{
			RenderQuad.w = ImageComp.Clip->w;
			RenderQuad.h = ImageComp.Clip->h;
		}
		SDL_RenderCopyEx(mRenderer, ImageComp.Texture, ImageComp.Clip, &RenderQuad, ImageComp.Angle, ImageComp.Center, ImageComp.Flip);
	}
}

Engine::Component& Engine::WImage::AddComponentToEntity(Entity& Target)
{
	return Target.AddComponent<Engine::WImage>();
}

void Engine::WImage::RemoveThisComponentFromEntity(Entity& Target)
{
	Target.RemoveComponent<Engine::WImage>();
}

nlohmann::json Engine::WImage::ToJsonC()
{
	
	return nlohmann::json{
		{"ComponentType",ComponentType},
		{"TexturePath", TexturePath.string()}
	};
}

void Engine::WImage::InitFromJson(nlohmann::json& _json)
{
	TexturePath = std::filesystem::path{ _json.at("TexturePath").get<std::string>()};
}