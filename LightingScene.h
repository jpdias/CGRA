#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "ExampleObject.h"
#include "Plane.h"
#include "myCylinder.h"
#include "MyClockHand.h"
#include "MyRobot.h"


class LightingScene : public CGFscene
{
public:
	void init();
	void display();
	void toggleSomething();
	int sceneVar;
	int state1,state2,state3,state4,activar,wire;
	bool state5;

	int statetext;


	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;

	myTable* table;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;

	MyRobot* robot;

	CGFappearance* materialA;
	CGFappearance* materialB;
	CGFappearance* robotapp;
	CGFappearance* robotapp1;
	CGFappearance* robotapp2;
	CGFappearance* boardAppearance;
	CGFappearance* slidesAppearance;
	CGFappearance* windowAppearance;
	CGFappearance* floorAppearance;
	CGFappearance* clearapp;
	CGFappearance* clockAppearance;
	CGFappearance* blissAppearance;
	CGFlight* newlight;
	virtual void update(long);
	~LightingScene();
};

#endif