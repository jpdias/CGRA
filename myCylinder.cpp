#include "myCylinder.h"
#define pi acos(-1.0)

myCylinder::myCylinder(int slices, int stacks, bool smooth) {

	if(!smooth){
	glPushMatrix();
	glBegin(GL_POLYGON);
	for (int i = 0; i < slices; i++) {
		glNormal3f(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), 0);
		glVertex3d(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), 0);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	for (int i = 0; i <= slices; i++) {
		glNormal3f(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), 0);
		glVertex3d(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), stacks);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	for (int i = 0; i < slices;) {
		glBegin(GL_QUADS);

		glNormal3f(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), 0);
		glVertex3d(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), stacks);
		glNormal3f(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), 0);
		glVertex3d(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), 0);

		i++;

		glNormal3f(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), 0);
		glVertex3d(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), 0);
		glNormal3f(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), 0);
		glVertex3d(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), stacks);
		glEnd();
	}
	glPopMatrix();
	}


	else{

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
}
