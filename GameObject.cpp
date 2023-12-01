
#include "GameObject.h"
#include "textureManager.h"


GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren){
    renderer = ren;
    objTexture = textureManager::LoadTexture(texturesheet, ren);
}

void GameObject::Update(){

}

void GameObject::Render(){
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}