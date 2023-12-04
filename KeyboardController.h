#pragma once;

#include "test_maze_0.hpp"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component{
    public:
        TransformComponent *transform;
        void init() override {
            transform = &entity->getComponent<TransformComponent>();
        }
        void update() overide{
            if(Game::event.type == SDL_KEYDOWN){
                switch (Game::event.keysym.sym){
                    case SDLK_w:
                        transform->velocity.y = -1;
                        break;
                    case SDLK_a:
                        transform->velocity.x = -1;
                        break;
                    case SDLK_d:
                        transform->velocity.x = 1;
                        break;
                    case SDLK_D:
                        transform->velocity.y = 1;
                        break;
                    default:
                        break;
                }
            }
            if(Game::event.type == SDL_KEYUP){
                switch (Game::event.keysym.sym){
                    case SDLK_w:
                        transform->velocity.y = 0;
                        break;
                    case SDLK_a:
                        transform->velocity.x = 0;
                        break;
                    case SDLK_d:
                        transform->velocity.x = 0;
                        break;
                    case SDLK_D:
                        transform->velocity.y = 0;
                        break;
                    default:
                        break;
                }
            }
        }
};