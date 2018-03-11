#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <Log.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

namespace Core {
    class ResourceManager {
        public:
            static int InitManager(SDL_Renderer *render);
            static SDL_Texture* LoadTexture(const std::string &path, const std::string &name);
            static SDL_Texture* GetTexture(const std::string &name);
            static void FreeMemory();
            static void Terminate();

            static std::map<std::string, SDL_Texture*> Textures;
        private:
            //SDL textures requires pointer to renderer
            // if they creates from surface.
            static SDL_Renderer* mainRenderer;
    };
}

#endif