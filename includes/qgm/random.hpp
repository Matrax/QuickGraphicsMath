#pragma once

// QGM includes
#include <qgm/math.hpp>
#include <qgm/vector.hpp>

namespace qgm
{
    qgm::Vector2f RandomDirection(const float x, const float y, const unsigned int seed = 0)
    {
        unsigned int cx = static_cast<unsigned int>(x + 504.32f) * 95622600 + 161561561;
        unsigned int cy = static_cast<unsigned int>(y + 123.32f) * 654564564 + 48948948;

        cx = (cx + 654564563) * cy * seed * 98741;
        cy = (cy + 719711981) * cx * seed * 98741;

        float result = static_cast<float>(cx ^ cy) * 644.632f + qgm::PI * 1001.645498f;

        return qgm::Vector2f(qgm::Cos(result), qgm::Sin(result)).Normalize();
    }

    float PerlinNoise(const float x, const float y, const unsigned int grid_scale, const unsigned int seed = 0)
    {
        // Convert coordinate to the grid coordinate
        const float x_float = x / static_cast<float>(grid_scale);
        const float y_float = y / static_cast<float>(grid_scale);

        // Get grid cell
        const float x0 = std::floor(x_float) ;
        const float y0 = std::floor(y_float);
        const float x1 = (x0 + 1.0f);
        const float y1 = (y0 + 1.0f);
    
        // Interpolation weights
        const float sx = x_float - x0;
        const float sy = y_float - y0;

        // Distance vectors
        qgm::Vector2f d1 = qgm::Vector2f(x_float - x0, y_float - y0).Normalize();
        qgm::Vector2f d2 = qgm::Vector2f(x_float - x1, y_float - y0).Normalize();
        qgm::Vector2f d3 = qgm::Vector2f(x_float - x0, y_float - y1).Normalize();
        qgm::Vector2f d4 = qgm::Vector2f(x_float - x1, y_float - y1).Normalize();

        // Get dot products between the four gradient vectors and the four distance vectors
        const float dot1 = qgm::RandomDirection(x0, y0, seed).Dot(d1);
        const float dot2 = qgm::RandomDirection(x1, y0, seed).Dot(d2);
        const float dot3 = qgm::RandomDirection(x0, y1, seed).Dot(d3);
        const float dot4 = qgm::RandomDirection(x1, y1, seed).Dot(d4);

        // Interpolate the values (Bilinear interpolation)
        const float i1 = qgm::LinearInterpolation(dot1, dot2, sx);
        const float i2 = qgm::LinearInterpolation(dot3, dot4, sx);
        const float final_value = qgm::LinearInterpolation(i1, i2, sy);

        return final_value ;
    }

    float FBM(const float x, const float y, const unsigned int octaves, const unsigned int grid_scale, const unsigned int seed = 0)
    {    
        float frequency = 1.0f;
        float amplitude = 1.0f;
        float current_noise = 0.0;

        for(unsigned int i = 0; i < octaves; i++)
        {
            current_noise += amplitude * qgm::PerlinNoise(frequency * x, frequency * y, grid_scale, seed);
            frequency *= 2.0f;
            amplitude *= 0.5f;
        }

        return current_noise;
    }
}