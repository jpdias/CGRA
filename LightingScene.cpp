#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "ExampleObject.h"
#include "Plane.h"
#include "MyClock.h"
#include <math.h>
#include "MyRobot.h"


int a;
MyClock relo;
float pi = acos(-1.0);
float deg2rad=pi/180.0;
long  tempo=0;
#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for two lights
float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light1_pos[4] = {10.5, 6.0, 1.0, 1.0};

float light2_pos[4] = {10.5, 6.0, 5.0, 1.0};
float light3_pos[4] = {4, 6.0, 5.0, 1.0};

float newlight_pos[4]={0,1.5,1.5,1.0};

// Global ambient light (do not confuse with ambient component of individual lights)
//float globalAmbientLight[4]= {0.2,0.2,0.2,1.0};
float globalAmbientLight[4]= {0,0,0,0};

// number of divisions
#define BOARD_A_DIVISIONS 1
#define BOARD_B_DIVISIONS 30 // 100

// Coefficients for material A
/*float ambA[3] = {0.2, 0.2, 0.2};
float difA[3] = {0.6, 0.6, 0.6};
float specA[3] = {0.2, 0.2, 0.2};
float shininessA = 10.f;*/
float ambA[3] = {0.2, 0.2, 0.2};
float difA[3] = {0.6, 0.6, 0.6};
float specA[3] = {0, 0.2, 0.8};
float shininessA = 120.f;

// Coefficients for material B
float ambB[3] = {0.5, 0.5, 0.5};
float difB[3] = {0.6, 0.6, 0.6};
float specB[3] = {0.8, 0.8, 0.8};
float shininessB = 120.f;

float ambC[3] = {0.5, 0.5, 0.5};
float difC[3] = {0.4, 0.4, 0.4};
float specC[3] = {0.6, 0.6, 0.6};
float shininessC = 200.0f;


float ambientNull[4]={0,0,0,1};
float yellow[4]={1,1,0,1};


void LightingScene::init() 
{
	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);  

	// Define ambient light (do not confuse with ambient component of individual lights)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);  

	//TPinterface

	sceneVar=0;
	state5=true;
	wire=false;

	// Declares and enables two lights, with null ambient component



	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setAmbient(ambientNull);
	light0->setSpecular(yellow);
	//light0->disable();
	light0->enable();

	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);

	//light1->disable();
	light1->enable();

	//Light 2
	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);
	light2->setKc(0);
	light2->setKl(1);
	light2->setKq(0);
	//light2->disable();
	light2->enable();


	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	light3->setSpecular(yellow);
	light3->setKc(0);
	light3->setKl(0);
	light3->setKq(0.2);
	//light3->disable();
	light3->enable();

	newlight = new CGFlight(GL_LIGHT3, newlight_pos);
	newlight->setAmbient(ambientNull);
	newlight->setSpecular(yellow);
	newlight->setKc(0);
	newlight->setKl(0);
	newlight->setKq(0.2);
	newlight->enable();
	// Uncomment below to enable normalization of lighting normal vectors
	// glEnable (GL_NORMALIZE);

	//Declares scene elements
	table = new myTable();
	wall = new Plane();
	boardA = new Plane(BOARD_A_DIVISIONS);
	boardB = new Plane(BOARD_B_DIVISIONS);



	robot = new MyRobot();

	//Declares materials
	materialA = new CGFappearance(ambA,difA,specA,shininessA);
	materialB = new CGFappearance(ambB,difB,specB,shininessB);
	slidesAppearance = new CGFappearance("slides.png",GL_REPEAT,GL_REPEAT);
	boardAppearance = new CGFappearance("board.png",GL_CLAMP,GL_CLAMP);
	floorAppearance =new CGFappearance("floor.png",GL_REPEAT,GL_REPEAT);
	windowAppearance =new CGFappearance("window.png",GL_CLAMP,GL_CLAMP);
	clockAppearance = new CGFappearance("clock.png", GL_CLAMP, GL_CLAMP);

	blissAppearance = new CGFappearance("bliss.png",GL_CLAMP, GL_CLAMP);
	robotapp = new CGFappearance("robot1.png", GL_REPEAT,GL_REPEAT);
	robotapp1 = new CGFappearance("robot2.png",  GL_REPEAT,GL_REPEAT);
	robotapp2 = new CGFappearance("robot3.png", GL_REPEAT,GL_REPEAT);
	clearapp =new CGFappearance();
	slidesAppearance->setDiffuse(difA);
	slidesAppearance->setAmbient(ambA);
	slidesAppearance->setSpecular(specA);
	slidesAppearance->setShininess(shininessA);

	boardAppearance->setAmbient(ambC);
	boardAppearance->setDiffuse(difC);
	boardAppearance->setSpecular(specC);
	boardAppearance->setShininess(shininessC);

	setUpdatePeriod(100);

}

