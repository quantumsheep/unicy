#pragma once

#include <array>
#include <iostream>
#include <string>

namespace Unicy
{

template <typename T, size_t R, size_t C>
class Matrix
{
public:
    std::array<std::array<T, C>, R> values = {std::array<T, C>()};

    template <typename Ty = T, size_t Ry = R, size_t Cy = C>
    static constexpr Matrix<Ty, Ry, Cy> identity()
    {
        static_assert(Ry == Cy, "Identity matrix can only be generated for square matrix.");

        Matrix<Ty, Ry, Cy> mat;

        for (size_t i = 0; i < R && i < C; i++)
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

    template <typename Tl, size_t Rl, size_t Cl, typename Tr, size_t Rr, size_t Cr>
    friend auto operator*(const Matrix<Tl, Rl, Cl> &l, const Matrix<Tr, Rr, Cr> &r) -> Matrix<decltype(std::declval<Tl &>() * std::declval<Tr &>()), Rl, Cr>
    {
        static_assert(Cl == Rr, "Right matrix rows count me be equal to left matrix columns count.");

        using MulT = decltype(std::declval<Tl &>() * std::declval<Tr &>());

        Matrix<MulT, Rl, Cr> mat;

        for (size_t i = 0; i < Rl; i++)
        {
            for (size_t j = 0; j < Cr; j++)
            {
                auto value = MulT();

                for (size_t k = 0; k < Rr; k++)
                {
                    value += l[i][k] * r[k][j];
                }

                mat[i][j] = value;
            }
        }

        return mat;
    }

    template <typename Tl, size_t Rl, size_t Cl, typename Ry>
    friend auto operator*(const Matrix<Tl, Rl, Cl> &l, const Ry &r) -> Matrix<decltype(std::declval<Tl &>() * std::declval<Ry &>()), Rl, Cl>
    {
        Matrix<decltype(std::declval<Tl &>() * std::declval<Ry &>()), Rl, Cl> mat;

        for (size_t y = 0; y < Rl; y++)
        {
            for (size_t x = 0; x < Cl; x++)
            {
                mat[y][x] = l[y][x] * r;
            }
        }

        return mat;
    }

    template <typename Tr, size_t Rr, size_t Cr>
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

    template <typename Ty, size_t Ry, size_t Cy>
    operator Matrix<Ty, Ry, Cy>()
    {
        auto mat = Matrix<Ty, Ry, Cy>();

        for (size_t y = 0; y < Ry; y++)
        {
            for (size_t x = 0; x < Cy; x++)
            {
                mat[y][x] = static_cast<Ty>((*this)[y][x]);
            }
        }

        return mat;
    }

    inline std::array<T, C> &operator[](size_t i)
    {
        return this->values[i];
    }

    inline const std::array<T, C> &operator[](size_t i) const
    {
        return this->values[i];
    }
};

} // namespace Unicy

#include <unicy/Matrix.inl>
