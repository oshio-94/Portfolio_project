#pragma once
#include <string>

class Map {
    public:
        Map();
        ~Map();

        static void LoadMap(std::string path, int sizeX, int sizeY);
        //void DrawMap();


    private:
        
        /*SDL_Rect src, dest;

        SDL_Texture* dirt;
        SDL_Texture* grass;
        SDL_Texture* water;
        SDL_Texture* wall;
        SDL_Texture* defaut;
    
        int map[20][25]; */
};
