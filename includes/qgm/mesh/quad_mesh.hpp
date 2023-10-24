#pragma once

#include <qgm/mesh/mesh.hpp>

namespace qgm
{
	class QuadMesh : public Mesh
	{
	public:

		QuadMesh() : Mesh(6)
        {
            AddPosition(-0.5f, -0.5f, 0.0f);
            AddPosition(0.5f, -0.5f, 0.0f);
            AddPosition(-0.5f, 0.5f, 0.0f);
            AddPosition(0.5f, 0.5f, 0.0f);

            AddNormal(0, 0, 1);
            AddNormal(0, 0, 1);
            AddNormal(0, 0, 1);
            AddNormal(0, 0, 1);

            AddTangente(1, 0, 0);
            AddTangente(1, 0, 0);
            AddTangente(1, 0, 0);
            AddTangente(1, 0, 0);

            AddUV(0, 0);
            AddUV(1, 0);
            AddUV(0, 1);
            AddUV(1, 1);

            AddIndex(0);
            AddIndex(1);
            AddIndex(3);
            AddIndex(0);
            AddIndex(2);
            AddIndex(3);
        }

        virtual ~QuadMesh() {}
	};
}