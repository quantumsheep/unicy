#pragma once

#include <array>
#include <iostream>
#include <string>

namespace Unicy
{

template <typename T, int R, int C, typename = std::enable_if_t<(R > 0 && C > 0), bool>>
class Matrix
{
public:
    std::array<std::array<T, C>, R> values = {std::array<T, C>()};

    template <typename Ty = T, int Ry = R, int Cy = C>
    static constexpr std::enable_if_t<(Ry == Cy), Matrix<Ty, Ry, Cy>> identity()
    {
        Matrix<Ty, Ry, Cy> mat;

        for (int i = 0; i < R && i < C; i++)
        {
            mat[i][i] = 1;
        }

        return mat;
    }

    std::string to_string() const;

    friend inline std::ostream &operator<<(std::ostream &os, const Matrix &r)
    {
        return os << r.to_string();
    }

    template <typename Tl, int Rl, int Cl, typename Tr, int Rr, int Cr>
    friend std::enable_if_t<(Cl == Rr), Matrix<decltype(std::declval<Tl &>() * std::declval<Tr &>()), Rl, Cr>>
    operator*(const Matrix<Tl, Rl, Cl> &l, const Matrix<Tr, Rr, Cr> &r)
    {
        using MulT = decltype(std::declval<Tl &>() * std::declval<Tr &>());

        Matrix<MulT, Rl, Cr> mat;

        for (int i = 0; i < Rl; i++)
        {
            for (int j = 0; j < Cr; j++)
            {
                auto value = MulT();

                for (int k = 0; k < Rr; k++)
                {
                    value += l[i][k] * r[k][j];
                }

                mat[i][j] = value;
            }
        }

        return mat;
    }

    inline std::array<T, C> &operator[](int i)
    {
        return this->values[i];
    }

    inline const std::array<T, C> &operator[](int i) const
    {
        return this->values[i];
    }
};

} // namespace Unicy

#include <unicy/Matrix.inl>
