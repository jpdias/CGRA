#include "MyRobot.h"
#include "CGFobject.h"
#include <vector>

MyRobot::MyRobot(){
	x=10;
	z=10;
	ang=210;

	const float pi = acos(-1.0);

	int slices=12;
	stacks=5;

	float xz=0.5;

	for(int i=0;i<12;i++){

		if(i<4){
			xz=0.5;
		}
		else if(i<7){
			xz-=1/3.0;
		}
		else if(i<10){
			xz=-0.5;
		}
		else if(i<12)
		{xz+=1/3.0;
		}
		squarex.push_back(xz);
		//printf(" %f",squarex[i]) ;
	}

	//printf("\n end");
	float zz=0.5;
	for(int i=0;i<12;i++){
		if(i==0)
			zz=0.5f;
		else if(i>0 && i<4){
			zz-=1/3.0;
		}
		else if(i>0 &&i<7){
			zz=-0.5;
		}
		else if(i>0 &&i<10){
			zz+=1/3.0;
		}
		else if(i>0 &&i<12)
			zz=0.5;
		squarez.push_back(zz);
		//	printf(" %f",squarez[i]) ;
	}

	float angle = (2*pi)/(float)12, angleFinal = 2*(2*pi)/(float)12;

	float xi,yi;

	for(int i=0;i<14;i++)
	{

		xi = cos(angleFinal);
		yi = sin(angleFinal);
		circlex.push_back(yi/4);
		circlez.push_back(xi/4);
		angleFinal += angle;
		
	}
}

void MyRobot::draw(){

	const float pi = acos(-1.0);

	int slices=12;
	stacks=5;

	glPushMatrix();
	glBegin(GL_POLYGON);
	for (int i = 0; i < slices; i++) {
		glTexCoord2f(circlex[i]+0.5,0.5- circlez[i]);
		glNormal3f(0.0,1.1,0.0);
		glVertex3d(circlex[i], 1,circlez[i]);
	}


	glEnd();
	glPopMatrix();



	for(int i=0;i<12; i++){
		glPushMatrix();
		glBegin(GL_QUADS);

		if(i<11){

			glTexCoord2f(squarez[i]+0.5,0.5- squarex[i]);
			glVertex3f(squarez[i],0.01,squarex[i]);
			glTexCoord2f(circlez[i]+0.5,0.5- circlex[i]);
			glVertex3f(circlez[i],1.01,circlex[i]);
			glTexCoord2f(circlez[i+1]+0.5,0.5- circlex[i+1]);	
			glVertex3f(circlez[i+1],1.01,circlex[i+1]);	
			glTexCoord2f(squarez[i+1]+0.5,0.5- squarex[i+1]);
			glVertex3f(squarez[i+1],0.01,squarex[i+1]);

		}
		else
		{
			glTexCoord2f(squarez[i]+0.5,0.5- squarex[i]);
			glVertex3f(squarez[i],0.01,squarex[i]);
			glTexCoord2f(circlez[i]+0.5,0.5- circlex[i]);
			glVertex3f(circlez[i],1.01,circlex[i]);
			glTexCoord2f(circlez[0]+0.5,0.5- circlex[0]);
			glVertex3f(circlez[0],1.01,circlex[0]);
			glTexCoord2f(squarez[0]+0.5,0.5- squarex[0]);
			glVertex3f(squarez[0],0.01,squarex[0]);

		}

		glEnd();
		glPopMatrix();
	}


	glPushMatrix();
	//glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for(int i=0;i<squarex.size();i++){
		glTexCoord2f(squarez[i],squarex[i]);
		glVertex3f(squarez[i], 0.01f,squarex[i]);

	}

	glEnd();
	glPopMatrix();


}

void MyRobot::move(int x, int y)
{
	glPushMatrix();
	glTranslated(x/2,y/2,0);
	draw();
	glPopMatrix();
}

void MyRobot::move(float ang){
	glPushMatrix();
	glRotatef(ang*3.0,0.0,1.0,0.0);//*3 to rotate fast
	draw();
	glPopMatrix();
}