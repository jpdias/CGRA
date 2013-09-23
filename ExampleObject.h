#ifndef EXAMPLEOBJECT_H
#define EXAMPLEOBJECT_H

#include "CGFobject.h"
#include "CGFappearance.h"

class ExampleObject: public CGFobject {
	public:
		void draw();
};

class myUnitCube: public CGFobject{
public:
	void draw();
};

class myTable: public CGFobject{
public:
	CGFappearance* tableAppearance;
	CGFappearance* random;
	void draw();
	void appear();
};

class myFloor: public CGFobject{
public:
	void draw();
};

#endif