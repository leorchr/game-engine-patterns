#ifndef ENGINEIMPL_RENDERER_H
#define ENGINEIMPL_RENDERER_H

#include "Defines.h"
#include "raylib.h"

struct Texture;
struct Color;
struct Rectangle;

namespace render {
    void BeginDraw();

    void ClearScreen();
    void EndDraw();
    GAPI void DrawTexture(Texture texture2D, i32 x, i32 y, Color tint);
    GAPI void DrawSprite(Texture texture2D, Rectangle srcRect, Rectangle dstRect, float rotation, Color tint);
}

#endif //ENGINEIMPL_RENDERER_H