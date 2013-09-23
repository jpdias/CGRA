#pragma once
#include "CGFobject.h"

class Plane
{
public:
	Plane(void);
	Plane(int);
	~Plane(void);
	void draw(float racio);
	void draw();
	void drawsq();
	void drawfloor();
	void drawbliss();
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
};

