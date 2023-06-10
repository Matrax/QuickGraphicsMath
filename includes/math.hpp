#pragma once

// STD includes
#include <cmath>

// QGM includes
#include "defines.hpp"

namespace qgm
{

    inline float cos(const float t) noexcept
    {
        return std::cos(t);
    }

    inline float sin(const float t) noexcept
    {
        return std::sin(t);
    }

    inline float tan(const float t) noexcept
    {
        return std::tan(t);
    }

    inline float acos(const float t) noexcept
    {
        return std::acos(t);
    }

    inline float asin(const float t) noexcept
    {
        return std::asin(t);
    }

    inline float atan(const float t) noexcept
    {
        return std::atan(t);
    }

    inline float pow(const float x, const float power)
    {
        return std::pow(x, power);
    }

    inline float min(const float a, const float b)
    {
        if(a > b) return b;
        return a;
    }

    inline float max(const float a, const float b)
    {
        if(a > b) return a;
        return b;
    }

    inline float clamp(const float min, const float x, const float max)
    {
        if(x < min) return min;
        if(x > max) return max;
        return x;
    }

    inline float linear_function(const float a, const float b, const float x) noexcept
    {
        return a * x + b;
    }

    inline float linear_interpolation(const float xa, const float xb, const float x) noexcept
    {
        return xa + (xb - xa) * x;
    }

    inline float linear_interpolation(const float xa, const float ya, const float xb, const float yb, const float x) noexcept
    {
        return ya + (x - xa) * ((yb - ya) / (xb - xa));
    }

    inline float circle_equation(const float center_x, const float center_y, const float radius, const float x, const float y)
    {
        return qgm::pow(x - center_x, 2) * qgm::pow(y - center_y, 2) - qgm::pow(radius, 2);
    }

    inline float sphere_equation(const float center_x, const float center_y, const float center_z, const float x, const float y, const float z, const float radius)
    {
        return qgm::pow(x - center_x, 2) * qgm::pow(y - center_y, 2) * qgm::pow(z - center_z, 2) - qgm::pow(radius, 2);
    }
}