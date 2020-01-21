#pragma once

#include <unicy/Mathf.hpp>
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

    Quaternion(const Quaternion &) = default;
    Quaternion(Quaternion &&) = default;

    Quaternion() : Quaternion(0.0f, 0.0f, 0.0f, 1.0f) {}
    Quaternion(const float &x, const float &y, const float &z, const float &w) : x(x), y(y), z(z), w(w) {}

    static Quaternion Identity() { return Quaternion(1, 0, 0, 0); }

    std::string to_string() const;

    Vector3 eulerAngles() const;
    void eulerAngles(const Vector3 &angles);

    static inline float Magnitude(const Quaternion &q)
    {
        return Mathf::Sqrt((q.x * q.x) + (q.y * q.y) + (q.z * q.z) + (q.w * q.w));
    }

    static inline Quaternion Normalize(const Quaternion &q)
    {
        return q / Quaternion::Magnitude(q);
    }

    inline float magnitude() { return Quaternion::Magnitude(*this); }
    inline Quaternion normalized() { return Quaternion::Normalize(*this); }

    friend inline std::ostream &operator<<(std::ostream &os, const Quaternion &r)
    {
        return os << r.to_string();
    }

    template <typename R>
    friend inline Quaternion operator*(const Quaternion &l, const R &r)
    {
        static_assert(std::is_arithmetic<R>::value, "rvalue must be an arithmetic type.");

        return Quaternion(l.x * r, l.y * r, l.z * r, l.w * r);
    }

    template <typename R>
    friend inline Quaternion operator/(const Quaternion &l, const R &r)
    {
        static_assert(std::is_arithmetic<R>::value, "rvalue must be an arithmetic type.");

        return Quaternion(l.x / r, l.y / r, l.z / r, l.w * r);
    }

    Quaternion &operator=(const Quaternion &r) = default;

private:
    static Vector3 ToEulerRad(const Quaternion &rotation);
    static Quaternion FromEulerRad(const Vector3 &angles);
};

} // namespace Unicy
