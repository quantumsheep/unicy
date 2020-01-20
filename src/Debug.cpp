#include <unicy/Debug.hpp>

#include <sstream>
#include <chrono>

static std::string pad_time(const long &t)
{
    return ((t <= 9) ? "0" : "") + std::to_string(t);
}

namespace Unicy
{

std::string Debug::TimeString()
{
    auto now = std::chrono::system_clock::now();

    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(seconds);
    auto hours = std::chrono::duration_cast<std::chrono::hours>(minutes);

    auto h = (hours.count() + 1) % 24;
    auto m = minutes.count() % 60;
    auto s = seconds.count() % 60;

    return "[" + pad_time(h) + ":" + pad_time(m) + ":" + pad_time(s) + "] ";
}

} // namespace Unicy
