#pragma once

#include <unicy/Quaternion.hpp>
#include <unicy/Vector3.hpp>

namespace Unicy
{

class Transform
{
public:
    Transform *parent = nullptr;

    Vector3 position;
    Vector3 localPosition;

    Quaternion rotation;
    Quaternion localRotation;

    Vector3 localScale;

    Transform(
        Transform *parent,
        Vector3 position = Vector3(0.0f),
        Quaternion rotation = Quaternion(),
        Vector3 scale = Vector3(0.0f)) : Transform(position, rotation, scale, parent) {}

    Transform(Vector3 position = Vector3(0.0f), Quaternion rotation = Quaternion(), Vector3 scale = Vector3(0.0f), Transform *parent = nullptr)
        : parent(parent),
          localPosition(position),
          localRotation(rotation),
          localScale(scale)
    {
        this->position = position;
        this->rotation = rotation;

        if (this->parent != nullptr)
        {
            // this->position -= this->parent->position;
            // this->rotation -= this->parent->rotation;
        }
    }
};

} // namespace Unicy
