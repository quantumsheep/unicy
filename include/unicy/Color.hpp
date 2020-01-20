#pragma once

#include <stdexcept>
#include <string>

namespace Unicy
{

class Color
{
private:
    float *refs = nullptr;

public:
    float &r;
    float &g;
    float &b;
    float &a;

    Color(float r, float g, float b) : Color(r, b, a, 1.0f) {}

    Color(float r, float g, float b, float a)
        : refs(new float[4]{r, g, b, a}),
          r(refs[0]),
          g(refs[1]),
          b(refs[2]),
          a(refs[3]) {}

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

    inline operator float *()
    {
        return this->refs;
    }
};

} // namespace Unicy
