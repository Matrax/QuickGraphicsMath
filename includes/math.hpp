#pragma once

#include <cmath>

#include "defines.hpp"

namespace qgm
{
    inline float pow(float x, float power)
    {
        return std::pow(x, power);
    }

    inline float linear_function(float a, float b, float x) noexcept
    {
        return a * x + b;
    }

    inline float linear_interpolation(float xa, float ya, float xb, float yb, float x) noexcept
    {
        return ya + (x - xa) * ((yb - ya) / (xb - xa));
    }

    inline float circle_equation(float center_x, float center_y, float radius, float x, float y)
    {
        return qgm::pow(x - center_x, 2) * qgm::pow(y - center_y, 2) - qgm::pow(radius, 2);
    }

    inline float sphere_equation(float center_x, float center_y, float center_z, float radius, float x, float y, float z)
    {
        return qgm::pow(x - center_x, 2) * qgm::pow(y - center_y, 2) * qgm::pow(z - center_z, 2) - qgm::pow(radius, 2);
    }
}