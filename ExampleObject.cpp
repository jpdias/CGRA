#include "ExampleObject.h"

void myTable::appear(){
	tableAppearance = new CGFappearance("table.png", GL_REPEAT,GL_REPEAT);
	random =new CGFappearance();
}
void ExampleObject::draw() 
{
	glBegin(GL_QUADS);
	glVertex3d(0,0,0);
	glVertex3d(4,0,0);
	glVertex3d(4,3,0);
	glVertex3d(0,3,0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3d(-1,3,0);
	glVertex3d(5,3,0);
	glVertex3d(2,4,0);
	glEnd();


}


void myUnitCube::draw(){

	
	//Front
	glPushMatrix();
	glEnable(GL_NORMALIZE);
	glNormal3d(0,0,1);
	glTranslated(0,0,0.5);
	
	glBegin(GL_QUADS);     
	glTexCoord2d(-0.5,-0.5);
	glVertex3f (-0.5, -0.5, 0);
	glTexCoord2d(0.5,-0.5);
	glVertex3f ( 0.5, -0.5, 0);
	glTexCoord2d(0.5,0.5);
	glVertex3f ( 0.5,  0.5, 0);
	glTexCoord2d(-0.5,0.5);
	glVertex3f (-0.5,  0.5, 0);
	glEnd();
	glPopMatrix();
	//BOT
	glPushMatrix();
	glEnable(GL_NORMALIZE);
	glNormal3d(0,0,1);
	glRotated(90,1,0,0);
	glTranslated(0,0,0.5);
	glBegin(GL_QUADS);     
	glTexCoord2d(-0.5,-0.5);
	glVertex3f (-0.5, -0.5, 0);
	glTexCoord2d(0.5,-0.5);
	glVertex3f ( 0.5, -0.5, 0);
	glTexCoord2d(0.5,0.5);
	glVertex3f ( 0.5,  0.5, 0);
	glTexCoord2d(-0.5,0.5);
	glVertex3f (-0.5,  0.5, 0);
	glEnd();
	glPopMatrix();
	//Back
	glPushMatrix();
	glEnable(GL_NORMALIZE);
	glNormal3d(0,0,1);
	glRotated(180,1,0,0);
	glTranslated(0,0,0.5);
	glBegin(GL_QUADS);     
	glTexCoord2d(-0.5,-0.5);
	glVertex3f (-0.5, -0.5, 0);
	glTexCoord2d(0.5,-0.5);
	glVertex3f ( 0.5, -0.5, 0);
	glTexCoord2d(0.5,0.5);
	glVertex3f ( 0.5,  0.5, 0);
	glTexCoord2d(-0.5,0.5);
	glVertex3f (-0.5,  0.5, 0);
	glEnd();
	glPopMatrix();
	//Right
	glPushMatrix();
	glEnable(GL_NORMALIZE);
	glNormal3d(0,0,1);
	glRotated(90,0,1,0);
	glTranslated(0,0,0.5);
	glBegin(GL_QUADS);     
	glTexCoord2d(-0.5,-0.5);
	glVertex3f (-0.5, -0.5, 0);
	glTexCoord2d(0.5,-0.5);
	glVertex3f ( 0.5, -0.5, 0);
	glTexCoord2d(0.5,0.5);
	glVertex3f ( 0.5,  0.5, 0);
	glTexCoord2d(-0.5,0.5);
	glVertex3f (-0.5,  0.5, 0);
	glEnd();
	glPopMatrix();
	//Left
	glPushMatrix();
	glEnable(GL_NORMALIZE);
	glNormal3d(0,0,1);
	glRotated(-90,0,1,0);
	glTranslated(0,0,0.5);
	glBegin(GL_QUADS);     
	glTexCoord2d(-0.5,-0.5);
	glVertex3f (-0.5, -0.5, 0);
	glTexCoord2d(0.5,-0.5);
	glVertex3f ( 0.5, -0.5, 0);
	glTexCoord2d(0.5,0.5);
	glVertex3f ( 0.5,  0.5, 0);
	glTexCoord2d(-0.5,0.5);
	glVertex3f (-0.5,  0.5, 0);
	glEnd();
	glPopMatrix();
	//TOP
	glPushMatrix();
	glEnable(GL_NORMALIZE);
	glNormal3d(0,0,1);
	glRotated(-90,1,0,0);
	glTranslated(0,0,0.5);
	glBegin(GL_QUADS);     
	glTexCoord2d(-0.5,-0.5);
	glVertex3f (-0.5, -0.5, 0);
	glTexCoord2d(0.5,-0.5);
	glVertex3f ( 0.5, -0.5, 0);
	glTexCoord2d(0.5,0.5);
	glVertex3f ( 0.5,  0.5, 0);
	glTexCoord2d(-0.5,0.5);
	glVertex3f (-0.5,  0.5, 0);
	glEnd();
	glPopMatrix();
	

}

void myFloor::draw(){

	myUnitCube bot;

	glScaled(8,0.1,6);

	bot.draw();

}

void myTable::draw(){
	
	appear();

	glPushMatrix();
	myUnitCube tampo;
	tableAppearance->apply();
	glTranslated(0,3.5,0);
	glScaled(5,0.3,3);
	tampo.draw();
	glPopMatrix();

	glPushMatrix();
	myUnitCube perna1;
	random->apply();
	glTranslated(2.25,1.875,1.25);
	glScaled(0.3,3.5,0.3);
	
	perna1.draw();
	glPopMatrix();

	glPushMatrix();
	myUnitCube perna2;
	glTranslated(-2.25,1.875,1.25);
	glScaled(0.3,3.5,0.3);
	perna2.draw();
	glPopMatrix();

	glPushMatrix();
	myUnitCube perna3;
	glTranslated(2.25,1.875,-1.25);
	glScaled(0.3,3.5,0.3);
	perna3.draw();
	glPopMatrix();

	glPushMatrix();
	myUnitCube perna4;
	
	glTranslated(-2.25,1.875,-1.25);
	glScaled(0.3,3.5,0.3);
	perna4.draw();
	glPopMatrix();

	
}