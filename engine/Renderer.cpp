#include <cmath>
#include "Renderer.h"
#include "raylib.h"

namespace render {
    void BeginDraw() {
        BeginDrawing();
    }
    void ClearScreen() {
        ClearBackground(BLACK);
    }
    void EndDraw() {
        EndDrawing();
    }
    void DrawTexture(Texture texture, i32 x, i32 y, Color tint) {
        ::DrawTexture(texture, x, y, tint);
    }
    void DrawSprite(Texture texture2D, Rectangle srcRect, Rectangle dstRect, float rotation, Color tint) {
        ::DrawTexturePro(texture2D, srcRect, dstRect, { 0, 0 }, rotation, tint);
    }
}