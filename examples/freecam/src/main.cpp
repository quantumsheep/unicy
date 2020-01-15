#include <unicy/unicy.hpp>

using namespace Unicy;

int main()
{
    Vector3Int a(9, 3, 70);

    Debug::Log(a);
    // Debug::Log(Vector3::Magnitude(a));
    // Debug::Log(Vector3::Normalize(a));
    Debug::Log(a.normalized());
    // Debug::Log(Vector3Int::positiveInfinity());
    // Debug::Log(Vector3::negativeInfinity());
    Debug::Log(a[0]);
    Debug::Log(a[1]);
    Debug::Log(a[2]);

    return 0;
}
