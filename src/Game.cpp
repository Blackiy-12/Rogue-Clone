#include "Game.h"

#include "Render/Render.h"
#include "Gamemode/GamemodeCreator.h"

Game* Game::GamePtr = nullptr;

Game::Game() : GamemodePtr(nullptr)
{
    Render::getRender();
}

Game* Game::getGamePointer()
{
    if (Game::GamePtr == nullptr)
        Game::GamePtr = new Game;
    
    return Game::GamePtr;
}

void Game::start()
{
    this->initNewGame();

    int a =0;

    while (true)
    {
        this->GamemodePtr->runGamemode();

        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT)
                a = 1;
        }
    }
}

void Game::initNewGame()
{
    this->GamemodePtr = GamemodeCreator::createNewGamemode();

    
}
