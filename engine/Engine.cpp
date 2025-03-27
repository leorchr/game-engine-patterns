#include <algorithm>
#include "Engine.h"
#include "raylib.h"
#include "Window.h"
#include "IGame.h"

void Engine::Start(i32 windowWidth, i32 windowHeight, const str& gameNameP,
unique_ptr<IGame>&& gameP) noexcept
{
    gameName = gameNameP;
    game = std::move(gameP);
    Window window { windowWidth, windowHeight, gameName };
    game->Load();
    while (!Window::ShouldClose())
    {
        f32 dt = std::min(GetFrameTime(), 0.0166f);
        game->Update(dt);
        render::BeginDraw();
        render::ClearScreen();
        game->Draw();
        render::EndDraw();
    }
    game->Unload();
}