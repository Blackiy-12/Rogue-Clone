#include "Game.h"

#include "Render/Render.h"
#include "Gamemode/GamemodeCreator.h"

Game* Game::GamePtr = nullptr;

Game::Game() : GamemodePtr(nullptr)
{
    Render::getRender();

    this->Active = true;
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

    while (this->Active)
    {
        this->GamemodePtr->runGamemode();
    }
}

void Game::changeGamemode()
{
    this->GamemodePtr = GamemodeCreator::createNewGamemode();
}

void Game::exit()
{
    this->Active = false;
}

void Game::initNewGame()
{
    this->changeGamemode();
}
