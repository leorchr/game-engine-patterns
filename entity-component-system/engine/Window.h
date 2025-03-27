#ifndef ENGINEIMPL_WINDOW_H
#define ENGINEIMPL_WINDOW_H

#include "Defines.h"

class Window {
public:
    Window(i32 width, i32 height, str title);
    ~Window();

    static bool ShouldClose();

private:
    i32 width;
    i32 height;
    str title;
};
#endif //ENGINEIMPL_WINDOW_H