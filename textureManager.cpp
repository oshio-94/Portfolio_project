#include "textureManager.h"

SDL_Texture* textureManager::LoadTexture(const char* texture);
{
    SDL_Surface* tempSurface = IMG_LOAD(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}