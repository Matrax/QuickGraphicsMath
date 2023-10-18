#pragma once

// STD includes
#include <string>
#include <string_view>
#include <vector>

namespace qgm
{
	class Mesh
	{
	private:

		std::vector<float> m_positions;
		std::vector<float> m_normals;
		std::vector<float> m_tangentes;
        std::vector<float> m_uvs;
		std::vector<unsigned int> m_indices;
		const unsigned long m_vertices_count;

	public:

		Mesh() = delete;

        Mesh(const unsigned long vertices_count) :
            m_positions(vertices_count * 3),
            m_uvs(vertices_count * 2),
            m_indices(vertices_count),
            m_vertices_count(vertices_count)
        {
            m_positions.clear();
            m_normals.clear();
            m_tangentes.clear();
            m_indices.clear();
            m_uvs.clear();
        }

        virtual ~Mesh() {}

        inline static Mesh CreateTriangleMesh()
        {
            Mesh mesh(3);

            mesh.AddPosition(-0.5f, -0.5f, 0.0f);
            mesh.AddPosition(0.5f, -0.5f, 0.0f);
            mesh.AddPosition(0.0f, 0.5f, 0.0f);

            mesh.AddNormal(0, 0, -1);
            mesh.AddNormal(0, 0, -1);
            mesh.AddNormal(0, 0, -1);

            mesh.AddTangente(1, 0, 0);
            mesh.AddTangente(1, 0, 0);
            mesh.AddTangente(1, 0, 0);

            mesh.AddUV(0, 0);
            mesh.AddUV(0, 1);
            mesh.AddUV(0.5f, 1);

            return mesh;
        }

        inline static Mesh CreateQuadMesh()
        {
            Mesh mesh(6);

            mesh.AddPosition(-0.5f, -0.5f, 0.0f);
            mesh.AddPosition(0.5f, -0.5f, 0.0f);
            mesh.AddPosition(-0.5f, 0.5f, 0.0f);
            mesh.AddPosition(0.5f, 0.5f, 0.0f);

            mesh.AddNormal(0, 0, 1);
            mesh.AddNormal(0, 0, 1);
            mesh.AddNormal(0, 0, 1);
            mesh.AddNormal(0, 0, 1);

            mesh.AddTangente(1, 0, 0);
            mesh.AddTangente(1, 0, 0);
            mesh.AddTangente(1, 0, 0);
            mesh.AddTangente(1, 0, 0);

            mesh.AddUV(0, 0);
            mesh.AddUV(1, 0);
            mesh.AddUV(0, 1);
            mesh.AddUV(1, 1);

            mesh.AddIndex(0);
            mesh.AddIndex(1);
            mesh.AddIndex(3);
            mesh.AddIndex(0);
            mesh.AddIndex(2);
            mesh.AddIndex(3);

            return mesh;
        }

        void AddPosition(const float x, const float y, const float z) noexcept
        {
            m_positions.push_back(x);
            m_positions.push_back(y);
            m_positions.push_back(z);
        }

        void AddNormal(const float x, const float y, const float z) noexcept
        {
            m_normals.push_back(x);
            m_normals.push_back(y);
            m_normals.push_back(z);
        }

        void AddTangente(const float x, const float y, const float z) noexcept
        {
            m_tangentes.push_back(x);
            m_tangentes.push_back(y);
            m_tangentes.push_back(z);
        }

        void AddUV(const float x, const float y) noexcept
        {
            m_uvs.push_back(x);
            m_uvs.push_back(y);
        }

        void AddIndex(const unsigned int index) noexcept
        {
            m_indices.push_back(index);
        }

        const std::vector<float> & GetPositions() noexcept
        {
            return m_positions;
        }

        const std::vector<float> & GetNormals() noexcept
        {
            return m_normals;
        }

        const std::vector<float> & GetTangentes() noexcept
        {
            return m_tangentes;
        }

        const std::vector<float> & GetUVS() noexcept
        {
            return m_uvs;
        }

        const std::vector<unsigned int> & GetIndices() noexcept
        {
            return m_indices;
        }

        const std::vector<float> GetAll() noexcept
        {
            std::vector<float> data;
            
            for(float f : m_positions)
            {
                data.push_back(f);
            }

            for(float f : m_normals)
            {
                data.push_back(f);
            }

            for(float f : m_tangentes)
            {
                data.push_back(f);
            }

            for(float f : m_uvs)
            {
                data.push_back(f);
            }

            return data;
        }

        const unsigned long GetVerticesCount() noexcept
        {
            return m_vertices_count;
        }
        
	};
}