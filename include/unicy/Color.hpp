#pragma once

#include <stdexcept>
#include <string>

namespace Unicy
{

struct Color
{
    float r;
    float g;
    float b;
    float a;

    Color(float r, float g, float b) : r(r), g(g), b(b) {}
    Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}

    inline float &operator[](int i)
    {
        switch (i)
        {
        case 0:
            return this->r;
        case 1:
            return this->g;
        case 2:
            return this->b;
        case 3:
            return this->a;
        default:
            throw std::out_of_range("Vector3Generic<T>[" + std::to_string(i) + "] : index out of range.");
        }
    }
};

} // namespace Unicy
