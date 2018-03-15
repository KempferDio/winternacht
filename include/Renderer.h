#ifndef RENDERER_H
#define RENDERER_H
#include <SDL2/SDL.h>
#include <Log.h>
#include <ResourceManager.h>
#include <Sprite.h>

namespace Core {
    class Renderer {
        public:
            static bool InitRenderer(const std::string &title,
                    unsigned int width, unsigned int height);

            static void Render(const char* spriteName);
            static void Render(const char* spriteName, SDL_Rect position);

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