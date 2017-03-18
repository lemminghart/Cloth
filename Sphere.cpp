#include "../Sphere.h"
#include <glm\gtc\matrix_transform.hpp>

Esfera::Esfera() {
	//setup the initial parameters (position)
	radius = ((float)rand() / RAND_MAX) * 2.f + 2.f;;

	//setup the initial position
	pos.x = ((float)rand() / RAND_MAX) * 10.f - 5.f;;
	pos.y = ((float)rand() / RAND_MAX) * 10.f - 5.f;;
	pos.z = ((float)rand() / RAND_MAX) * 10.f - 5.f;;

}

Esfera::~Esfera() {

}
