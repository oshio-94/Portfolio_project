#include "Map.h"
#include "textureManager.h"

//Contains all the components for the map functions
int lvl1[20][25] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

Map::Map() {
    dirt = textureManager::LoadTexture("/Users/emike/Documents/Maze_Project/Maze_Project/Maze_Project/assets/dirt.png");
    grass = textureManager::LoadTexture("/Users/emike/Documents/Maze_Project/Maze_Project/Maze_Project/assets/grass.png");
    water = textureManager::LoadTexture("/Users/emike/Documents/Maze_Project/Maze_Project/Maze_Project/assets/water.png");
    wall = textureManager::LoadTexture("/Users/emike/Documents/Maze_Project/Maze_Project/Maze_Project/assets/wall.png");
    defaut = textureManager::LoadTexture("/Users/emike/Documents/Maze_Project/Maze_Project/Maze_Project/assets/default.png");
  

    LoadMap(lvl1);

    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;

    dest.x = dest.y = 0;
}

Map::~Map(){
    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(water);
    SDL_DestroyTexture(dirt);
    SDL_DestroyTexture(wall);
    SDL_DestroyTexture(defaut);
}
void Map::LoadMap(int arr[20][25]){
    for (int row = 0; row < 20; row++){
        for(int column = 0; column < 25; column++){
            map[row][column] = arr[row][column];
        }
    }
}

void Map::DrawMap(){
    int type = 0;
    for (int row = 0; row < 20; row++){
        for(int column = 0; column < 25; column++){
            type = map[row][column];

            dest.x = column * 32;
            dest.y = row * 32;

            switch (type)
            {
                case 0:
                    textureManager::Draw(water, src, dest);
                    break;
                case 1:
                    textureManager::Draw(grass, src, dest);
                    break;
                case 2:
                    textureManager::Draw(dirt, src, dest);
                    break;
                case 3:
                    textureManager::Draw(wall, src, dest);
                    break;
                case 4:
                    textureManager::Draw(defaut, src, dest);
                    break;
                default:
                    break;
            }
        }
    }
}
