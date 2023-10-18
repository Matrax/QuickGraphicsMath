#pragma once

// STD includes
#include <cmath>

// QGM includes
#include <qgm/defines.hpp>

//
#undef min
#undef max

namespace qgm
{

    template<typename T>
    inline T Pow(const T x, const T power) noexcept
    {
        return std::pow(x, power);
    }

    template<typename T>
    inline T Min(T a, T b) noexcept
    {
        if(a > b) return b;
        return a;
    }

    template<typename T>
    inline T Max(T a, T b) noexcept
    {
        if(a > b) return a;
        return b;
    }

    template<typename T>
    inline T Clamp(const T min, const T x, const T max) noexcept
    {
        if(x < min) return min;
        if(x > max) return max;
        return x;
    }
    
    /**
    * Square root method using Heron algorithm 
    */
    template<typename T, unsigned char precision = 8>
    inline T FastSqrt(const T t) noexcept 
    { 
        double u = static_cast<double>(t);

        for(unsigned char i = 0; i < precision; i++)
        {
            u = (u + t / u) * 0.5;
        }

        return static_cast<float>(u); 
    }

    template<typename T>
    inline T LinearFunction(const T a, const T b, const T x) noexcept
    {
        return a * x + b;
    }

    template<typename T>
    inline T LinearInterpolation(const T xa, const T xb, const T x) noexcept
    {
        return xa + (xb - xa) * x;
    }

    template<typename T>
    inline T BilinearInterpolation(const T bottom_left, const T bottom_right, const T top_left, const T top_right, const T x, const T y)
    {
        return bottom_left * x * y + bottom_right * (1 - x) * y + top_left * x * (1 - y) + top_right * (1 - x) * (1 - y);
    }

    template<typename T>
    inline T CircleEquation(const T center_x, const T center_y, const T radius, const T x, const T y)
    {
        return qgm::Pow<T>(x - center_x, 2) + qgm::Pow<T>(y - center_y, 2) - qgm::Pow<T>(radius, 2);
    }

    template<typename T>
    inline T SphereEquation(const T center_x, const T center_y, const T center_z, const T x, const T y, const T z, const T radius)
    {
        return qgm::Pow<T>(x - center_x, 2) + qgm::Pow<T>(y - center_y, 2) + qgm::Pow<T>(z - center_z, 2) - qgm::Pow<T>(radius, 2);
    }

    template<typename T>
    inline T Cos(const T t) noexcept { return std::cos(t); }
    
    template<typename T>
    inline T Sin(const T t) noexcept { return std::sin(t); }

    template<typename T>
    inline T Tan(const T t) noexcept { return std::tan(t); }

    template<typename T>
    inline T ACos(const T t) noexcept { return std::acos(t); }

    template<typename T>
    inline T ASin(const T t) noexcept { return std::asin(t); }

    template<typename T>
    inline T ATan(const T t) noexcept { return std::atan(t); }
    
}