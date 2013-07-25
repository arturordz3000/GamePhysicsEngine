#ifndef _CYCLONE_PARTICLE
#define _CYCLONE_PARTICLE

#include "precision.h";
#include "core.h"

namespace cyclone
{
	class Particle
	{
	public:
		/** Posicion lineal de la part�cula */
		Vector3 position;
		
		/** Velocidad lineal de la part�cula */
		Vector3 velocity;

		/** Aceleraci�n de la part�cula (la gravedad, por ejemplo) */
		Vector3 acceleration;

		/** 
		*	Fuerza de amortiguaci�n, es decir, es la fuerza necesaria
		*   para detener a nuestro objeto seg�n la 1ra ley de Newton
		*	sobre el movimiento. Este valor va de 0 a 1
		*/
		real damping;
	}
}

#endif