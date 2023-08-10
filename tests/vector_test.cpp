// STD includes
#include <iostream>

// QGM includes
#include <qgm/vector.hpp>
#include <qgm/math.hpp>

int main()
{
    qgm::Vector3f v1(1, 2, 3);
    qgm::Vector3f v2(1, 2, 3);
    qgm::Vector3f v3(1, 2, 3);
    qgm::Vector3f v4 = v1 + v2 * v3;

    std::cout << "Vector V1: " << std::endl;
    std::cout << v1.ToString() << std::endl;
    std::cout << "Vector V2: " << std::endl;
    std::cout << v2.ToString() << std::endl;
    std::cout << "Vector V3: " << std::endl;
    std::cout << v3.ToString() << std::endl;
    std::cout << "Vector V1 + V2 * V3: " << std::endl;
    std::cout << v4.ToString() << std::endl;

    std::cout << qgm::LinearInterpolation<float>(0.7, 0.8, 0.5) << std::endl;
    std::cout << qgm::BilinearInterpolation<float>(0.7, 0.8, 0.7, 0.8, 0.5, 0.5) << std::endl;

    return 0;
}