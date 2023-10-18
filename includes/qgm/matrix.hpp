#pragma once

// STD includes
#include <string>
#include <exception>
#include <stdexcept>

// QGM includes
#include <qgm/math.hpp>
#include <qgm/defines.hpp>
#include <qgm/vector.hpp>

namespace qgm
{
	/*
	* This class allow to create a matrix of n * m size with any primitive type, in row-major order.
	* So if you want to use this class with OpenGl, you need to transpose the matrix before sending it.
	*
	* Here is an example with a 4x4 matrix.
	* Row-major order (number = index)
	* [0,  1,  2,  3 ]
	* [4,  5,  6,  7 ]
	* [8,  9,  10, 11]
	* [12, 13, 14, 15]
	*/
	template<typename T, size_t n, size_t m> class Matrix
	{
	private:

		T m_data[n * m];

	public:

		Matrix<T, n, m>()
		{
			for (size_t i = 0; i < n * m; i++)
				m_data[i] = 0;
		}

		Matrix<T, n, m>(Matrix<T, n, m>& copy)
		{
			for (size_t i = 0; i < n * m; i++)
				m_data[i] = copy.m_data[i];
		}

		Matrix<T, n, m>(const Matrix<T, n, m>& copy)
		{
			for (size_t i = 0; i < n * m; i++)
				m_data[i] = copy.m_data[i];
		}

		Matrix<T, n, m>(const T data[n * m])
		{
			for (size_t i = 0; i < n * m; i++)
				m_data[i] = data[i];
		}

		static Matrix<T, n, m> Identity()
		{
			Matrix<T, n, m> result;

			size_t j = 0;
			for (size_t i = 0; i < n * m; i++)
			{
				if (i == j)
				{
					result.m_data[i] = 1;
					j += n + 1;
				}
			}

			return result;
		}

		static Matrix<T, 3, 3> Translation2D(const Vector2f translation)
		{
			Matrix<T, 3, 3> result = Identity();
			result.m_data[2] = translation.GetX();
			result.m_data[5] = translation.GetY();
			return result;
		}

		static Matrix<T, 4, 4> Translation(const Vector3f translation)
		{
			Matrix<T, 4, 4> result = Identity();
			result.m_data[3] = translation.GetX();
			result.m_data[7] = translation.GetY();
			result.m_data[11] = translation.GetZ();
			return result;
		}

		static Matrix<T, 3, 3> Scale2D(const Vector2f scale)
		{
			Matrix<T, 3, 3> result = Identity();
			result.m_data[0] = scale.GetX();
			result.m_data[4] = scale.GetY();
			return result;
		}

		static Matrix<T, 4, 4> Scale(const Vector3f scale)
		{
			Matrix<T, 4, 4> result = Identity();
			result.m_data[0] = scale.GetX();
			result.m_data[5] = scale.GetY();
			result.m_data[10] = scale.GetZ();
			return result;
		}

		static Matrix<T, 3, 3> Rotation2D(const float rotation)
		{
			Matrix<T, 3, 3> result = Identity();
			result.m_data[0] = qgm::Cos<float>(rotation);
			result.m_data[1] = qgm::Sin<float>(rotation);
			result.m_data[3] = -qgm::Sin<float>(rotation);
			result.m_data[4] = qgm::Cos<float>(rotation);
			return result;
		}

		static Matrix<T, 4, 4> RotationX(const float rotation)
		{
			Matrix<T, 4, 4> result = Identity();
			result.m_data[5] = qgm::Cos<float>(rotation);
			result.m_data[6] = qgm::Sin<float>(rotation);
			result.m_data[9] = -qgm::Sin<float>(rotation);
			result.m_data[10] = qgm::Cos<float>(rotation);
			return result;
		}

		static Matrix<T, 4, 4> RotationY(const float rotation)
		{
			Matrix<T, 4, 4> result = Identity();
			result.m_data[0] = qgm::Cos<float>(rotation);
			result.m_data[2] = qgm::Sin<float>(rotation);
			result.m_data[8] = -qgm::Sin<float>(rotation);
			result.m_data[10] = qgm::Cos<float>(rotation);
			return result;
		}

		static Matrix<T, 4, 4> RotationZ(const float rotation)
		{
			Matrix<T, 4, 4> result = Identity();
			result.m_data[0] = qgm::Cos<float>(rotation);
			result.m_data[1] = qgm::Sin<float>(rotation);
			result.m_data[4] = -qgm::Sin<float>(rotation);
			result.m_data[5] = qgm::Cos<float>(rotation);
			return result;
		}

		static Matrix<T, 4, 4> Rotation(const Vector3f rotation)
		{
			Matrix<T, 4, 4> result = RotationX(rotation.GetX()) * RotationY(rotation.GetY()) * RotationZ(rotation.GetZ());
			return result;
		}

		static Matrix<T, 4, 4> ViewMatrixNoTranslation(Vector3f direction, Vector3f world_up = Vector3f(0.0f, 1.0f, 0.0f))
		{
			Vector3f forward = direction.Normalize();
			Vector3f right = forward.Cross(world_up).Normalize();
			Vector3f up = right.Cross(forward).Normalize();

			Matrix<T, 4, 4> camera_rotation = Identity();
			camera_rotation.m_data[0] = right.GetX();
			camera_rotation.m_data[1] = right.GetY();
			camera_rotation.m_data[2] = right.GetZ();
			camera_rotation.m_data[4] = up.GetX();
			camera_rotation.m_data[5] = up.GetY();
			camera_rotation.m_data[6] = up.GetZ();
			camera_rotation.m_data[8] = -forward.GetX();
			camera_rotation.m_data[9] = -forward.GetY();
			camera_rotation.m_data[10] = -forward.GetZ();
 
			return camera_rotation;
		}

		static Matrix<T, 4, 4> ViewMatrix(Vector3f position, Vector3f direction, Vector3f world_up = Vector3f(0.0f, 1.0f, 0.0f))
		{
			Vector3f forward = direction.Normalize();
			Vector3f right = forward.Cross(world_up).Normalize();
			Vector3f up = right.Cross(forward).Normalize();

			Matrix<T, 4, 4> camera_translation = Translation(Vector3f(-position.GetX(), -position.GetY(), -position.GetZ()));

			Matrix<T, 4, 4> camera_rotation = Identity();
			camera_rotation.m_data[0] = right.GetX();
			camera_rotation.m_data[1] = right.GetY();
			camera_rotation.m_data[2] = right.GetZ();
			camera_rotation.m_data[4] = up.GetX();
			camera_rotation.m_data[5] = up.GetY();
			camera_rotation.m_data[6] = up.GetZ();
			camera_rotation.m_data[8] = -forward.GetX();
			camera_rotation.m_data[9] = -forward.GetY();
			camera_rotation.m_data[10] = -forward.GetZ();
			
			Matrix<T, 4, 4> result = camera_translation * camera_rotation;
			return result;
		}

		static Matrix<T, 3, 3> ViewMatrix2D(const Vector2f position, const float aspect_ratio)
		{
			Matrix<T, 3, 3> result = Identity();
			result.m_data[0] = 1.0f;
			result.m_data[4] = 1.0f / aspect_ratio;
			result.m_data[2] = -position.GetX();
			result.m_data[5] = -position.GetY();
			result.m_data[8] = 1.0f;
			return result;
		}

		static Matrix<T, 4, 4> PerspectiveProjection(const float nearZ, const float farZ, const float field_of_view, const float aspect_ratio)
		{
			Matrix<T, 4, 4> result = Identity();
			result.m_data[0] = 1.0f / (qgm::Tan(field_of_view / 2.0f * qgm::RADIANS_FACTOR));
			result.m_data[5] = 1.0f / (qgm::Tan(field_of_view / 2.0f * qgm::RADIANS_FACTOR)) * aspect_ratio;
			result.m_data[10] = -farZ / (farZ - nearZ);
			result.m_data[11] = -2 * (farZ * nearZ) / (farZ - nearZ);
			result.m_data[14] = -1.0f;
			result.m_data[15] = 0.0f;
			return result;
		}

		std::string ToString() const
		{
			std::string str("[ ");
			for (size_t i = 0; i < n * m - 1; i++)
			{
				if (i % n == 0 && i != 0) str.append("\n  ");
				std::string data = std::to_string(m_data[i]);
				str.append(data);
				str.append(",");
			}

			std::string last_data = std::to_string(m_data[n * m - 1]);
			str.append(last_data);
			str.append(" ]");
			
			return str;
		}

		T * GetPtr()
		{
			return m_data;
		}

		T GetData(unsigned long at) const
		{
			if (at >= n * m)
				throw std::runtime_error("Can't get the data !");

			return m_data[at];
		}

		void SetData(const size_t at, T value)
		{
			if (at >= n * m)
				throw std::runtime_error("Can't set the data !");

			m_data[at] = value;
		}

		Matrix<T, n, m> operator+(Matrix<T, n, m> other)
		{
			Matrix<T, n, m> result;

			for (size_t i = 0; i < n * m; i++)
				result.m_data[i] = m_data[i] + other.m_data[i];

			return result;
		}

		Matrix<T, n, m>& operator+=(Matrix<T, n, m> other)
		{
			for (size_t i = 0; i < n * m; i++)
				m_data[i] = m_data[i] + other.m_data[i];

			return *this;
		}

		Matrix<T, n, m> operator-(Matrix<T, n, m> other)
		{
			Matrix<T, n, m> result;

			for (size_t i = 0; i < n * m; i++)
				result.m_data[i] = m_data[i] - other.m_data[i];

			return result;
		}

		Matrix<T, n, m> operator*(Matrix<T, n, m> other)
		{
			Matrix<T, n, m> result;

			for (size_t i = 0; i < n; i++)
			{
				for (size_t j = 0; j < m; j++)
				{
					for (size_t k = 0; k < n; k++)
					{
						result.m_data[j + i * n] += m_data[j + k * m] * other.m_data[k + i * m];
					}
				}
			}

			return result;
		}

		Matrix<T, n, m> operator*(T other)
		{
			Matrix<T, n, m> result;

			for (size_t i = 0; i < n * m; i++)
				result.m_data[i] = m_data[i] * other;

			return result;
		}

		Vector<T, m> operator*(Vector<T, m> other)
		{
			Vector<T, m> result;

			for (size_t i = 0; i < n; i++)
			{
				for (size_t j = 0; j < m; j++)
				{
					result.SetData(i, result.GetData(i) + m_data[j + i * n] * other.GetData(j));
				}
			}

			return result;
		}
	};

	// Usings
	using Matrix2f = Matrix<float, 2, 2>;
	using Matrix3f = Matrix<float, 3, 3>;
	using Matrix4f = Matrix<float, 4, 4>;
	using Matrix2i = Matrix<int, 2, 2>;
	using Matrix3i = Matrix<int, 3, 3>;
	using Matrix4i = Matrix<int, 4, 4>;
}