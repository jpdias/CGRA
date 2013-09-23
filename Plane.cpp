#include "Plane.h"
#include "ExampleObject.h"
#include <GL/GLU.h>


Plane::Plane(void)
{
	_numDivisions = 1;
}

Plane::Plane(int n)
{
	_numDivisions = n;
}


Plane::~Plane(void)
{
}

void Plane::draw(float racio)
{
	glPushMatrix();
	glRotatef(180.0,1,0,0);
	glTranslatef(-0.5,0.0,-0.5);
	glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
	glNormal3f(0,-1,0);

	for (float bx = 0; bx<_numDivisions; bx++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2d(bx,0);
		glVertex3f(bx, 0, 0);

		for (float bz = 0; bz<_numDivisions; bz++)
		{
			glTexCoord2d(((bx+1)/_numDivisions),(bz/_numDivisions)*racio);
			glVertex3f(bx + 1, 0, bz);
			glTexCoord2d(((bx)/_numDivisions),((bz+1)/_numDivisions)*racio);
			glVertex3f(bx, 0, bz + 1);
		}
		glTexCoord2d(((bx+1)/_numDivisions),1);
		glVertex3d(bx+ 1, 0, _numDivisions);
		glEnd();
	}
	glPopMatrix();

}

void Plane::draw()
{
	glPushMatrix();
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	glTranslatef(0.5,0.5,0.0);
	glRotatef(0,0.0,0.0,1.0);
	glTranslatef(-0.5,-0.5,0.0);
	glMatrixMode(GL_MODELVIEW);
	glRotatef(180.0,1,0,0);
	glTranslatef(-0.5,0.0,-0.5);
	glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
	glNormal3f(0,-1,0);

	for (float bx = 0; bx<_numDivisions; bx++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2d(bx,0);
		glVertex3f(bx, 0, 0);

		for (float bz = 0; bz<_numDivisions; bz++)
		{
			glTexCoord2d(((bx+1)/_numDivisions),(bz/_numDivisions));
			glVertex3f(bx + 1, 0, bz);
			glTexCoord2d(((bx)/_numDivisions),((bz+1)/_numDivisions));
			glVertex3f(bx, 0, bz + 1);
		}
		glTexCoord2d(((bx+1)/_numDivisions),1);
		glVertex3d(bx+ 1, 0, _numDivisions);
		glEnd();
	}
	glPopMatrix();

}


void Plane::drawsq()
{
	float var =0.001;
	glPushMatrix();
	
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	glTranslatef(0.5,0.5,0.0);
	glRotatef(0,0.0,0.0,1.0);
	glScalef(0.95,0.95,0.0);
	glTranslatef(-0.5,-0.5,0.0);
	glMatrixMode(GL_MODELVIEW);
	glNormal3f(0,0,1);
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0.0-1.0,0.0-1.0);
	glVertex3f(0,0,0);
	glTexCoord2f(1.0/3.0*3-1.0,1.0/3.0*3.0-1.0);
	glVertex3f(1.0/3.0+var,1.0/3.0+var,0);
	glTexCoord2f(0.0-1.0,1.0*3.0-1.0);
	glVertex3f(0,1,0);
	glTexCoord2f(1.0/3.0*3.0-1,2.0/3.0*3.0-1);
	glVertex3f(1.0/3.0+var,2.0/3.0-var,0);
	glTexCoord2f(1*3.0-1.0,1*3.0-1.0);
	glVertex3f(1,1,0);
	glTexCoord2f(2.0/3.0*3.0-1,2.0/3.0*3.0-1);
	glVertex3f(2.0/3.0-var,2.0/3.0-var,0);
	glTexCoord2d(1.0*3.0-1.0,0.0-1.0);
	glVertex3f(1,0,0);
	glTexCoord2f(2.0/3.0*3.0-1.0,1.0/3.0*3.0-1.0);
	glVertex3f(2.0/3.0-var,1.0/3.0+var,0);
	glTexCoord2f(0.0-1.0,0.0-1.0);
	glVertex3f(0,0,0);
	glTexCoord2f(1.0/3.0*3.0-1.0,1.0/3.0*3.0-1.0);
	glVertex3f(1.0/3.0+var,1.0/3.0+var,0);
	
	glEnd();
	
	glPopMatrix();
	
}

void Plane::drawbliss()
{

	glPushMatrix();
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	glTranslatef(0.5,0.5,0.0);
	glRotatef(0,0.0,0.0,1.0);
	glRotatef(-90.0,0.0,0.0,1.0);
	glTranslatef(-0.5,-0.5,0.0);
	glMatrixMode(GL_MODELVIEW);
	glRotatef(180.0,1,0,0);
	glTranslatef(-0.5,0.0,-0.5);
	glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
	glNormal3f(0,-1,0);

	for (float bx = 0; bx<_numDivisions; bx++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2d(bx,0);
		glVertex3f(bx, 0, 0);

		for (float bz = 0; bz<_numDivisions; bz++)
		{
			glTexCoord2d(((bx+1)/_numDivisions),(bz/_numDivisions));
			glVertex3f(bx + 1, 0, bz);
			glTexCoord2d(((bx)/_numDivisions),((bz+1)/_numDivisions));
			glVertex3f(bx, 0, bz + 1);
		}
		glTexCoord2d(((bx+1)/_numDivisions),1);
		glVertex3d(bx+ 1, 0, _numDivisions);
		glEnd();
	}
	glPopMatrix();


}


void Plane::drawfloor()
{

	int _numDivisions2=12;
	glPushMatrix();

	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	glTranslatef(0.5,0.5,0.0);
	glRotatef(-90,0.0,0.0,1.0);
	glTranslatef(-0.5,-0.5,0.0);
	glMatrixMode(GL_MODELVIEW);

	glRotatef(180.0,1,0,0);
	glTranslatef(-0.5,0.0,-0.5);
	glScalef(1.0/(double) _numDivisions2, 1 ,1.0/(double) _numDivisions2);
	glNormal3f(0,-1,0);
	float racio=512.0/372.0;

	for (int bx = 0; bx<12; bx++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2f((bx*1.0)-6,0);
		glVertex3f(bx, 0, 0);
		for (int bz = 0; bz<_numDivisions2; bz++)
		{
			glTexCoord2f((((bx+1)*1.0)-6),((bz*1.0)-6)*racio);
			glVertex3f(bx + 1, 0, bz);
			glTexCoord2f(((bx*1.0)-6),(((bz+1)*1.0)-6)*racio);
			glVertex3f(bx,0, bz + 1);
		}
		glTexCoord2f((((bx + 1)*1.0)-6),1*racio);
		glVertex3d(bx + 1, 0, _numDivisions2);

		glEnd();
	}

	glPopMatrix();

}