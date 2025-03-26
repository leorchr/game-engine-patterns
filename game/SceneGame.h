#ifndef GAMEIMPL_SCENE_GAME_H
#define GAMEIMPL_SCENE_GAME_H

#include "IScene.h"
#include "raylib.h"
#include "ECSManager.h"
#include "Game.h"

#include <vector>
#include <array>
#include <memory>

using std::vector;
using std::array;
using std::unique_ptr;
using std::shared_ptr;

class SceneGame : public IScene {

public:
    SceneGame(shared_ptr<ECSManager> ecsRef,
    Game& game);
    void Load() override;
    void Update(f32 dt) override;
    void Draw() override;
    void Unload() override;
private:
    Game& game;
    shared_ptr<ECSManager> ecs;

};

#endif //GAMEIMPL_SCENE_GAME_H