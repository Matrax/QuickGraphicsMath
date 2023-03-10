#pragma once

#include "vector.hpp"

#include <string>
#include <cmath>
#include <exception>
#include <stdexcept>

namespace QuickMathCpp
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
	template<typename T, unsigned int n, unsigned int m> class Matrix
	{
	private:

		T m_data[n * m];

	public:

		Matrix<T, n, m>()
		{
			for (unsigned long i = 0; i < n * m; i++)
				m_data[i] = 0;
		}

		Matrix<T, n, m>(Matrix<T, n, m>& copy)
		{
			for (unsigned long i = 0; i < n * m; i++)
				m_data[i] = copy.m_data[i];
		}

		Matrix<T, n, m>(const Matrix<T, n, m>& copy)
		{
			for (unsigned long i = 0; i < n * m; i++)
				m_data[i] = copy.m_data[i];
		}

		Matrix<T, n, m>(const T data[n * m])
		{
			for (unsigned long i = 0; i < n * m; i++)
				m_data[i] = data[i];
		}

		static Matrix<T, n, m> Identity()
		{
			Matrix<T, n, m> result;

			for (unsigned long i = 0; i < n * m; i++)
			{
				if (i % j == 0)
				{
					result.m_data[j + i * n] = 1;
				}
				else {
					result.m_data[j + i * n] = 0;
				}
			}

			return result;
		}

		static Matrix<T, 4, 4> Translation(Vector3f translation)
		{
			Matrix<T, 4, 4> result = Identity();

			result.m_data[3] = translation.GetX();
			result.m_data[7] = translation.GetY();
			result.m_data[11] = translation.GetZ();

			return result;
		}

		static Matrix<T, 4, 4> Scale(Vector3f scale)
		{
			Matrix<T, 4, 4> result = Identity();

			result.m_data[0] = scale.GetX();
			result.m_data[5] = scale.GetY();
			result.m_data[10] = scale.GetZ();

			return result;
		}

		std::string ToString() const
		{
			std::string str("[ ");

			for (unsigned long i = 0; i < n * m - 1; i++)
			{
				if (i % n == 0 && i != 0) str.append("\n  ");
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

		T GetData(unsigned long at) const
		{
			if (at >= n * m)
				throw std::runtime_error("Can't get the data !");

			return m_data[at];
		}

		void SetData(unsigned long at, T value)
		{
			if (at >= n * m)
				throw std::runtime_error("Can't set the data !");

			m_data[at] = value;
		}

		Matrix<T, n, m> operator+(const Matrix<T, n, m>& other)
		{
			Matrix<T, n, m> result;

			for (unsigned long i = 0; i < n * m; i++)
				result.m_data[i] = m_data[i] + other.m_data[i];

			return result;
		}

		Matrix<T, n, m>& operator+=(const Matrix<T, n, m>& other)
		{
			for (unsigned long i = 0; i < n * m; i++)
				m_data[i] = m_data[i] + other.m_data[i];

			return *this;
		}

		Matrix<T, n, m> operator-(const Matrix<T, n, m>& other)
		{
			Matrix<T, n, m> result;

			for (unsigned long i = 0; i < n * m; i++)
				result.m_data[i] = m_data[i] - other.m_data[i];

			return result;
		}

		Matrix<T, n, m> operator*(const Matrix<T, n, m>& other)
		{
			Matrix<T, n, m> result;

			for (unsigned long i = 0; i < n; i++)
			{
				for (unsigned long j = 0; j < m; j++)
				{
					for (unsigned long k = 0; k < n; k++)
					{
						result.m_data[j + i * n] += m_data[j + k * m] * other.m_data[k + i * m];
					}
				}
			}

			return result;
		}

		Matrix<T, n, m> operator*(const T other)
		{
			Matrix<T, n, m> result;

			for (unsigned long i = 0; i < n * m; i++)
				result.m_data[i] = m_data[i] * other;

			return result;
		}

		Vector<T, m> operator*(const Vector<T, m> other)
		{
			Vector<T, m> result;

			for (unsigned long i = 0; i < n; i++)
			{
				for (unsigned long j = 0; j < m; j++)
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

