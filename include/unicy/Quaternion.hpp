#pragma once

#include <unicy/Mathf.hpp>
#include <unicy/Vector3.hpp>

#include <string>

namespace Unicy
{

class Quaternion
{
public:
    float w;
    float x;
    float y;
    float z;

    Quaternion() = default;
    Quaternion(const Quaternion &) = default;
    Quaternion(Quaternion &&) = default;

    Quaternion(const float &w, const float &x, const float &y, const float &z) : w(w), x(x), y(y), z(z) {}

    static Quaternion Identity() { return Quaternion(1, 0, 0, 0); }

    std::string to_string() const;

    Vector3 eulerAngles() const;
    void eulerAngles(const Vector3 &angles);

    static inline float Magnitude(const Quaternion &q)
    {
        return Mathf::Sqrt((q.w * q.w) + (q.x * q.x) + (q.y * q.y) + (q.z * q.z));
    }

    inline float magnitude() { return Quaternion::Magnitude(*this); }

    friend inline std::ostream &operator<<(std::ostream &os, const Quaternion &r)
    {
        return os << r.to_string();
    }

private:
    static Vector3 ToEulerRad(const Quaternion &rotation);
    static Quaternion FromEulerRad(const Vector3 &angles);
};

} // namespace Unicy
