#include "textureManager.h"

SDL_Texture* textureManager::LoadTexture(const char* texture, SDL_Renderer* ren);
{
    SDL_Surface* tempSurface = IMG_LOAD(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}