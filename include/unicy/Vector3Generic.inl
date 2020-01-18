#include <unicy/Vector3Generic.hpp>

#include <unicy/Mathf.hpp>

namespace Unicy
{

template <typename T>
std::string Vector3Generic<T>::to_string() const
{
    auto x = std::to_string(this->x);
    auto y = std::to_string(this->y);
    auto z = std::to_string(this->z);

    return "(" + x + ", " + y + ", " + z + ")";
}

template <typename T>
T Vector3Generic<T>::Magnitude(const Vector3Generic<T> &v)
{
    return static_cast<T>(Mathf::Sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

template <typename T>
Vector3Generic<T> Vector3Generic<T>::Normalize(const Vector3Generic<T> &v)
{
    return v / Vector3Generic::Magnitude(v);
}

} // namespace Unicy
