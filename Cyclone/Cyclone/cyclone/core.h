#ifndef _CYCLONE_CORE
#define _CYCLONE_CORE

#include <iostream>
#include <math.h>
#include "precision.h"

using namespace std;

namespace cyclone
{	
	class Vector3
	{
	public:
		/** Los tres componentes de un vector (x, y, z) */
		real x;
		real y;
		real z;

	private:
		/** Variable sin uso que nos ayuda a evitar el desalineamiento */
		real pad;
		
	public:
		/** Constructor default que crea un vector cero */
		Vector3() : x(0), y(0), z(0) {}

		/** Constructor que crea un vector con los valores definidos */
		Vector3(const real x, const real y, const real z) : x(x), y(y), z(z) {}

		/** Invierte los valores del vector */
		void invert()
		{
			x = -x;
			y = -y;
			z = -z;
		}

		/** Calcula la magnitud del vector */
		real magnitude() const
		{
			return real_sqrt(x*x + y*y + z*z);
		}

		/** Calcula la magnitud cuadrada del vector */
		real squareMagnitude() const
		{
			return x*x + y*y + z*z;
		}

		/** Normaliza el vector y lo vuelve unitario */
		void normalize()
		{
			real m = magnitude();

			if(m > 0)
			{
				x *= 1/m;
				y *= 1/m;
				z *= 1/m;
			}
		}

		/** Suma este vector y otro vector con escala dada */
		void addScaledVector(Vector3& vector, real scale)
		{
			x += vector.x * scale;
			y += vector.y * scale;
			z += vector.z * scale;
		}

		/** Regresa el producto de los componentes de este vector y el vector dado */
		Vector3 componentProduct(const Vector3& vector) const
		{
			return Vector3(x * vector.x, y * vector.y, z * vector.z);
		}

		/** Multiplica los componentes de este vector y el vector dado y actualiza */
		void componentProductUpdate(const Vector3& vector)
		{
			x *= vector.x;
			y *= vector.y;
			z *= vector.z;
		}

		/** Realiza el producto escalar (producto punto) regresando el resultado */
		real scalarProduct(const Vector3& vector) const
		{
			return x * vector.x + y * vector.y + z * vector.z;
		}

		/** Realiza el producto escalar (producto punto) regresando el resultado */
		real operator*(const Vector3& vector)
		{
			return x * vector.x + y * vector.y + z * vector.z; 
		}

		/** Obtiene el angulo en radianes entre este vector y el vector dado */
		real angleBetweenRadians(const Vector3& vector) const
		{
			Vector3 a = (*this);
			Vector3 b = vector;

			/**
			 * Normalizar es dividir el vector entre su magnitud, osea:
			 *		a / |a|
			 *		b / |b|
			 */
			a.normalize(); b.normalize();

			/**
			 * El ángulo entre dos vectores puede obtenerse mediante la siguiente fórmula:
			 *		a * b = |a| * |b| * cos(theta)
			 *
			 * Despejando theta de lo anterior:
			 *		theta = acos((a / |a|) * (b / |b|))
			 *
			 * Dado a que ya se normalizaron los vectores,
			 * simplemente saco el coseno inverso del producto escalar de los vectores
			 */
			return real_acos(a * b);
		}

		/** Obtiene el angulo en grados entre este vector y el vector dado */
		real angleBetweenDegrees(const Vector3& vector) const
		{
			Vector3 a = (*this);
			Vector3 b = vector;

			/**
			 * Normalizar es dividir el vector entre su magnitud, osea:
			 *		a / |a|
			 *		b / |b|
			 */
			a.normalize(); b.normalize();

			/**
			 * El ángulo entre dos vectores puede obtenerse mediante la siguiente ecuación:
			 *		a * b = |a| * |b| * cos(theta)
			 *
			 * Despejando theta de lo anterior:
			 *		theta = acos((a / |a|) * (b / |b|))
			 *
			 * Dado a que ya se normalizaron los vectores,
			 * simplemente saco el coseno inverso del producto escalar de los vectores y convierto a grados
			 */
			return real_acos(a * b) * TO_DEGREES;
		}

		/** Realiza el producto vector (producto cruz) regresando el resultado */
		Vector3 vectorProduct(const Vector3& vector) const
		{
			return Vector3(y * vector.z - z * vector.y, 
						   z * vector.x - x * vector.z, 
						   x * vector.y - y * vector.x);
		}

		/** Realiza el producto vector (producto cruz) regresando el resultado */
		void operator%=(const Vector3& vector)
		{
			*this = vectorProduct(vector);
		}

		/** Realiza el producto vector (producto cruz) regresando el resultado */
		Vector3 operator%(const Vector3& vector) const
		{
			return vectorProduct(vector);
		}

		/** Multiplica este vector por un escalar */
		void operator*=(const real value)
		{
			x *= value;
			y *= value;
			z *= value;
		}

		/** Regresa una copia de la multiplicación de este vector por un escalar */
		Vector3 operator*(const real value) const
		{
			return Vector3(x * value, y * value, z * value);
		}

		/** Suma este vector y el vector dado */
		void operator+=(const Vector3& vector)
		{
			x += vector.x;
			y += vector.y;
			z += vector.z;
		}

		/** Suma este vector y el vector dado, regresando una copia */
		Vector3 operator+(Vector3& vector) const
		{
			return Vector3(x + vector.x, y + vector.y, z + vector.z);
		}

		/** Resta este vector y el vector dado */
		void operator-=(const Vector3& vector)
		{
			x -= vector.x;
			y -= vector.y;
			z -= vector.z;
		}

		/** Resta este vector y el vector dado, regresando una copia */
		Vector3 operator-(Vector3& vector) const
		{
			return Vector3(x - vector.x, y - vector.y, z - vector.z);
		}
	};

	/** Sobrecarga el operador "<<" para cuando se quiera imprimir el vector */
	ostream& operator<<(ostream& os, Vector3& vector)
	{
		os << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return os;
	}
}

#endif