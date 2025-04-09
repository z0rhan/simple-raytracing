#include "window.hh"
#include <SDL2/SDL.h>
#include <cstddef>

Window::Window() :
    pWindow(NULL),
    pRenderer(NULL),
    isRunning(false)
{
}

bool Window::onInit() {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    pWindow = SDL_CreateWindow("Ray tracer",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               1280, 720,
                               SDL_WINDOW_SHOWN);

    if (pWindow == NULL) {
        return false;
    }

    pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

    this->isRunning = true;

    return true;
}

int Window::onExecute() {
    SDL_Event event;

    if (!onInit()) {
        return -1;
    }

    // App loop
    while (isRunning) {
        while (SDL_PollEvent(&event) != 0) {
            onEvent(&event);
        }
        onLoop();
        onRender();
    }
    onExit();

    return 0;
}

void Window::onEvent(SDL_Event* event) {
    if (event->type == SDL_QUIT) {
        isRunning = false;
    }
}

void Window::onLoop() {

}

void Window::onRender() {
    // Set the bf-color to white
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(pRenderer);


    // Show the result
    SDL_RenderPresent(pRenderer);
}

void Window::onExit() {

    // Clean up SDL2 stuff
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);

    pWindow = NULL;
    SDL_Quit();
}

