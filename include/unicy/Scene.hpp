#pragma once

#include <unicy/Transform.hpp>

#include <vector>

namespace Unicy
{

class Scene
{
public:
    std::vector<Transform> roots = std::vector<Transform>();
};

} // namespace Unicy
