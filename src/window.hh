#ifndef WINDOW_HH
#define WINDOW_HH

#include <SDL2/SDL.h>

class Window {
public:
    Window();

    int onExecute();
    bool onInit();
    void onEvent(SDL_Event* event);
    void onLoop();
    void onRender();
    void onExit();

private:
    bool isRunning;
    SDL_Window* pWindow;
    SDL_Renderer* pRenderer;
};

#endif
