#pragma once

namespace Unicy
{

enum class EnvironmentError
{
    None,

    FailedToInitializeGLFW,
    FailedToCreateWindow,
    FailedToLoadGLAD,
};

} // namespace Unicy
