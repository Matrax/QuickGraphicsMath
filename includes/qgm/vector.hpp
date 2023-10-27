#pragma once

// STD includes
#include <string>

// QGM includes
#include <qgm/math.hpp>

namespace qgm
{
	template<typename T, size_t size> 
	class Vector
	{
	private:

		T m_data[size];

	public:

		Vector<T, size>()
		{
			for (size_t i = 0; i < size; i++)
				m_data[i] = 0;
		}

		Vector<T, size>(Vector<T, size>& copy)
		{
			for (size_t i = 0; i < size; i++)
				m_data[i] = copy.m_data[i];
		}

		Vector<T, size>(const Vector<T, size>& copy)
		{
			for (size_t i = 0; i < size; i++)
				m_data[i] = copy.m_data[i];
		}

		Vector<T, size>(T x, T y)
		{
			static_assert(size >= 2, "Can't instantiate with less than 2 parameters !");

			m_data[0] = x;
			m_data[1] = y;
		}

		Vector<T, size>(T x, T y, T z)
		{
			static_assert(size >= 3, "Can't instantiate with  less than 3 parameters !");

			m_data[0] = x;
			m_data[1] = y;
			m_data[2] = z;
		}

		Vector<T, size>(T x, T y, T z, T w)
		{
			static_assert(size >= 4, "Can't instantiate with  less than 4 parameters !");

			m_data[0] = x;
			m_data[1] = y;
			m_data[2] = z;
			m_data[3] = w;
		}

		T Distance(Vector<T, size> other)
		{
			double sum = 0;
			for (size_t i = 0; i < size; i++)
				sum += (m_data[i] - other.m_data[i]) * (m_data[i] - other.m_data[i]);
			return static_cast<T>(std::abs(std::sqrt(sum)));
		}

		T Magnitude()
		{
			double magnitude = 0;
			for (size_t i = 0; i < size; i++)
				magnitude += m_data[i] * m_data[i];
			return static_cast<T>(std::sqrt(magnitude));
		}

		T Dot(Vector<T, size> other)
		{
			double dot = 0;
			for (size_t i = 0; i < size; i++)
				dot += m_data[i] * other.m_data[i];

			return static_cast<T>(dot);
		}

		Vector<T, size> Cross(Vector<T, size> other)
		{
			static_assert(size >= 3, "Can't get the cross product, it is not a Vector3 !");

			Vector<T, size> result;
			result.m_data[0] = m_data[1] * other.m_data[2] - m_data[2] * other.m_data[1];
			result.m_data[1] = m_data[2] * other.m_data[0] - m_data[0] * other.m_data[2];
			result.m_data[2] = m_data[0] * other.m_data[1] - m_data[1] * other.m_data[0];
			return result;
		}

		Vector<T, size> Normalize()
		{
			Vector<T, size> result;

			T magnitude = Magnitude();
			if (magnitude == 0)
				return result;

			double magnitude_inv = 1.0 / magnitude;
			for (size_t i = 0; i < size; i++)
				result.m_data[i] = static_cast<T>(m_data[i] * magnitude_inv);

			return result;
		}

		std::string ToString() const
		{
			std::string str("[ ");

			for (size_t i = 0; i < size - 1; i++)
			{
				std::string data = std::to_string(m_data[i]);
				str.append(data);
				str.append(",");
			}

			std::string last_data = std::to_string(m_data[size - 1]);
			str.append(last_data);
			str.append(" ]");

			return str;
		}

		T* GetPtr()
		{
			static_assert(m_data != nullptr, "Can't get the pointer because it is null !");

			return m_data;
		}

		T GetX() const
		{
			static_assert(size >= 1, "Can't get the X coordinate !");

			return m_data[0];
		}

		T GetY() const
		{
			static_assert(size >= 2, "Can't get the Y coordinate !");

			return m_data[1];
		}

		T GetZ() const
		{
			static_assert(size >= 3, "Can't get the Z coordinate !");

			return m_data[2];
		}

		T GetW() const
		{
			static_assert(size >= 4, "Can't get the Z coordinate !");

			return m_data[3];
		}

		T GetData(const unsigned long at) const
		{
			if(at >= size)
				return 0;

			return m_data[at];
		}

		void SetX(T x)
		{
			static_assert(size >= 1, "Can't set the X coordinate !");

			m_data[0] = x;
		}

		void SetY(T y)
		{
			static_assert(size >= 2, "Can't set the Y coordinate !");

			m_data[1] = y;
		}

		void SetZ(T z)
		{
			static_assert(size >= 3, "Can't set the Z coordinate !");

			m_data[2] = z;
		}

		void SetW(T w)
		{
			static_assert(size >= 4, "Can't set the W coordinate !");

			m_data[3] = w;
		}
		
		void SetXY(T x, T y)
		{
			static_assert(size >= 2, "Can't set the XY coordinate !");

			m_data[0] = x;
			m_data[1] = y;
		}

		void SetXYZ(T x, T y, T z)
		{
			static_assert(size >= 3, "Can't set the XYZ coordinate !");

			m_data[0] = x;
			m_data[1] = y;
			m_data[2] = z;
		}

		void SetXYZW(T x, T y, T z, T w)
		{
			static_assert(size >= 4, "Can't set the XYZW coordinate !");

			m_data[0] = x;
			m_data[1] = y;
			m_data[2] = z;
			m_data[3] = w;
		}

		void SetData(unsigned long at, T value)
		{
			static_assert(at >= size, "Can't set the coordinate !");

			m_data[at] = value;
		}

		Vector<T, size> operator+(Vector<T, size> other)
		{
			Vector<T, size> result;

			for (size_t i = 0; i < size; i++)
				result.m_data[i] = m_data[i] + other.m_data[i];

			return result;
		}

		Vector<T, size>& operator+=(Vector<T, size> other)
		{
			for (size_t i = 0; i < size; i++)
				m_data[i] = m_data[i] + other.m_data[i];

			return *this;
		}

		Vector<T, size> operator-(Vector<T, size> other)
		{
			Vector<T, size> result;

			for (size_t i = 0; i < size; i++)
				result.m_data[i] = m_data[i] - other.m_data[i];

			return result;
		}

		Vector<T, size> operator*(Vector<T, size> other)
		{
			Vector<T, size> result;

			for (size_t i = 0; i < size; i++)
				result.m_data[i] = m_data[i] * other.m_data[i];

			return result;
		}

		Vector<T, size> operator*(T other)
		{
			Vector<T, size> result;

			for (size_t i = 0; i < size; i++)
				result.m_data[i] = m_data[i] * other;

			return result;
		}
	};

	// Usings
	using Vector2d = Vector<double, 2>;
	using Vector3d = Vector<double, 3>;
	using Vector4d = Vector<double, 4>;
	using Vector2f = Vector<float, 2>;
	using Vector3f = Vector<float, 3>;
	using Vector4f = Vector<float, 4>;
	using Vector2i = Vector<int, 2>;
	using Vector3i = Vector<int, 3>;
	using Vector4i = Vector<int, 4>;
	using Vector2ui = Vector<unsigned int, 2>;
	using Vector3ui = Vector<unsigned int, 3>;
	using Vector4ui = Vector<unsigned int, 4>;
	using Vector2l = Vector<long, 2>;
	using Vector3l = Vector<long, 3>;
	using Vector4l = Vector<long, 4>;
	using Vector2ul = Vector<unsigned long, 2>;
	using Vector3ul = Vector<unsigned long, 3>;
	using Vector4ul = Vector<unsigned long, 4>;
}