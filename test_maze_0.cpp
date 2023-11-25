//
//  test_maze_0.cpp
//  Maze_Project
//
//  Created by Ryomen_Sukuna on 25/11/2023.
//

#include "test_maze_0.hpp"

Game::Gamer()
{}
Game::~Game()
{}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
     int flags = 0;
     if(fullscreen)
     {
	     flags = SLD_WINDOW_FULLSCREEN;
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
		     std::cout << "Renderer created" << std::endl;
	     }

	     isRunning = true;
     } else {
	     isRunning = false;
     }	
}

void Game::updated()
{
    SDL_Event event;
    SDL_PollEvent(&event);
}

void Game::render()
{}

void Game::clean()
{}
