#pragma once

#include "Components.h"
#include "SDL2/SDL.h"
#include "textureManager.h"

//when a player is added with texture, spritcomponent draws it to the screen

class SpriteComponent : public Component{
    private:
        TransformComponent *transform;
        SDL_Texture *texture;
        SDL_Rect srcRect, destRect;

        bool animated = false;
        int frames = 0;

    public:
        SpriteComponent() = default;
        SpriteComponent(const char* path){
            setTex(path);
        }

        ~SpriteComponent(){
            SDL_DestroyTexture(texture);
        }

        void setTex(const char* path){
            texture = textureManager::LoadTexture(path);
        }
        void init() override {

            transform = &entity->getComponent<TransformComponent>();

            srcRect.x = srcRect.y = 0;
            srcRect.w = transform->width;
            srcRect.h = transform->height;
            //destRect.w = destRect.h = 32;
        }

        void update() override {
            destRect.x = static_cast<int>(transform->position.x);
            destRect.y = static_cast<int>(transform->position.y);
            destRect.w = transform->width * transform->scale;
            destRect.h = transform->height * transform->scale;
        }
        
        void draw() override {
            textureManager::Draw(texture, srcRect, destRect);
        }
};
