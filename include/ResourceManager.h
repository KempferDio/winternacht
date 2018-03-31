#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <Log.h>
#include <Render/Sprite.h>
#include <Render/Texture.h>
#include <GameObjects/GameObject.h>
#include <GameObjects/Pawn.h>
#include <GameObjects/Tile.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

namespace Core {
    class ResourceManager {
        public:
            static std::map<std::string, Texture*> Textures;
            static std::map<std::string, Sprite*> Sprites;
            static std::map<std::string, GameObjects::Pawn*> Pawns;
            static std::map<std::string, GameObjects::Tile*> Tiles;

            static int InitManager(SDL_Renderer *render);


            static Texture* LoadTexture(const char* path, const char* name);
            static Sprite* LoadSpriteFromTexture(const char* textureName, const char* spriteName,
                int clipRowCount, int clipColumnCount, int clipSize);
            static Sprite* LoadSpriteFromTexture(const char* textureName, const char* spriteName,
                int clipRowCount, int clipColumnCount, int clipWidth, int clipHeight);
            static Sprite* LoadSpriteFromTexture(const char* textureName, const char* spriteName);

            //static GameObject* CreateGameObject(const char* name, const char* spriteName);
            static GameObjects::Pawn* CreatePawn(const char* name, const char* spriteName);
            static GameObjects::Tile* CreateTile(const char* name, const char* spriteName);

            static Texture* GetTexture(const char* name);
            static Sprite* GetSprite(const char* name);
            //static GameObject* GetGameObject(const char* name);
            static GameObjects::Pawn* GetPawn(const char* name);
            static GameObjects::Tile* GetTile(const char* name);

            static void FreeMemory();
            static void Terminate();
                        
        private:
            ResourceManager() {}
            //SDL textures requires pointer to renderer
            // if they creates from surface.
            static SDL_Renderer* mainRenderer;
    };
}

#endif