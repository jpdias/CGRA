#include "MyClock.h"
#define pi acos(-1.0)

MyClock::MyClock() {
	slices=12;
	angmin=180.0;
	anghour=90.0;
	angsec=270.0;
}

void MyClock::drawClock()
{
	glPushMatrix();
	glBegin(GL_POLYGON);
	for (int i = 0; i < slices; i++) {
		glTexCoord2f((cos(i * (2 * pi / (double) slices))+1)/2,
			(sin(i * (2 * pi / (double) slices))+1)/2);
		glNormal3f(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), 0);
		glTexCoord2f((cos(i * (2 * pi / (double) slices))+1)/2,
			(sin(i * (2 * pi / (double) slices))+1)/2);
		glVertex3d(cos(i * (2 * pi / (double) slices)),
			sin(i * (2 * pi / (double) slices)), 0);
	}
	glEnd();
	glPopMatrix();
}

void MyClock::update(bool stat)
{
	if(stat){


	angmin+=((320/60)*0.0611)/60;
		 
	anghour+=(((320/60)*0.0611)/60)/60;
	
	angsec+=(320/60)*0.0611;
		}
	else {}
}
