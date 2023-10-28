// STD includes
#include <iostream>

// QGM includes
#include <qgm/random.hpp>

int main()
{
    unsigned int time = std::time(nullptr);
    std::cout << "================================" << std::endl;
    std::cout << "Perlin noise (0, 0), seed = " << time << " : " << qgm::PerlinNoise(5, 5, 10, std::time(nullptr)) << std::endl;
    std::cout << "Random direction (0, 0), seed = 0 : " << qgm::RandomDirection(0, 0, 0).ToString() << std::endl;
    std::cout << "================================" << std::endl;
    for(unsigned int y = 0; y < 5; y++)
    {
        for(unsigned int x = 0; x < 5; x++)
        {
            std::cout << qgm::PerlinNoise(x, y, 10, time) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}