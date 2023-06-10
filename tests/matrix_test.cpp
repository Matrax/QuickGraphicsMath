// STD includes
#include <iostream>

// QGM includes
#include <matrix.hpp>

int main()
{
    qgm::Matrix4f m1 = qgm::Matrix4f::Translation(qgm::Vector3f(1, 2, 3));
    qgm::Matrix4f m2 = qgm::Matrix4f::Scale(qgm::Vector3f(1, 2, 3));
    qgm::Matrix4f m3 = qgm::Matrix4f::Rotation(qgm::Vector3f(1, 2, 3));
    qgm::Matrix4f m4 = m1 + m2 * m3;
    std::cout << "Matrix M1: " << std::endl;
    std::cout << m1.ToString() << std::endl;
    std::cout << "Matrix M2: " << std::endl;
    std::cout << m2.ToString() << std::endl;
    std::cout << "Matrix M3: " << std::endl;
    std::cout << m3.ToString() << std::endl;
    std::cout << "Matrix M1 + M2 * M3: " << std::endl;
    std::cout << m4.ToString() << std::endl;
    return 0;
}