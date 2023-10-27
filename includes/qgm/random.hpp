#pragma once

// QGM includes
#include <qgm/math.hpp>
#include <qgm/vector.hpp>

namespace qgm
{
    qgm::Vector2f RandomDirection(float x, float y, unsigned int seed = 0)
    {
        unsigned int cx = static_cast<unsigned int>(x * 95622600 + 161561561);
        unsigned int cy = static_cast<unsigned int>(y * 654564564 + 48948948);

        cx = (cx ^ cy) >> 4;
        cy = (cy ^ cx) >> 2;

        cx = (cx + 654564563) * cy;
        cy = (cy + 719711981) * cx * seed;

        float result = static_cast<float>(cx ^ cy) * qgm::PI * 1001.645498f;

        return qgm::Vector2f(qgm::Cos(result), qgm::Sin(result));
    }

    float PerlinNoise(float x, float y, int scale = 10)
    {
        // Convert coordinate to the grid coordinate
        x = x * (1.0f / static_cast<float>(scale));
        y = y * (1.0f / static_cast<float>(scale));

        // Get grid cell
        float x0 = std::floor(x) ;
        float y0 = std::floor(y);
        float x1 = (x0 + 1.0f);
        float y1 = (y0 + 1.0f);
    
        // Interpolation weights
        float sx = x - x0;
        float sy = y - y0;

        // Get dot products between the four gradient vectors and the four distance vectors
        float d1 = qgm::RandomDirection(x0, y0).Dot(qgm::Vector2f(x - x0, y - y0));
        float d2 = qgm::RandomDirection(x1, y0).Dot(qgm::Vector2f(x - x1, y - y0));
        float d3 = qgm::RandomDirection(x0, y1).Dot(qgm::Vector2f(x - x0, y - y1));
        float d4 = qgm::RandomDirection(x1, y1).Dot(qgm::Vector2f(x - x1, y - y1));

        // Interpolate the values (Bilinear interpolation)
        float i1 = qgm::LinearInterpolation(d1, d2, sx);
        float i2 = qgm::LinearInterpolation(d3, d4, sx);
        float final_value = qgm::LinearInterpolation(i1, i2, sy);

        return final_value;
    }

    float FBM( float x, float y, unsigned int octaves)
    {    
        float frequency = 1.0f;
        float amplitude = 1.0f;
        float current_noise = 0.0;

        for(unsigned int i = 0; i < octaves; i++)
        {
            current_noise += amplitude * qgm::PerlinNoise(frequency * x, frequency * y);
            frequency *= 2.0f;
            amplitude *= 0.5f;
        }

        return current_noise;
    }
}