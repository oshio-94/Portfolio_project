#pragma once
#include <SDL2/SDL.h>

class ColliderComponent;

class Collision {
    public:
    //check the position of each rctangle and make sure theyre within boundaries
        static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);    
    //add colliders objects and compare them
        static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
};
