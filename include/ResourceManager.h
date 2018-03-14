#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <Log.h>
#include <Sprite.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

namespace Core {
    class ResourceManager {
        public:
            static std::map<std::string, SDL_Texture*> Textures;
            static std::map<std::string, Sprite> Sprites;

            static int InitManager(SDL_Renderer *render);
            static SDL_Texture* LoadTexture(const std::string &path, const std::string &name);
            static Sprite* LoadSpriteFromTexture(const std::string &textureName, const std::string &spriteName,
                int clipRowCount, int clipColumnCount, int clipSize);

            static SDL_Texture* GetTexture(const std::string &name);
            static Sprite* GetSprite(const std::string &name);

            static void FreeMemory();
            static void Terminate();

            
        private:
            //SDL textures requires pointer to renderer
            // if they creates from surface.
            static SDL_Renderer* mainRenderer;
    };
}

#endif