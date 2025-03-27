#include "SceneGame.h"
#include "AssetsManager.h"
#include "raylib.h"
#include <random>

SceneGame::SceneGame(shared_ptr<ECSManager> ecsRef, Game& game)
: ecs {std::move( ecsRef )}, game { game }
{
    srand(time(0));
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
    playerTransform.pos = Vector2{ 100.0f, 100.0f };

    ecs->CreateInputComponent(player);

    {
        int x = AssetsManager::GetTexture("Ship").width;
        int y = AssetsManager::GetTexture("Ship").height;
        auto playerBox = Rectangle( static_cast<float>(x),static_cast<float>(y));
        ecs->CreateRigidbody2DComponent(player, playerTransform.pos, playerBox);
    }


    int x = AssetsManager::GetTexture("Astroid").width;
    int y = AssetsManager::GetTexture("Astroid").height;
    auto astroidBox = Rectangle( static_cast<float>(x),static_cast<float>(y));

    for (size_t i = 0; i < 20; i++)
    {
        u64 astroid = ecs->CreateEntity();
        ecs->CreateSpriteComponent(astroid, "Astroid");
        Transform2D& astroidTransform = ecs->CreateTransform2DComponent(astroid);


        float randomX = rand() % GetScreenWidth();
        float randomY = rand() % GetScreenHeight();

        astroidTransform.pos = Vector2{ randomX, randomY };

        int randomRot = rand() % 361;
        astroidTransform.rotation = randomRot;

        Rigidbody2D& astroidRigidbody = ecs->CreateRigidbody2DComponent(astroid, astroidTransform.pos, astroidBox);

        float randomVelocityX = 0 + (rand() % (1 - 0 + 1)) == 1 ? -1.f : 1.f ;
        float randomVelocityY = 0 + (rand() % (1 - 0 + 1)) == 1 ? -1.f : 1.f ;
        astroidRigidbody.velocity = Vector2{ 50.0f * randomVelocityX, 50.0f* randomVelocityY };
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