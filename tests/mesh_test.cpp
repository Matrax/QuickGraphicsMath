// STD includes
#include <iostream>

// QGM includes
#include <qgm/mesh/quad_mesh.hpp>
#include <qgm/mesh/triangle_mesh.hpp>

int main()
{
    qgm::QuadMesh quad_mesh;
    qgm::TriangleMesh triangle_mesh;

    std::cout << "Quad vertices count : " << quad_mesh.GetVerticesCount() << std::endl;
    std::cout << "Triangle vertices count : " << triangle_mesh.GetVerticesCount() << std::endl;

    return 0;
}