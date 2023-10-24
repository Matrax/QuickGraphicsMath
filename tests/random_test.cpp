// STD includes
#include <iostream>

// QGM includes
#include <qgm/random.hpp>

int main()
{
    
    std::cout << "Perlin noise (0, 0) : " << qgm::PerlinNoise(0, 0, 10) << std::endl;
    std::cout << "Random direction (0, 0), seed = 0 : " << qgm::RandomDirection(0, 0, 0).ToString() << std::endl;

    return 0;
}