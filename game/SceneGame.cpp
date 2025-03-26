#include "SceneGame.h"

#include <iostream>

#include "AssetsManager.h"

#include "raylib.h"
#include "raymath.h"

SceneGame::SceneGame(shared_ptr<ECSManager> ecsRef, Game& game)
: ecs {std::move( ecsRef )}, game { game }
{

}

void SceneGame::Load() {
    AssetsManager::LoadTexture("Ship01", "assets/Ship01.png", ToSceneId(SceneName::SceneGame));
    AssetsManager::LoadTexture("Ship02", "assets/Ship02.png", ToSceneId(SceneName::SceneGame));
    AssetsManager::LoadTexture("Ship03", "assets/Ship03.png", ToSceneId(SceneName::SceneGame));
    AssetsManager::LoadTexture("Ship04", "assets/Ship04.png", ToSceneId(SceneName::SceneGame));
    AssetsManager::LoadTexture("Farback01", "assets/Farback01.png", ToSceneId(SceneName::SceneGame));
    AssetsManager::LoadTexture("Farback02", "assets/Farback02.png", ToSceneId(SceneName::SceneGame));
    AssetsManager::LoadTexture("Stars", "assets/Stars.png", ToSceneId(SceneName::SceneGame));
    AssetsManager::LoadTexture("Astroid", "assets/Astroid.png", ToSceneId(SceneName::SceneGame));
    AssetsManager::LoadTexture("Ship", "assets/Ship.png", ToSceneId(SceneName::SceneGame));
    AssetsManager::LoadTexture("Laser", "assets/Laser.png", ToSceneId(SceneName::SceneGame));

    u64 player = ecs->CreateEntity();
    ecs->CreateSpriteComponent(player, "Ship");


    Transform2D& playerTransform = ecs->CreateTransform2DComponent(player);
    playerTransform.pos = Vector2{ 0.0f, 0.0f };

    ecs->CreateInputComponent(player);


    int x = AssetsManager::GetTexture("Ship").width;
    int y = AssetsManager::GetTexture("Ship").height;
    auto astroidBox = Rectangle( static_cast<float>(x),static_cast<float>(y));

    for (size_t i = 0; i < 20; i++)
    {
        u64 astroid = ecs->CreateEntity();
        ecs->CreateSpriteComponent(astroid, "Astroid");
        Transform2D& astroidTransform = ecs->CreateTransform2DComponent(astroid);
        astroidTransform.pos = Vector2{ 0.0f, 0.0f };
        Rigidbody2D& astroidRigidbody = ecs->CreateRigidbody2DComponent(astroid, astroidTransform.pos, astroidBox);

        astroidRigidbody.velocity = Vector2{ 50.0f, 50.0f };
    }
}

void SceneGame::Update(f32 dt) {
    ecs->UpdateScene(dt);
}

void SceneGame::Draw() {
    ecs->PrepareDraw();
    ecs->DrawScene();

}

void SceneGame::Unload() {
    AssetsManager::UnloadSceneTextures(ToSceneId(SceneName::SceneGame));
}