#pragma once
#include <vector>

struct Coord { float x, y, z; };

//enum Type { WATERFALL = 0, FOUNTAIN = 1, BASIC = 2 };

class Particle {
public:
	Coord currentPos, lastPos; //Stores Current and Last Position
	Coord currentV, lastV; //Stores Current and Last Velocity
	//float lifeTime; //Life time of the particle
	bool fixed; //states if particle is animated or not

	Particle(bool fix, Coord pos);
	Particle(Particle *part, float separationX, float separationZ);
	~Particle();
};

static std::vector <Particle> partArray; //vector de particulas