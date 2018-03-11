#ifndef RENDERER_H
#define RENDERER_H
#include <SDL2/SDL.h>
#include <Log.h>

namespace Core {
    class Renderer {
        public:
            static bool InitRenderer(const std::string &title,
                    unsigned int width, unsigned int height);
                    
            static void Render(/* Game Object goes here */);
            static SDL_Renderer* GetRenderer();
            static void Terminate();
        private:
            static SDL_Renderer* MainRenderer;
            static SDL_Window* MainWindow;
            static unsigned int WindowWidth;
            static unsigned int WindowHeight;
            static std::string WindowTitle;
    };
}

#endif