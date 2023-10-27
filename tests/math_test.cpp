// STD includes
#include <iostream>

// QGM includes
#include <qgm/math.hpp>

int main()
{
    
    std::cout << "LinearInterpolation<float>(0.7, 0.8, 0.5): " << qgm::LinearInterpolation<float>(0.7, 0.8, 0.5) << std::endl;
    std::cout << "BilinearInterpolation<float>(0.7, 0.8, 0.7, 0.8, 0.5, 0.5): " << qgm::BilinearInterpolation<float>(0.7, 0.8, 0.7, 0.8, 0.5, 0.5) << std::endl;
    std::cout << "FastSqrt<float>(27): " << qgm::FastSqrt<float>(27) << std::endl;
    std::cout << "FastSin<float>(0.32): " << qgm::FastSin<float>(0.32) << std::endl;
    std::cout << "Sin<float>(0.32): " << qgm::Sin<float>(0.32) << std::endl;
    std::cout << "FastCos<float>(0.32): " << qgm::FastCos<float>(0.32) << std::endl;
    std::cout << "Cos<float>(0.32): " << qgm::Cos<float>(0.32) << std::endl;
    return 0;
}
