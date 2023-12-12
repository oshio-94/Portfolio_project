#pragma once

#include <string>
#include "SDL2/SDL.h"

class ColliderComponent : public Component {
    SDL_Rect collider;
    std::string tag;

    TransformComponent* transform;

    void init() override{
        if(!entity->hascomponent<TransformComponent>()){
            entity->addComponent<TransformCompoenet>();
        }
        transform = &entity->getComponent<TransformComponent>();
    }
    
    void update() override{
        collider.x = transform->position.x;
        collider.y = transform->position.y;
        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
    }

};