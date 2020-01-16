#pragma once

#include <unicy/Color.hpp>

#include <algorithm>
#include <cmath>
#include <limits>

namespace Unicy::Mathf
{

constexpr float PI = 3.14159274f;

constexpr float Infinity = std::numeric_limits<float>::infinity();
constexpr float NegativeInfinity = -Infinity;

constexpr float Deg2Rad = 0.0174532924f;
constexpr float Rad2Deg = 57.29578f;

constexpr float Epsilon = std::numeric_limits<float>::epsilon();

inline float Abs(const float &f) { return std::abs(f); }
inline int Abs(const int &f) { return std::abs(f); }

inline float Acos(const float &f) { return std::acosf(f); }

inline float Approximately(const float &a, const float &b)
{
    return (Mathf::Abs(a - b) < Mathf::Epsilon);
}

inline float Asin(const float &f) { return std::asinf(f); }

inline float Atan(const float &f) { return std::atanf(f); }

inline float Atan2(const float &y, const float &x) { return std::atan2f(y, x); }

inline float Ceil(const float &f) { return std::ceilf(f); }
inline int CeilToInt(const float &f) { return static_cast<int>(Mathf::Ceil(f)); }

template <typename T>
inline constexpr const T &Clamp(const T &value, const T &min, const T &max)
{
    return std::clamp(value, min, max);
}

template <typename T>
inline constexpr const T &Clamp01(const T &value)
{
    return std::clamp(value, 0.0f, 1.0f);
}

// int ClosestPowerOfTwo(int value)
// {
//     return Mathf::Pow( 2, Math.round( Math.log( aSize ) / Math.log( 2 ) ) );
// }

// Color CorrelatedColorTemperatureToRGB(float kelvin)
// {
// }

inline float Cos(const float &f) { return std::cosf(f); }

inline float Floor(const float &f) { return std::floorf(f); }
inline int FloorToInt(const float &f) { return static_cast<int>(std::floorf(f)); }

inline float Repeat(const float &t, const float &length)
{
    return Mathf::Clamp(t - Mathf::Floor(t / length) * length, 0.0f, length);
}

inline float DeltaAngle(const float &current, const float &target)
{
    float delta = Mathf::Repeat((target - current), 360.0f);

    if (delta > 180.0f)
        delta -= 360.0f;

    return delta;
}

inline float Exp(const float &f) { return std::expf(f); }

inline float Pow(const float &f, const float &p) { return std::powf(f, p); }

inline float Gamma(const float &value, const float &absmax, const float &gamma)
{
    bool negative = value < 0.0f;
    float absval = Mathf::Abs(value);
    if (absval > absmax)
        return negative ? -absval : absval;

    float result = Mathf::Pow(absval / absmax, gamma) * absmax;
    return negative ? -result : result;
}

// inline float GammaToLinearSpace(const float &value)
// {
// }

inline float Lerp(const float &a, const float &b, const float &t)
{
    return (a + t * (b - a));
}

inline float Sin(const float &f) { return std::sinf(f); }

inline float Sqrt(const float &f) { return std::sqrtf(f); }

} // namespace Unicy::Mathf
