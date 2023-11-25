//
//  test_maze_0.hpp
//  Maze_Project
//
//  Created by Ryomen_Sukuna on 25/11/2023.
//

#ifndef test_maze_0_hpp
#define test_maze_0_hpp
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <iostream>

class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() {return isRunning;}



private:
    int cnt = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;


};
#endif /* test_maze_0_hpp */
