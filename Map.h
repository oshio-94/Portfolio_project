#pragma once
//#include "test_maze_0.hpp"

class Map {
    public:
        Map();
        ~Map();

        void LoadMap(std::string path, int sizeX, int sizeY);
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
