#include <unicy/Quaternion.hpp>

#include <unicy/Mathf.hpp>

using namespace Unicy;

std::string Quaternion::to_string() const
{
    return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z) + ", " + std::to_string(this->w) + ")";
}

Vector3 Quaternion::eulerAngles() const
{
    return Quaternion::ToEulerRad(*this) * Mathf::Rad2Deg;
}

void Quaternion::eulerAngles(const Vector3 &angles)
{
    auto q = Quaternion::FromEulerRad(angles * Mathf::Deg2Rad);

    this->x = q.x;
    this->y = q.y;
    this->z = q.z;
    this->w = q.w;
}

Vector3 Quaternion::ToEulerRad(const Quaternion &rotation)
{
    Vector3 angles;

    // roll (x-axis rotation)
    float sinr_cosp = 2 * (rotation.w * rotation.x + rotation.y * rotation.z);
    float cosr_cosp = 1 - 2 * (rotation.x * rotation.x + rotation.y * rotation.y);
    angles.x = Mathf::Atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    float sinp = 2 * (rotation.w * rotation.y - rotation.z * rotation.x);
    if (Mathf::Abs(sinp) >= 1)
    {
        angles.y = std::copysign(Mathf::PI / 2, sinp); // use 90 degrees if out of range
    }
    else
    {
        angles.y = Mathf::Asin(sinp);
    }

    // yaw (z-axis rotation)
    float siny_cosp = 2 * (rotation.w * rotation.z + rotation.x * rotation.y);
    float cosy_cosp = 1 - 2 * (rotation.y * rotation.y + rotation.z * rotation.z);
    angles.z = Mathf::Atan2(siny_cosp, cosy_cosp);

    return angles;
}

Quaternion Quaternion::FromEulerRad(const Vector3 &angles)
{
    auto roll = angles.x;
    auto pitch = angles.y;
    auto yaw = angles.z;

    double cy = Mathf::Cos(yaw * 0.5f);
    double sy = Mathf::Sin(yaw * 0.5f);
    double cp = Mathf::Cos(pitch * 0.5f);
    double sp = Mathf::Sin(pitch * 0.5f);
    double cr = Mathf::Cos(roll * 0.5f);
    double sr = Mathf::Sin(roll * 0.5f);

    Quaternion q;
    q.w = cy * cp * cr + sy * sp * sr;
    q.x = cy * cp * sr - sy * sp * cr;
    q.y = sy * cp * sr + cy * sp * cr;
    q.z = sy * cp * cr - cy * sp * sr;

    return q;
}
