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

    
};