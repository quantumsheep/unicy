#pragma once

#include <unicy/Transform.hpp>

#include <string>

namespace Unicy
{

class GameObject
{
public:
    std::string name;

    Transform transform = Transform();

    GameObject() : GameObject("object") {}
    GameObject(std::string name) : name(name) {}
};

} // namespace Unicy
