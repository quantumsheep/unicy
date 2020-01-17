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

    template <typename Tl, int Rl, int Cl, typename Ry>
    friend Matrix<decltype(std::declval<Tl &>() * std::declval<Ry &>()), Rl, Cl> operator*(const Matrix<Tl, Rl, Cl> &l, const Ry &r)
    {
        Matrix<decltype(std::declval<Tl &>() * std::declval<Ry &>()), Rl, Cl> mat;

        for (int y = 0; y < Rl; y++)
        {
            for (int x = 0; x < Cl; x++)
            {
                mat[y][x] = l[y][x] * r;
            }
        }

        return mat;
    }

    template <typename Tr, int Rr, int Cr>
    Matrix<T, R, C> &operator*=(const Matrix<Tr, Rr, Cr> &r)
    {
        Matrix<T, R, C> mat = static_cast<Matrix<T, Cr, R>>(*this * r);
        this->values = mat.values;

        return *this;
    }

    template <typename Ry>
    Matrix<T, R, C> &operator*=(const Ry &r)
    {
        Matrix<T, R, C> mat = *this * static_cast<T>(r);
        this->values = mat.values;

        return *this;
    }

    template <typename Ty, int Ry, int Cy>
    operator Matrix<Ty, Ry, Cy>()
    {
        auto mat = Matrix<Ty, Ry, Cy>();

        for (int y = 0; y < Ry; y++)
        {
            for (int x = 0; x < Cy; x++)
            {
                mat[y][x] = static_cast<Ty>((*this)[y][x]);
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
