#ifndef RENDERER_H
#define RENDERER_H
#include <SDL2/SDL.h>
#include <Log.h>
#include <ResourceManager.h>
#include <Render/Sprite.h>

namespace Core {
    class Renderer {
        public:
            static bool InitRenderer(const std::string &title,
                    unsigned int width, unsigned int height);

            static void Render(const char* pawnName);
            static void RenderTile(const char* tileName);

            static SDL_Renderer* GetRenderer();
            static bool IsWindowOpen();
            static void SetWindowOpen(bool state);
            static void Terminate();

        private:
            static SDL_Renderer* MainRenderer;
            static SDL_Window* MainWindow;
            static unsigned int WindowWidth;
            static unsigned int WindowHeight;
            static std::string WindowTitle;
            static bool IsOpen;
    };
}

#endif