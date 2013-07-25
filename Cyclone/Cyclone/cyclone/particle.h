#ifndef _CYCLONE_PARTICLE
#define _CYCLONE_PARTICLE

#include "precision.h";
#include "core.h"

namespace cyclone
{
	class Particle
	{
	public:
		/** Posicion lineal de la partícula */
		Vector3 position;
		
		/** Velocidad lineal de la partícula */
		Vector3 velocity;

		/** Aceleración de la partícula (la gravedad, por ejemplo) */
		Vector3 acceleration;

		/** 
		*	Fuerza de amortiguación, es decir, es la fuerza necesaria
		*   para detener a nuestro objeto según la 1ra ley de Newton
		*	sobre el movimiento. Este valor va de 0 a 1
		*/
		real damping;
	}
}

#endif