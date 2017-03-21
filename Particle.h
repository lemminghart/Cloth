#pragma once
#include <vector>


class Particle {
public:
	glm::vec3 currentPos, lastPos; //Stores Current and Last Position
	glm::vec3 currentV, lastV; //Stores Current and Last Velocity
	//float lifeTime; //Life time of the particle
	bool fixed; //states if particle is animated or not

	Particle(bool fix, glm::vec3 pos);
	Particle(Particle *part, float separationX, float separationZ);
	~Particle();
};

static std::vector <Particle> partArray; //vector de particulas