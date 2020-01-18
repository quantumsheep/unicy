#include <unicy/Vector2Generic.hpp>

#include <unicy/Mathf.hpp>

namespace Unicy
{

template <typename T>
std::string Vector2Generic<T>::to_string() const
{
    auto x = std::to_string(this->x);
    auto y = std::to_string(this->y);

    return "(" + x + ", " + y + ")";
}

template <typename T>
T Vector2Generic<T>::Magnitude(const Vector2Generic<T> &v)
{
    return static_cast<T>(Mathf::Sqrt((v.x * v.x) + (v.y * v.y)));
}

template <typename T>
Vector2Generic<T> Vector2Generic<T>::Normalize(const Vector2Generic<T> &v)
{
    return v / Vector2Generic::Magnitude(v);
}

} // namespace Unicy
