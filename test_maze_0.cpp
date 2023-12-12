//
//  test_maze_0.cpp
//  Maze_Project
//
//  Created by Ryomen_Sukuna on 25/11/2023.
//

#include "test_maze_0.hpp"
#include "textureManager.h"
#include "Map.h"
#include "Components.h"
#include "Vector2D.h"
#include "Collision.h"

//GameObject* player;
//GameObject* enemy;
Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
     int flags = 0;
     if(fullscreen)
     {
	     flags = SDL_WINDOW_FULLSCREEN;
     } //Initialize SDL
     if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
     {
	     std::cout << "Subsystems Initialised" << std::endl;
         //create window
	     window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
	     if(window)
	     {
		 std::cout << "Window created" <<std::endl;
	     }

	     renderer = SDL_CreateRenderer(window, -1, 0);
	     if(renderer)
	     {
		     SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
		     std::cout << "Renderer created" << std::endl;
	     }

	     isRunning = true;
     } else {
	     isRunning = false;
     }

//player = new GameObject("assets/player.png", 0, 0);
//enemy  = new GameObject("assets/enemy.png", 50, 50);
map = new Map();

//ecs implementation
player.addComponent<TransformComponent>(2);
player.addComponent<SpriteComponent>("/Users/emike/Documents/Maze_Project/Maze_Project/Maze_Project/assets/player.png");
player.addComponent<KeyboardController>();
player.addComponent<ColliderController>(player);

wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
wall.addComponent<SpriteComponent>("/Users/emike/Documents/Maze_Project/Maze_Project/Maze_Project/assets/dirt.png");
wall.addComponent<ColliderComponent>("wall");




//newPlayer.getComponent<PositionComponent>().setPos(500, 500);
}

void Game::handleEvents()
{
	
    SDL_PollEvent(&event);
    switch (event.type) {
	    case SDL_QUIT:
		    isRunning = false;
		    break;

	    default:
		    break;
    }
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	manager.draw();
	//player->Render();
	//enemy->Render();
	/*SDL_RenderCopy(renderer, playerTex, NULL, &destR);*/
	SDL_RenderPresent(renderer);
}

void Game::update()
{
	//player->Update();
	//enemy->Update();
	manager.refresh();
	manager.update();

	if(Collision::AABB(player.getComponent<ColliderComponent>().collider, wall.getComponent<ColliderComponent>().collider)){
		std::cout << "Wall hit!" << std::endl;
	}
	/*player.getComponent<TransformComponent>().position.Add(Vector2D(5, 0));

	if(player.getComponent<TransformComponent>().position.x() > 100){
        player.getComponent<SpriteComponent>().setTex("/Users/emike/Documents/Maze_Project/Maze_Project/Maze_Project/assets/enemy.png");
    }
	std::cout << newPlayer.getComponent<positionComponent>().x() << "," << 
	    newPlayer.getComponent<positionComponent>().y() << std::endl;
	cnt++;
	destR.h = 32;
	destR.w = 32;
	destR.x = cnt;
	std::cout << cnt << std::endl;*/
}
//Destroy Window, Quit SDL subsystems
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleared" << std::endl;
}
