//
//  test_maze_0.cpp
//  Maze_Project
//
//  Created by Ryomen_Sukuna on 25/11/2023.
//

#include "test_maze_0.hpp"
#include "textureManager.h"
#include "GameObject.h"

GameObject* player;
GameObject* enemy;

SDL_Renderer* Game::renderer = nullptr;

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
     }
     if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
     {
	     std::cout << "Subsystems Initialised" << std::endl;

	     window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
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

player = new GameObject("assets/texture.png", renderer,0,0);
player = new GameObject("assets/enemy.png", rendered,50,50);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
	    case SDL_QUIT:
		    isRunning = false;
		    break;

	    defaault:
		    break;
    }
}

void Game::render()
{
	SDL_RenderClear(renderer);
	player->Render();
	enemy->Render();
	/*SDL_RenderCopy(renderer, playerTex, NULL, &destR);*/
	SDL_RenderPresent(renderer);
}

void Game::update()
{
	player->Update();
	enemy->Update();
	/*cnt++;
	destR.h = 32;
	destR.w = 32;
	destR.x = cnt;
	std::cout << cnt << std::endl;*/
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleared" << std::endl;
}
