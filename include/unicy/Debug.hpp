#pragma once

#include <string>
#include <unicy/has_insertion_operator.hpp>

namespace Unicy::Debug
{

std::string TimeString();

template <std::ostream &stream = std::cout, typename T, std::enable_if_t<has_insertion_operator<T>::value> * = nullptr>
inline void Log(const T &obj, bool time = true)
{
    if (time)
        stream << Debug::TimeString();

    stream << obj << std::endl;
}

template <typename... Args>
inline void Log(FILE *stream, const char *fmt, const Args &... args)
{
    fprintf(stream, fmt, args...);
}

} // namespace Unicy::Debug
