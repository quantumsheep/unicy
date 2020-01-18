#include <sstream>
#include <unicy/Matrix.hpp>

using namespace Unicy;

template <typename T, size_t R, size_t C>
std::string Matrix<T, R, C>::to_string() const
{
    std::stringstream stream;

    for (int i = 0; i < R; i++)
    {
        stream << "(";

        for (int j = 0; j < C; j++)
        {
            stream << this->values[i][j];

            if (j < (C - 1))
            {
                stream << ", ";
            }
        }

        stream << ")\n";
    }

    return stream.str();
}
