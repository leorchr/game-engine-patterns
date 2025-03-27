#include "../engine/Engine.h"
#include "Game.h"

int main()
{
    Engine engine;
    engine.Start(1280, 720, "ECS implementation", std::make_unique<Game>());
    return 0;
}