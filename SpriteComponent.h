#pragma once

#include "Components.h"
#include "SDL2/SDL.h"
#include "textureManager.h"

class SpriteComponent : public Component{
    private:
        TransformComponent *transform;
        SDL_Texture *texture;
        SDL_Rect srcRect, destRect;

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
            srcRect.w = transform->width
            srcRect.h = transform->height;
            //destRect.w = destRect.h = 32;
        }

        void update() override {
            destRect.x = (int)transform->position.x;
            destRect.y = (int)transform->position.y;
            destRect.w = transorm->width * transform->scale;
            destRect.h = transorm->height * transform->scale;
        }
        
        void draw() override {
            textureManager::Draw(texture, srcRect, destRect);
        }
};
