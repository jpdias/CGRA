#include "MyClockHand.h"
#include <Math.h>

#define pi acos(-1.0)


void myClokHand::draw(int type, float ang){
	float x=0,y=0,z=0;
	
	glRotated(ang,0,0,1);
	glRotated(90,0,1,0);


	if(type==1)
	{	x=0.4;
	y=0.045;
	z=0.045;
	glScaled(y,z,x);
	}
	if(type==2)
	{x=0.8;
	y=0.05;
	z=0.05;
	glScaled(y,z,x);
	}
	
	if(type==3)
	{	x=0.9;
	y=0.015;
	z=0.015;
	glScaled(y,z,x);
	}

	

	int slices=12;
	int stacks=1;

	glPushMatrix();
	glBegin(GL_POLYGON);
	for (int i = 0; i < slices; i++) {
		glNormal3f(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)),  0);
		glVertex3d(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), 0);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	for (int i = 0; i <= slices; i++) {
		glNormal3f(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)),  stacks);
		glVertex3d(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), stacks);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	for (int i = 0; i < slices;) {
		glBegin(GL_QUADS);

		glNormal3f(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)),  stacks);
		glVertex3d(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), stacks);
		glNormal3f(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)),  0);
		glVertex3d(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), 0);

		i++;

		glNormal3f(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)),  0);
		glVertex3d(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), 0);
		glNormal3f(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)),  stacks);
		glVertex3d(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), stacks);
		glEnd();
	}
	glPopMatrix();
}