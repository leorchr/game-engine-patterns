#ifndef GAMEIMPL_ENTITY_H
#define GAMEIMPL_ENTITY_H

#include <array>
#include "Defines.h"

constexpr i32 MAX_COMPONENTS = 4;

struct Entity {
    explicit Entity(u64 idP): id {idP} {}
    u64 id;
    std::array<i32, MAX_COMPONENTS> components { -1, -1, -1, -1 };
};

#endif //GAMEIMPL_ENTITY_H