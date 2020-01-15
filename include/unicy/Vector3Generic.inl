#include <unicy/Vector3Generic.hpp>

#include <cmath>

namespace Unicy
{

template <typename T, typename E>
std::string Vector3Generic<T, E>::to_string() const
{
    auto x = std::to_string(this->x);
    auto y = std::to_string(this->y);
    auto z = std::to_string(this->z);

    return "(" + x + ", " + y + ", " + z + ")";
}

template <typename T, typename E>
T Vector3Generic<T, E>::Magnitude(const Vector3Generic<T> &v)
{
    return static_cast<T>(std::sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

template <typename T, typename E>
Vector3Generic<T> Vector3Generic<T, E>::Normalize(const Vector3Generic<T> &v)
{
    return v / Vector3Generic::Magnitude(v);
}

} // namespace Unicy
