#include "test_maze_0.hpp"


Game *game = nullptr;

int main(int argc, const char * arv[]) {
	game = new Game();

	game->init("Maze-Challenge", SDL_WINDOWPOS_CENTERED, SDL_WINDOWSPOS_CENTERED, 700, 500, false);

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}
