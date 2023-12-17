#pragma once

#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "SDL2/SDL.h"

class TileComponent : public Component{
    public:
        TransformComponent *transform; //Give access to our position
        SpriteComponent *sprite;

        SDL_Rect tileRect;
        int tileID;
        const char* path;

        TileComponent() = default;

        TileComponent(int x, int y, int w, int h, int id){
            tileRect.x = x;
            tileRect.y = y;
            tileRect.w = w;
            tileRect.h = h;
            tileID = id;

            switch (tileID){
                case 0:
                    path = "/Users/emike/Documents/Maze_Project/Maze_Project/Maze_Project/assets/dirt.png";
                    break;
                case 1:
                    path = "/Users/emike/Documents/Maze_Project/Maze_Project/Maze_Project/assets/grass.png";
                    break;
                case 2:
                    path = "/Users/emike/Documents/Maze_Project/Maze_Project/Maze_Project/assets/water.png";
                    break; 
                case 3:
                    path = "/Users/emike/Documents/Maze_Project/Maze_Project/Maze_Project/assets/wall.png";
                    break;
                /*case 4:
                    path = "/Users/emike/Documents/Maze_Project/Maze_Project/Maze_Project/assets/default.png";
                    break;*/
                default:
                    break;
            }

        }
        // initialise class
        //add transform component to tile
        void init() override{
            entity->addComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, tileRect.w, tileRect.h, 1);
            transform = &entity->getComponent<TransformComponent>();

            entity->addComponent<SpriteComponent>(path);
            sprite = &entity->getComponent<SpriteComponent>();

        }
};
