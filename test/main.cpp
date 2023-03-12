#include <iostream>

#include "../includes/matrix.hpp"

int main()
{
    // Test Vector
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

    // Test Matrix
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