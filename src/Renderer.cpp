#include <Renderer.h>

using namespace Core;

//Init static vars
SDL_Renderer* Renderer::MainRenderer = NULL;
SDL_Window* Renderer::MainWindow = NULL;
unsigned int Renderer::WindowWidth = 0;
unsigned int Renderer::WindowHeight = 0;
std::string Renderer::WindowTitle;
bool Renderer::IsOpen;

bool Renderer::InitRenderer(const std::string &title,
        unsigned int width, unsigned int height)
{
    WindowTitle = title;
    WindowWidth = width;
    WindowHeight = height;
    IsOpen = true;

    MainWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
     SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, SDL_WINDOW_SHOWN);
    if(MainWindow == NULL) {
        Log::makeNote("Window couldn't create");
        return false;
    }

    MainRenderer = SDL_CreateRenderer(MainWindow, -1, SDL_RENDERER_ACCELERATED);
    if(MainRenderer == NULL) {
        Log::makeNote("Renderer couldn't create");
        return false;
    }

    SDL_SetRenderDrawColor(MainRenderer, 255, 255, 255, 255);
    return true;
}

SDL_Renderer* Renderer::GetRenderer() {
    return MainRenderer;
}

bool Renderer::IsWindowOpen() {
    return IsOpen;
}

void Renderer::SetWindowOpen(bool state) {
    IsOpen = state;
}

void Renderer::Render(int x, int y, const std::string &textureName, SDL_Rect *clip) {
    SDL_Rect renderQuad = { x, y, clip->w, clip->h };
    SDL_RenderCopy(GetRenderer(), ResourceManager::GetTexture(textureName), clip, &renderQuad);
}

void Renderer::Terminate() {
    SDL_DestroyRenderer(MainRenderer);
    SDL_DestroyWindow(MainWindow);
}