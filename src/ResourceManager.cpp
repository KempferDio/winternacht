#include <ResourceManager.h>

using namespace Core;


SDL_Renderer* ResourceManager::mainRenderer = NULL;
std::map<std::string, SDL_Texture*> ResourceManager::Textures;
std::map<std::string, Sprite> ResourceManager::Sprites;


int ResourceManager::InitManager(SDL_Renderer *render) {
    mainRenderer = render;

    int imgFlag = IMG_INIT_PNG;
    if(!IMG_Init(imgFlag)) {
        Log::makeNote("SDL_image couldn't init", "ResourceManager::InitManager");
        return 1;
    }

    return 0;
}

SDL_Texture* ResourceManager::LoadTexture(const std::string &path, const std::string &name) {

    SDL_Texture *texture;
    SDL_Surface *surface;

    surface = IMG_Load(path.c_str());
    
    if(surface == NULL) {
        Log::makeNote("Image couldn't load", "ResourceManager::LoadTexture");
        return NULL;
    }

    texture = SDL_CreateTextureFromSurface(mainRenderer, surface);
    if(texture == NULL) {
        Log::makeNote("Texture couldn't create from surface", "ResourceManager::LoadTexture");
        return NULL;
    }

    SDL_FreeSurface(surface);

    Textures.insert(std::pair<std::string, SDL_Texture*>(name, texture));

    return texture;

}

Sprite* ResourceManager::LoadSpriteFromTexture(const std::string &textureName, const std::string &spriteName,
    int clipRowCount, int clipColumnCount, int clipSize) {
        

    Sprite sprite(clipRowCount, clipColumnCount, clipSize, GetTexture(textureName));
    Sprites.insert(std::pair<std::string, Sprite>(spriteName, sprite));

    return &Sprites.at(spriteName);
}

SDL_Texture* ResourceManager::GetTexture(const std::string &name) {
    return Textures.at(name);
}

Sprite* ResourceManager::GetSprite(const std::string &name) {
    return &Sprites.at(name);
}

void ResourceManager::FreeMemory() {
    
    for(auto texture : Textures) {
        SDL_DestroyTexture(texture.second);
    }
    Textures.clear();
}

void ResourceManager::Terminate() {
    IMG_Quit();
}