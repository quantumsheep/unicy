#pragma once

#include <string>
#include <unicy/has_insertion_operator.hpp>

namespace Unicy::Debug
{

std::string TimeString();

inline void Log(const std::string &data)
{
    std::cout << Debug::TimeString() << data << std::endl;
}

template <typename T, std::enable_if_t<has_insertion_operator<T>::value> * = nullptr>
inline void Log(const T &obj)
{
    std::cout << Debug::TimeString() << obj << std::endl;
}

} // namespace Unicy::Debug
