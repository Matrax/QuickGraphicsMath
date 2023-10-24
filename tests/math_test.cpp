// STD includes
#include <iostream>

// QGM includes
#include <qgm/math.hpp>

int main()
{
    
    std::cout << qgm::LinearInterpolation<float>(0.7, 0.8, 0.5) << std::endl;
    std::cout << qgm::BilinearInterpolation<float>(0.7, 0.8, 0.7, 0.8, 0.5, 0.5) << std::endl;
    std::cout << qgm::FastSqrt<float>(27) << std::endl;

    return 0;
}