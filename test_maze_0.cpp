//
//  test_maze_0.cpp
//  Maze_Project
//
//  Created by Ryomen_Sukuna on 25/11/2023.
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
std::vector<ColliderComponent*> Game::colliders;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

enum groupLabels : std::size_t{
	groupMap,
	groupPlayers,
	groupEnemies,
	groupColliders
};

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

//ECS implementation

//size and position of tile
/* tile0.addComponent<TileComponent>(200, 200, 32, 32, 0);
tile1.addComponent<TileComponent>(250, 250, 32, 32, 1);
tile2.addComponent<TileComponent>(100, 100, 32, 32, 2);
tile3.addComponent<TileComponent>(220, 220, 32, 32, 3);
tile3.addComponent<ColliderComponent>("wall");
tile4.addComponent<TileComponent>(120, 120, 32, 32, 4);
tile4.addComponent<ColliderComponent>("defaut"); */

Map::LoadMap("/Users/emike/Documents/Maze_Project/Maze_Project/Maze_Project/assets/pyxel.map", 32, 32);


player.addComponent<TransformComponent>(1);
player.addComponent<SpriteComponent>("/Users/emike/Documents/Maze_Project/Maze_Project/Maze_Project/assets/player.png");
player.addComponent<KeyboardController>();
player.addComponent<ColliderComponent>("player");
player.addGroup(groupPlayers);

wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
wall.addComponent<SpriteComponent>("/Users/emike/Documents/Maze_Project/Maze_Project/Maze_Project/assets/wall.png");
wall.addComponent<ColliderComponent>("wall");
wall.addGroup(groupMap);

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

void Game::update()
{
	//player->Update();
	//enemy->Update();
	manager.refresh();
	manager.update();

	for (auto cc : colliders){
		/*if(Collision::AABB(player.getComponent<ColliderComponent>().collider, wall.getComponent<ColliderComponent>().collider)){
			player.getComponent<TransformComponent>().scale = 1;
		    player.getComponent<TransformComponent>().velocity * -1;
		    std::cout << "Wall hit!" << std::endl;
		}*/
		Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
    }
}

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));


void Game::render()
{
	SDL_RenderClear(renderer);
    for (auto& t : tiles){
		t->draw();
	}

	for (auto& p : players){
		p->draw();
	}

	for (auto& e : enemies){
		e->draw();
	}
	SDL_RenderPresent(renderer);
}

//Destroy Window, Quit SDL subsystems
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleared" << std::endl;
}

void Game::AddTile(int id, int x, int y){
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(x, y, 32, 32, id);
	tile.addGroup(groupMap);
}
