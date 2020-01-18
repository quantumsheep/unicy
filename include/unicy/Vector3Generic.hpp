#pragma once

#include <iostream>
#include <string>
#include <type_traits>

namespace Unicy
{

template <typename T>
class Vector3Generic
{
public:
    T x;
    T y;
    T z;

    Vector3Generic() = default;
    Vector3Generic(const Vector3Generic &) = default;
    Vector3Generic(Vector3Generic &&) = default;

    Vector3Generic(T x, T y, T z) : x(x), y(y), z(z) {}
    Vector3Generic(T a) : x(a), y(a), z(a) {}

    static T Magnitude(const Vector3Generic<T> &v);
    static Vector3Generic<T> Normalize(const Vector3Generic<T> &v);

    static constexpr Vector3Generic<T> one() { return Vector3Generic<T>(1, 1, 1); }
    static constexpr Vector3Generic<T> zero() { return Vector3Generic<T>(0, 0, 0); }

    static constexpr Vector3Generic<T> forward() { return Vector3Generic<T>(0, 0, 1); }
    static constexpr Vector3Generic<T> back() { return Vector3Generic<T>(0, 0, -1); }
    static constexpr Vector3Generic<T> up() { return Vector3Generic<T>(0, 1, 0); }
    static constexpr Vector3Generic<T> down() { return Vector3Generic<T>(0, -1, 0); }
    static constexpr Vector3Generic<T> right() { return Vector3Generic<T>(1, 0, 0); }
    static constexpr Vector3Generic<T> left() { return Vector3Generic<T>(-1, 0, 0); }

    static constexpr Vector3Generic<T> negativeInfinity()
    {
        static_assert(std::numeric_limits<T>::has_infinity, "Type doesn't have infinity.");

        constexpr auto infinity = std::numeric_limits<T>::infinity();
        return Vector3Generic<T>(-infinity);
    }

    static constexpr Vector3Generic<T> positiveInfinity()
    {
        static_assert(std::numeric_limits<T>::has_infinity, "Type doesn't have infinity.");

        constexpr auto infinity = std::numeric_limits<T>::infinity();
        return Vector3Generic<T>(infinity);
    }

    std::string to_string() const;

    inline Vector3Generic<T> magnitude() const
    {
        return Vector3Generic<T>::Magnitude(*this);
    }

    inline Vector3Generic<T> normalized() const
    {
        return Vector3Generic<T>::Normalize(*this);
    }

    inline operator std::string() const
    {
        return this->to_string();
    }

    template <typename VecL, typename VecR>
    friend inline auto operator+(const Vector3Generic<VecL> &l, const Vector3Generic<VecR> &r) -> Vector3Generic<decltype(l.x + r.x)>
    {
        return Vector3Generic<decltype(l.x + r.x)>(l.x + r.x, l.y + r.y, l.z + r.z);
    }

    template <typename VecL, typename VecR>
    friend inline auto operator-(const Vector3Generic<VecL> &l, const Vector3Generic<VecR> &r) -> Vector3Generic<decltype(l.x - r.x)>
    {
        return Vector3Generic<decltype(l.x - r.x)>(l.x - r.x, l.y - r.y, l.z - r.z);
    }

    template <typename VecL, typename VecR>
    friend inline auto operator*(const Vector3Generic<VecL> &l, const Vector3Generic<VecR> &r) -> Vector3Generic<decltype(l.x * r.x)>
    {
        return Vector3Generic<decltype(l.x * r.x)>(l.x * r.x, l.y * r.y, l.z * r.z);
    }

    template <typename VecL, typename VecR>
    friend inline auto operator/(const Vector3Generic<VecL> &l, const Vector3Generic<VecR> &r) -> Vector3Generic<decltype(l.x / r.x)>
    {
        return Vector3Generic<decltype(l.x / r.x)>(l.x / r.x, l.y / r.y, l.z / r.z);
    }

    template <typename V, typename R>
    friend inline auto operator*(const Vector3Generic<V> &l, const R &r) -> Vector3Generic<decltype(l.x * r)>
    {
        static_assert(std::is_arithmetic<R>::value, "rvalue must be an arithmetic type.");

        return Vector3Generic<decltype(l.x * r)>(l.x * r, l.y * r, l.z * r);
    }

    template <typename V, typename R>
    friend inline auto operator/(const Vector3Generic<V> &l, const R &r) -> Vector3Generic<decltype(l.x / r)>
    {
        static_assert(std::is_arithmetic<R>::value, "rvalue must be an arithmetic type.");

        return Vector3Generic<decltype(l.x / r)>(l.x / r, l.y / r, l.z / r);
    }

    template <typename VecR>
    friend inline std::ostream &operator<<(std::ostream &os, const Vector3Generic<VecR> &r)
    {
        os << r.to_string();
        return os;
    }

    template <typename VecR>
    Vector3Generic<T> &operator+=(const Vector3Generic<VecR> &r)
    {
        this->x += r.x;
        this->y += r.y;
        this->z += r.z;

        return *this;
    }

    template <typename VecR>
    Vector3Generic<T> &operator-=(const Vector3Generic<VecR> &r)
    {
        this->x -= r.x;
        this->y -= r.y;
        this->z -= r.z;

        return *this;
    }

    template <typename R>
    Vector3Generic<T> &operator*=(const R &r)
    {
        static_assert(std::is_arithmetic<R>::value, "rvalue must be an arithmetic type.");

        this->x *= r;
        this->y *= r;
        this->z *= r;

        return *this;
    }

    T &operator[](const int &i)
    {
        switch (i)
        {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;
        default:
            throw std::out_of_range("Vector3Generic<T>[" + std::to_string(i) + "] : index out of range.");
        }
    }
};

} // namespace Unicy

#include <unicy/Vector3Generic.inl>
