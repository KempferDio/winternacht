#include <ResourceManager.h>

using namespace Core;


SDL_Renderer* ResourceManager::mainRenderer = NULL;
std::map<std::string, Texture*> ResourceManager::Textures;
std::map<std::string, Sprite*> ResourceManager::Sprites;
std::map<std::string, GameObjects::Pawn*> ResourceManager::Pawns;
std::map<std::string, GameObjects::Tile*> ResourceManager::Tiles;

int ResourceManager::InitManager(SDL_Renderer *render) {
    mainRenderer = render;

    int imgFlag = IMG_INIT_PNG;
    if(!IMG_Init(imgFlag)) {
        Log::LogError("SDL_image can't init", "imgFlag was", imgFlag);
        return 1;
    }

    return 0;
}


GameObjects::Pawn* ResourceManager::CreatePawn(const char* name, const char* spriteName) {
    GameObjects::Pawn* pawn = new GameObjects::Pawn(GetSprite(spriteName));
    Pawns.insert(std::pair<std::string, GameObjects::Pawn*>(name, pawn));
    return Pawns.at(name);
}

GameObjects::Tile* ResourceManager::CreateTile(const char* name, const char* spriteName) {
    GameObjects::Tile* tile = new GameObjects::Tile(GetSprite(spriteName));
    Tiles.insert(std::pair<std::string, GameObjects::Tile*>(name, tile));
    return Tiles.at(name);
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

    Texture *texture = new Texture(name, rect, SDL_CreateTextureFromSurface(mainRenderer, surface));

    texture->data = SDL_CreateTextureFromSurface(mainRenderer, surface);
    if(texture->data == NULL) {
        Log::LogError("Texture can't create from surface");
        return NULL;
    }

    SDL_FreeSurface(surface);

    Textures.insert(std::pair<std::string, Texture*>(name, texture));

    return Textures.at(name);
}

//Sprite
Sprite* ResourceManager::LoadSpriteFromTexture(const char* textureName, const char* spriteName,
    int clipRowCount, int clipColumnCount, int clipSize) {
    
    Sprite *sprite = new Sprite(clipRowCount, clipColumnCount, clipSize, GetTexture(textureName));
    Sprites.insert(std::pair<std::string, Sprite*>(spriteName, sprite));

    return Sprites.at(spriteName);
}

Sprite* ResourceManager::LoadSpriteFromTexture(const char* textureName, const char* spriteName,
    int clipRowCount, int clipColumnCount, int clipWidth, int clipHeight) {
    
    Sprite *sprite = new Sprite(clipRowCount, clipColumnCount, clipWidth, clipHeight, GetTexture(textureName));
    Sprites.insert(std::pair<std::string, Sprite*>(spriteName, sprite));

    return Sprites.at(spriteName);
}

Sprite* ResourceManager::LoadSpriteFromTexture(const char* textureName, const char* spriteName) {
    Sprite *sprite = new Sprite(GetTexture(textureName));
    Sprites.insert(std::pair<std::string, Sprite*>(spriteName, sprite));

    return Sprites.at(spriteName);
}

Texture* ResourceManager::GetTexture(const char* name) {
    Texture *texture;
    try {
        texture = Textures.at(name);
    } catch(std::out_of_range e) {
        Log::LogError("This texture is not exist");
        return NULL;
    }
    return texture;
}

Sprite* ResourceManager::GetSprite(const char* name) {
    Sprite *sprite;
    try {
        sprite = Sprites.at(name);
    } catch(std::out_of_range e) {
        Log::LogError("This sprite is not exist");
        return NULL;
    }
    return sprite;
}


GameObjects::Pawn* ResourceManager::GetPawn(const char* name) {
    GameObjects::Pawn* pawn;
    try {
        pawn = Pawns.at(name);
    } catch(std::out_of_range e) {
        Log::LogError("This pawn is not exist");
        return NULL;
    }

    return pawn;
}

GameObjects::Tile* ResourceManager::GetTile(const char* name) {
    GameObjects::Tile* tile;
    try {
        tile = Tiles.at(name);
    } catch(std::out_of_range e) {
        Log::LogError("This tile is not exist");
        return NULL;
    }

    return tile;
}

void ResourceManager::FreeMemory() {
    
    for(auto texture : Textures) {
        SDL_DestroyTexture(texture.second->data);
        delete texture.second;
    }
    for(auto sprite : Sprites) {
        delete sprite.second;
    }
    for(auto pawn : Pawns) {
        delete pawn.second;
    }

    for(auto tile : Tiles) {
        delete tile.second;
    }
    Textures.clear();
    Sprites.clear();
    Pawns.clear();
    Tiles.clear();
}

void ResourceManager::Terminate() {
    IMG_Quit();
}