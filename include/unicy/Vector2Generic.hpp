#pragma once

#include <iostream>
#include <string>
#include <type_traits>

namespace Unicy
{

template <typename T>
class Vector2Generic
{
public:
    T x;
    T y;

    Vector2Generic() = default;
    Vector2Generic(const Vector2Generic &) = default;
    Vector2Generic(Vector2Generic &&) = default;

    Vector2Generic(T x, T y) : x(x), y(y) {}
    Vector2Generic(T a) : x(a), y(a) {}

    static T Magnitude(const Vector2Generic<T> &v);
    static Vector2Generic<T> Normalize(const Vector2Generic<T> &v);

    static constexpr Vector2Generic<T> one() { return Vector2Generic<T>(1, 1); }
    static constexpr Vector2Generic<T> zero() { return Vector2Generic<T>(0, 0); }

    static constexpr Vector2Generic<T> up() { return Vector2Generic<T>(0, 1); }
    static constexpr Vector2Generic<T> down() { return Vector2Generic<T>(0, -1); }
    static constexpr Vector2Generic<T> right() { return Vector2Generic<T>(1, 0); }
    static constexpr Vector2Generic<T> left() { return Vector2Generic<T>(-1, 0); }

    static constexpr Vector2Generic<T> negativeInfinity()
    {
        static_assert(std::numeric_limits<T>::has_infinity, "Type doesn't have infinity.");

        constexpr auto infinity = std::numeric_limits<T>::infinity();
        return Vector2Generic<T>(-infinity);
    }

    static constexpr Vector2Generic<T> positiveInfinity()
    {
        static_assert(std::numeric_limits<T>::has_infinity, "Type doesn't have infinity.");

        constexpr auto infinity = std::numeric_limits<T>::infinity();
        return Vector2Generic<T>(infinity);
    }

    std::string to_string() const;

    inline Vector2Generic<T> magnitude() const
    {
        return Vector2Generic<T>::Magnitude(*this);
    }

    inline Vector2Generic<T> normalized() const
    {
        return Vector2Generic<T>::Normalize(*this);
    }

    inline operator std::string() const
    {
        return this->to_string();
    }

    template <typename VecL, typename VecR>
    friend inline auto operator+(const Vector2Generic<VecL> &l, const Vector2Generic<VecR> &r) -> Vector2Generic<decltype(l.x + r.x)>
    {
        return Vector2Generic<decltype(l.x + r.x)>(l.x + r.x, l.y + r.y);
    }

    template <typename VecL, typename VecR>
    friend inline auto operator-(const Vector2Generic<VecL> &l, const Vector2Generic<VecR> &r) -> Vector2Generic<decltype(l.x - r.x)>
    {
        return Vector2Generic<decltype(l.x - r.x)>(l.x - r.x, l.y - r.y);
    }

    template <typename VecL, typename VecR>
    friend inline auto operator*(const Vector2Generic<VecL> &l, const Vector2Generic<VecR> &r) -> Vector2Generic<decltype(l.x * r.x)>
    {
        return Vector2Generic<decltype(l.x * r.x)>(l.x * r.x, l.y * r.y);
    }

    template <typename VecL, typename VecR>
    friend inline auto operator/(const Vector2Generic<VecL> &l, const Vector2Generic<VecR> &r) -> Vector2Generic<decltype(l.x / r.x)>
    {
        return Vector2Generic<decltype(l.x / r.x)>(l.x / r.x, l.y / r.y);
    }

    template <typename V, typename R>
    friend inline auto operator*(const Vector2Generic<V> &l, const R &r) -> Vector2Generic<decltype(l.x * r)>
    {
        static_assert(std::is_arithmetic<R>::value, "rvalue must be an arithmetic type.");

        return Vector2Generic<decltype(l.x * r)>(l.x * r, l.y * r);
    }

    template <typename V, typename R>
    friend inline auto operator/(const Vector2Generic<V> &l, const R &r) -> Vector2Generic<decltype(l.x / r)>
    {
        static_assert(std::is_arithmetic<R>::value, "rvalue must be an arithmetic type.");

        return Vector2Generic<decltype(l.x / r)>(l.x / r, l.y / r);
    }

    template <typename VecR>
    friend inline std::ostream &operator<<(std::ostream &os, const Vector2Generic<VecR> &r)
    {
        os << r.to_string();
        return os;
    }

    template <typename VecR>
    Vector2Generic<T> &operator+=(const Vector2Generic<VecR> &r)
    {
        this->x += r.x;
        this->y += r.y;

        return *this;
    }

    template <typename VecR>
    Vector2Generic<T> &operator-=(const Vector2Generic<VecR> &r)
    {
        this->x -= r.x;
        this->y -= r.y;

        return *this;
    }

    template <typename R>
    Vector2Generic<T> &operator*=(const R &r)
    {
        this->x *= r;
        this->y *= r;

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
        default:
            throw std::out_of_range("Vector2Generic<T>[" + std::to_string(i) + "] : index out of range.");
        }
    }
};

} // namespace Unicy

#include <unicy/Vector2Generic.inl>
