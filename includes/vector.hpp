#pragma once

#include <string>
#include <cmath>
#include <exception>
#include <stdexcept>

namespace MatraxEngine
{
	template<typename T, unsigned int size> class Vector
	{
		private:

			T m_data[size];

		public:

			Vector<T, size>()
			{
				for (int i = 0; i < size; i++)
				{
					this->m_data[i] = 0;
				}
			}

			Vector<T, size>(const Vector<T, size> & copy)
			{
				for (int i = 0; i < size; i++)
				{
					this->m_data[i] = copy.m_data[i];
				}
			}

			Vector<T, size>(T x, T y)
			{
				if (size < 2)
					throw std::runtime_error("Can't instantiate with 2 parameters !");

				this->m_data[0] = x;
				this->m_data[1] = y;
			}

			Vector<T, size>(T x, T y, T z)
			{
				if (size < 3)
					throw std::runtime_error("Can't instantiate with 3 parameters !");

				this->m_data[0] = x;
				this->m_data[1] = y;
				this->m_data[2] = z;
			}

			Vector<T, size>(T x, T y, T z, T w)
			{
				if (size < 4)
					throw std::runtime_error("Can't instantiate with 4 parameters !");

				this->m_data[0] = x;
				this->m_data[1] = y;
				this->m_data[2] = z;
				this->m_data[3] = w;
			}

			std::string ToString() const
			{
				std::string str("[ ");
				for (int i = 0; i < size - 1; i++)
				{
					str.append(std::to_string(this->m_data[i]));
					str.append(",");
				}
				str.append(std::to_string(this->m_data[size - 1]));
				str.append(" ]");
				return str;
			}

			T* GetPtr()
			{
				return this->m_data;
			}

			T GetX() const
			{
				return this->m_data[0];
			}

			T GetY() const
			{
				if (size < 2)
					throw std::runtime_error("Can't get the Y coordinate !");

				return this->m_data[1];
			}

			T GetZ() const
			{
				if (size < 3)
					throw std::runtime_error("Can't get the Z coordinate !");

				return this->m_data[2];
			}

			T GetData(unsigned long at) const 
			{
				if(at >= size)
					throw std::runtime_error("Can't get the data !");

				return this->m_data[at];
			}

			void SetData(unsigned long at, T value)
			{
				if (at >= size)
					throw std::runtime_error("Can't set the data !");

				this->m_data[at] = value;
			}

			Vector<T, size> operator+(const Vector<T, size> & other)
			{
				Vector<T, size> result;

				for (int i = 0; i < size; i++)
				{
					result.m_data[i] = this->m_data[i] + other.m_data[i];
				}

				return result;
			}

			Vector<T, size> & operator+=(const Vector<T, size>& other)
			{
				for (int i = 0; i < size; i++)
				{
					this->m_data[i] = this->m_data[i] + other.m_data[i];
				}

				return *this;
			}

			Vector<T, size> operator-(const Vector<T, size>& other)
			{
				Vector<T, size> result;

				for (int i = 0; i < size; i++)
				{
					result.m_data[i] = this->m_data[i] - other.m_data[i];
				}

				return result;
			}

			Vector<T, size> operator*(const Vector<T, size>& other)
			{
				Vector<T, size> result;

				for (int i = 0; i < size; i++)
				{
					result.m_data[i] = this->m_data[i] * other.m_data[i];
				}

				return result;
			}

			Vector<T, size> operator*(const T other)
			{
				Vector<T, size> result;

				for (int i = 0; i < size; i++)
				{
					result.m_data[i] = this->m_data[i] * other;
				}

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

