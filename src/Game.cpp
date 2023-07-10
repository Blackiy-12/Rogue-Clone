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

    while (true)
    {
        this->GamemodePtr->runGamemode();
    }
}

void Game::initNewGame()
{
    this->GamemodePtr = std::make_unique<Gamemode>(GamemodeCreator::createNewGamemode());

    
}
