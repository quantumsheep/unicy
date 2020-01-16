#pragma once

#include <unicy/Vector3.hpp>

#include <string>

namespace Unicy
{

class Quaternion
{
public:
    float x;
    float y;
    float z;
    float w;

    Quaternion() = default;
    Quaternion(const Quaternion &) = default;
    Quaternion(Quaternion &&) = default;

    Quaternion(const float &x, const float &y, const float &z, const float &w) : x(x), y(y), z(z), w(w) {}

    static Quaternion Identity() { return Quaternion(0, 0, 0, 1); }

    std::string to_string() const;

    Vector3 eulerAngles() const;
    void eulerAngles(const Vector3 &angles);

    friend inline std::ostream &operator<<(std::ostream &os, const Quaternion &r)
    {
        return os << r.to_string();
    }

private:
    static Vector3 ToEulerRad(const Quaternion &rotation);
    static Quaternion FromEulerRad(const Vector3 &angles);

    static Vector3 NormalizeAngles(Vector3 angle);
    static float NormalizeAngle(float angle);
};

} // namespace Unicy
