#pragma once

class Collision {
    public:
    //check the position of each rctangle and make sure theyre within boundaries
        static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);    
};