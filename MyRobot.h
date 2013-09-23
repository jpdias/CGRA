#ifndef MY_ROBOT
#define MY_ROBOT

#include "CGFobject.h"
#include "Math.h"
#include <vector>
#include "Newell.h"
class MyRobot : public CGFobject {
	

public:
	int stacks;
	double x, z;
	float ang;
	MyRobot();
	std::vector<float> squarex;
	std::vector<float> squarez;
	std::vector<float> circlex;
	std::vector<float> circlez;
	std::vector<float> stack;
	void draw();
	void move(int x, int y);
	void move(float ang);

};




#endif