void LightingScene::display() 
{

	// ---- BEGIN Background, camera and axis setup

	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();
	//printf("textx: %d",statetext1);
	light0->draw();
	light1->draw();
	light2->draw();
	light3->draw();
	// Draw axis
	axis.draw();
	//glShadeModel(GL_FLAT);
	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section


	if(!state1)
		light0->disable();
	else
	{
		light0->enable();
	}
	if(!state2)
		light1->disable();
	else
	{
		light1->enable();
	}
	if(!state3)
		light2->disable();
	else
	{
		light2->enable();
	}
	if(!state4)
		light3->disable();
	else
	{
		light3->enable();
	}


	//First Table
	glPushMatrix();
	glTranslated(5,0,8);

	table->draw();
	glPopMatrix();

	//Second Table
	/*glPushMatrix();
	glTranslated(12,0,8);
	table->draw();
	glPopMatrix();*/

	//Floor
	glPushMatrix();
	glTranslated(7.5,0,7.5);
	glScaled(15,0.2,15);
	floorAppearance->apply();
	wall->drawfloor();
	glPopMatrix();

	//LeftWall
	glPushMatrix();
	glTranslated(0,0,15);
	glRotated(90,0,1,0);
	glScaled(15,8,0.2);
	windowAppearance->apply();// APPL
	wall->drawsq();
	glPopMatrix();

	//bliss
	glPushMatrix();
	glTranslated(-3,4,7.5);
	glRotated(-90.0,0,0,1);
	glScaled(3,3,3);
	blissAppearance->apply();// APPL
	glScaled(8,0.2,15);
	wall->drawbliss();
	glPopMatrix();

	//PlaneWall
	glPushMatrix();
	clearapp->apply();
	glTranslated(7.5,4,0);
	glRotated(90.0,1,0,0);
	glScaled(15,0.2,8);
	wall->draw();
	glPopMatrix();


	// Board A
	glPushMatrix();

	glTranslated(4,4,0.2);
	glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
	glRotated(90.0,1,0,0);
	slidesAppearance->apply();
	//materialA->apply();
	boardA->draw();
	glPopMatrix();

	//PlaneB
	glPushMatrix();

	glTranslated(10.5,4,0.2);
	glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
	glRotated(90.0,1,0,0);
	//materialB->apply();
	boardAppearance->apply();
	boardB->draw(512.0/372.0);
	glPopMatrix();



	//Clock



	glPushMatrix();
	glTranslated(7.2,8.1,0.1);
	clockAppearance->apply();
	relo.drawClock();
	clearapp->apply();
	glPopMatrix();


	if(state5){
		relo.update(true);
		glPushMatrix();
		glTranslated(7.2,8.1,0.1);
		myClokHand hour;
		hour.draw(2,90-relo.anghour);
		glPopMatrix();

		glPushMatrix();
		glTranslated(7.2,8.1,0.1);
		myClokHand min;
		min.draw(1,90-relo.angmin);
		glPopMatrix();

		glPushMatrix();
		glTranslated(7.2,8.1,0.1);
		myClokHand sec;
		sec.draw(3,90-relo.angsec);
		glPopMatrix();
	}
	else
	{
		relo.update(false);
		glPushMatrix();
		glTranslated(7.2,8.1,0.1);
		myClokHand hour;
		hour.draw(2,90-relo.anghour);
		glPopMatrix();

		glPushMatrix();
		glTranslated(7.2,8.1,0.1);
		myClokHand min;
		min.draw(1,90-relo.angmin);
		glPopMatrix();

		glPushMatrix();
		glTranslated(7.2,8.1,0.1);
		myClokHand sec;
		sec.draw(3,90-relo.angsec);
		glPopMatrix();
	}




	glPushMatrix();

	if(wire)
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
	else 
		glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );


	glTranslated(robot->x,0,robot->z);
	glRotated(robot->ang,0,1,0);
	if(statetext==1){
		robotapp->apply();
	}
	else if(statetext==2){
		robotapp1->apply();
	}
	else if(statetext==3){
		robotapp2->apply();
	}
	robot->draw();
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
	glPopMatrix();





	// ---- END Primitive drawing section
	//relo.update(true);

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();


}

LightingScene::~LightingScene() 
{
	delete(light0);
	delete(light1);

	delete(table);
	delete(wall);
	delete(boardA);
	delete(boardB);
	delete(materialA);
	delete(materialB);
}

void LightingScene::update(long temp){

	tempo=temp;
}

void LightingScene::toggleSomething(){
};