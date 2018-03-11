#include <ResourceManager.h>

using namespace Core;


SDL_Renderer* ResourceManager::mainRenderer = NULL;
std::map<std::string, SDL_Texture*> ResourceManager::Textures;


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
        Log::makeNote("Image couldn't load");
        return NULL;
    }

    texture = SDL_CreateTextureFromSurface(mainRenderer, surface);
    if(texture == NULL) {
        Log::makeNote("Texture couldn't create from surface");
        return NULL;
    }

    SDL_FreeSurface(surface);

    Textures.insert(std::pair<std::string, SDL_Texture*>(name, texture));

    return texture;

}

SDL_Texture* ResourceManager::GetTexture(const std::string &name) {
    return Textures.at(name);
}

void ResourceManager::FreeMemory() {
    Textures.clear();
}

void ResourceManager::Terminate() {
    IMG_Quit();
}