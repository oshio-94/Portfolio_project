#include "test_maze_0.hpp"

// main game loop and functions
Game *game = nullptr;

int main(int argc, const char * arv[]) {
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
    int frameTime;

	game = new Game();

	game->init("Maze-Challenge", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 800, false);

// Implement game loop
	while (game->running()) {
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}
