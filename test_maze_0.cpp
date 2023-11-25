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

	     window = SDL_CreateWindow(title, xpos, ypos, width, height, flags)
	

}

void Game::updated()
{}

void Game::render()
{}

void Game::clean()
{}
