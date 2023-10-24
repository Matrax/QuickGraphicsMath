#pragma once

#include <qgm/mesh/mesh.hpp>

namespace qgm
{
	class TriangleMesh : public Mesh
	{
	public:

		TriangleMesh() : Mesh(3)
        {
            AddPosition(-0.5f, -0.5f, 0.0f);
            AddPosition(0.5f, -0.5f, 0.0f);
            AddPosition(0.0f, 0.5f, 0.0f);

            AddNormal(0, 0, 1);
            AddNormal(0, 0, 1);
            AddNormal(0, 0, 1);

            AddTangente(1, 0, 0);
            AddTangente(1, 0, 0);
            AddTangente(1, 0, 0);

            AddUV(0, 0);
            AddUV(0, 1);
            AddUV(0.5f, 1);
        }

        virtual ~TriangleMesh() {}
	};
}