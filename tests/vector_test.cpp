// STD includes
#include <iostream>

// QGM includes
#include <matrix.hpp>

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
    return 0;
}