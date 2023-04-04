#pragma once

#include <cmath>

#include "defines.hpp"

namespace qgm
{
    inline float cos(float t) noexcept
    {
        return std::cos(t);
    }

    inline float sin(float t) noexcept
    {
        return std::sin(t);
    }

    inline float tan(float t) noexcept
    {
        return std::tan(t);
    }

    inline float acos(float t) noexcept
    {
        return std::acos(t);
    }

    inline float asin(float t) noexcept
    {
        return std::asin(t);
    }

    inline float atan(float t) noexcept
    {
        return std::atan(t);
    }
}