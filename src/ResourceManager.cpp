#include <ResourceManager.h>

using namespace Core;


SDL_Renderer* ResourceManager::mainRenderer = NULL;
std::map<std::string, Texture> ResourceManager::Textures;
std::map<std::string, Sprite> ResourceManager::Sprites;
std::map<std::string, GameObject> ResourceManager::GameObjects;

int ResourceManager::InitManager(SDL_Renderer *render) {
    mainRenderer = render;

    int imgFlag = IMG_INIT_PNG;
    if(!IMG_Init(imgFlag)) {
        Log::LogError("SDL_image can't init", "imgFlag was", imgFlag);
        return 1;
    }

    return 0;
}

//Game object
GameObject* ResourceManager::CreateGameObject(const char* name, const char* spriteName) {
    GameObject go(GetSprite(spriteName));
    GameObjects.insert(std::pair<std::string, GameObject>(name, go));
    return &GameObjects.at(name);
}

//Texture
Texture* ResourceManager::LoadTexture(const char* path, const char* name) {

    
    SDL_Surface *surface;

    surface = IMG_Load(path);
    
    if(surface == NULL) {
        Log::LogError("Image can't load", "Path", path);
        return NULL;
    }
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = surface->w;
    rect.h = surface->h;

    Texture texture(name, rect, SDL_CreateTextureFromSurface(mainRenderer, surface));

    texture.data = SDL_CreateTextureFromSurface(mainRenderer, surface);
    if(texture.data == NULL) {
        Log::LogError("Texture can't create from surface");
        return NULL;
    }

    SDL_FreeSurface(surface);

    Textures.insert(std::pair<std::string, Texture>(name, texture));

    return &Textures.at(name);

}

//Sprite
Sprite* ResourceManager::LoadSpriteFromTexture(const char* textureName, const char* spriteName,
    int clipRowCount, int clipColumnCount, int clipSize) {
        

    Sprite sprite(clipRowCount, clipColumnCount, clipSize, GetTexture(textureName));
    Sprites.insert(std::pair<std::string, Sprite>(spriteName, sprite));

    return &Sprites.at(spriteName);
}

Texture* ResourceManager::GetTexture(const char* name) {
    Texture texture;
    try {
        texture = Textures.at(name);
    } catch(std::out_of_range e) {
        Log::LogError("This texture is not exist");
        return NULL;
    }

    return &Textures.at(name);
}

Sprite* ResourceManager::GetSprite(const char* name) {
    try {
        Sprite sprite;
        sprite = Sprites.at(name);
    } catch(std::out_of_range e) {
        Log::LogError("This sprite is not exist");
        return NULL;
    }

    return &Sprites.at(name);
}

GameObject* ResourceManager::GetGameObject(const char* name) {
    try {
        GameObject go;
        go = GameObjects.at(name);
    } catch(std::out_of_range e) {
        Log::LogError("This game object is not exist");
        return NULL;
    }
    return &GameObjects.at(name);
}

void ResourceManager::FreeMemory() {
    
    for(auto texture : Textures) {
        SDL_DestroyTexture(texture.second.data);
    }
    Textures.clear();
    Sprites.clear();
    GameObjects.clear();
}

void ResourceManager::Terminate() {
    IMG_Quit();
}