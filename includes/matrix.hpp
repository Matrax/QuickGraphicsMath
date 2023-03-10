#pragma once

#include "vector.hpp"

#include <string>
#include <cmath>
#include <exception>
#include <stdexcept>

namespace MatraxEngine
{
	template<typename T, unsigned int n, unsigned int m> class Matrix
	{
		private:

			T m_data[n * m];

		public:

			Matrix<T, n, m>()
			{
				for (int i = 0; i < n * m; i++)
				{
					this->m_data[i] = 0;
				}
			}

			Matrix<T, n, m>(const Matrix<T, n, m> & copy)
			{
				for (int i = 0; i < n * m; i++)
				{
					this->m_data[i] = copy.m_data[i];
				}
			}

			Matrix<T, n, m>(const T data[n * m])
			{
				for (int i = 0; i < n * m; i++)
				{
					this->m_data[i] = data[i];
				}
			}

			static Matrix<T, n, m> Identity()
			{
				Matrix<T, n, m> result;

				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						if (i == j)
							result.m_data[j + i * n] = 1;
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
				result.m_data[12] = scale.GetX();
				result.m_data[13] = scale.GetY();
				result.m_data[14] = scale.GetZ();
				return result;
			}

			std::string ToString() const
			{
				std::string str("[ ");
				for (int i = 0; i < n * m - 1; i++)
				{
					if (i % n == 0 && i != 0) str.append("\n  ");
					str.append(std::to_string(this->m_data[i]));
					str.append(",");
				}
				str.append(std::to_string(this->m_data[n * m - 1]));
				str.append(" ]");
				return str;
			}

			T * GetPtr()
			{
				return this->m_data;
			}

			T GetData(unsigned long at) const
			{
				if (at >= n * m)
					throw std::runtime_error("Can't get the data !");

				return this->m_data[at];
			}

			void SetData(unsigned long at, T value)
			{
				if (at >= n * m)
					throw std::runtime_error("Can't set the data !");

				this->m_data[at] = value;
			}

			Matrix<T, n, m> operator+(const Matrix<T, n, m> & other)
			{
				Matrix<T, n, m> result;

				for (int i = 0; i < n * m; i++)
				{
					result.m_data[i] = this->m_data[i] + other.m_data[i];
				}

				return result;
			}

			Matrix<T, n, m> & operator+=(const Matrix<T, n, m> & other)
			{
				for (int i = 0; i < n * m; i++)
				{
					this->m_data[i] = this->m_data[i] + other.m_data[i];
				}

				return *this;
			}

			Matrix<T, n, m> operator-(const Matrix<T, n, m> & other)
			{
				Matrix<T, n, m> result;

				for (int i = 0; i < n * m; i++)
				{
					result.m_data[i] = this->m_data[i] - other.m_data[i];
				}

				return result;
			}

			Matrix<T, n, m> operator*(const Matrix<T, n, m> & other)
			{
				Matrix<T, n, m> result;

				// column
				for (int i = 0; i < n; i++)
				{
					// line
					for (int j = 0; j < m; j++)
					{
						for (int k = 0; k < n; k++)
						{
							result.m_data[j + i * n] += this->m_data[j + k * m] * other.m_data[k + i * m];
						}
					}
				}

				return result;
			}

			Matrix<T, n, m> operator*(const T other)
			{
				Matrix<T, n, m> result;

				for (int i = 0; i < n * m; i++)
				{
					result.m_data[i] = this->m_data[i] * other;
				}

				return result;
			}

			Vector<T, m> operator*(const Vector<T, m> other)
			{
				Vector<T, m> result;

				// column
				for (int i = 0; i < n; i++)
				{
					// line
					for (int j = 0; j < m; j++)
					{
						result.SetData(i, result.GetData(i) + this->m_data[j + i * n] * other.GetData(j));
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

