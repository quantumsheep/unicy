#pragma once

#include <iostream>
#include <type_traits>
#include <utility>

namespace Unicy
{

template <typename Ty, typename = void>
struct has_insertion_operator : std::false_type
{
};

template <typename Ty>
struct has_insertion_operator<
    Ty,
    std::void_t<decltype(std::declval<std::ostream &>() << std::declval<Ty>())>>
    : std::true_type
{
};

} // namespace Unicy
