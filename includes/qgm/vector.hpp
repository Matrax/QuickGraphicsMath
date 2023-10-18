#pragma once

// STD includes
#include <string>
#include <exception>
#include <stdexcept>

// QGM includes
#include <qgm/math.hpp>
#include <qgm/defines.hpp>

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
			if (size < 2)
				throw std::runtime_error("Can't instantiate with 2 parameters !");

			m_data[0] = x;
			m_data[1] = y;
		}

		Vector<T, size>(T x, T y, T z)
		{
			if (size < 3)
				throw std::runtime_error("Can't instantiate with 3 parameters !");

			m_data[0] = x;
			m_data[1] = y;
			m_data[2] = z;
		}

		Vector<T, size>(T x, T y, T z, T w)
		{
			if (size < 4)
				throw std::runtime_error("Can't instantiate with 4 parameters !");

			m_data[0] = x;
			m_data[1] = y;
			m_data[2] = z;
			m_data[3] = w;
		}

		inline static Vector<T, size> RandomDirection()
		{
			Vector<T, size> result;

			for (size_t i = 0; i < size; i++)
			{
				T random_value = static_cast<T>(std::rand());
				T random_value_2 = static_cast<T>(std::rand());
				result.m_data[i] = qgm::Cos<T>(random_value) + qgm::Sin<T>(random_value_2);
			}

			return result.Normalize();
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
			return m_data;
		}

		T GetX() const
		{
			return m_data[0];
		}

		T GetY() const
		{
			if (size < 2)
				throw std::runtime_error("Can't get the Y coordinate !");

			return m_data[1];
		}

		T GetZ() const
		{
			if (size < 3)
				throw std::runtime_error("Can't get the Z coordinate !");

			return m_data[2];
		}

		T GetW() const
		{
			if (size < 4)
				throw std::runtime_error("Can't get the W coordinate !");

			return m_data[3];
		}

		T GetData(unsigned long at) const
		{
			if (at >= size)
				throw std::runtime_error("Can't get the data !");

			return m_data[at];
		}

		void SetX(T x)
		{
			m_data[0] = x;
		}

		void SetY(T y)
		{
			if (size < 2)
				throw std::runtime_error("Can't set the Y coordinate !");

			m_data[1] = y;
		}

		void SetZ(T z)
		{
			if (size < 3)
				throw std::runtime_error("Can't set the Z coordinate !");

			m_data[2] = z;
		}

		void SetW(T w)
		{
			if (size < 4)
				throw std::runtime_error("Can't set the W coordinate !");

			m_data[3] = w;
		}
		
		void SetXY(T x, T y)
		{
			if (size < 2)
				throw std::runtime_error("Can't set the XY coordinates !");

			m_data[0] = x;
			m_data[1] = y;
		}

		void SetXYZ(T x, T y, T z)
		{
			if (size < 3)
				throw std::runtime_error("Can't set the XYZ coordinates !");

			m_data[0] = x;
			m_data[1] = y;
			m_data[2] = z;
		}

		void SetXYZW(T x, T y, T z, T w)
		{
			if (size < 4)
				throw std::runtime_error("Can't set the XYZW coordinates !");

			m_data[0] = x;
			m_data[1] = y;
			m_data[2] = z;
			m_data[3] = w;
		}

		void SetData(unsigned long at, T value)
		{
			if (at >= size)
				throw std::runtime_error("Can't set the data !");

			m_data[at] = value;
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
			if (size < 3)
				throw std::runtime_error("Can't get the cross product !");

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
	using Vector2f = Vector<float, 2>;
	using Vector3f = Vector<float, 3>;
	using Vector4f = Vector<float, 4>;
	using Vector2i = Vector<int, 2>;
	using Vector3i = Vector<int, 3>;
	using Vector4i = Vector<int, 4>;
}