#include <iostream>
#include "cyclone\core.h"

using namespace std;
using namespace cyclone;

void main()
{
	Vector3 v(1, -5, 0);
	Vector3 v2(-1, -5, 0);

	cout << v.angleBetweenDegrees(v2) << endl;

	system("PAUSE");
}