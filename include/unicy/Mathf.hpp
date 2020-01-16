#pragma once

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

const auto Sqrt = std::sqrtf;

} // namespace Unicy::Mathf
