#include "Map.h"
#include "test_maze_0.hpp"
#include <fstream>
//Contains all the components for the map functions


Map::Map() {

}

Map::~Map(){

}
void Map::LoadMap(std::string path, int sizeX, int sizeY){
    char tile;
    std::fstream mapFile;
    mapFile.open(path);

    for(int y = 0; y < sizeY; y++){
        for(int x = 0; x < sizeX; x++){
            mapFile.get(tile);
            Game::AddTile(atoi(&tile), x * 32, y * 32);
            mapFile.ignore();
        }
    }

    mapFile.close();
}

/* oid Map::DrawMap(){
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
} */
