#ifndef _CYCLONE_PRECISION
#define _CYCLONE_PRECISION

namespace cyclone
{
	/**
	 * Asigna un nombre alternativo al tipo float, con el fin
	 * de poder cambiarlo fácilmente a double si es necesario
	 */
	typedef float real;
	#define real_sqrt sqrtf
	#define real_acos acosf
	#define TO_RADIANS 3.141592 / 180
	#define TO_DEGREES 180 / 3.141592
}

#endif