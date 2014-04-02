#include "lion.h"

extern float WidthofLoop;
extern float mapsize;

int Lion::IsCollisionPot(float _x, float _y, float _radius){
	if(_x-_radius < x+0.2*size && _x+_radius > x-0.8*size){
		if(y-0.7*size < _y)
			return true;
	}
	return false;
}

int Lion::IsCollisionLoop(float _x, float _y, float _radius){
	if(_x < x+0.3*size && x-0.7*size < _x){
		if(!(y-0.7*size>_y-_radius&&y+0.5*size<_y+_radius))
			return true;
	}
	return false;
}

void Lion::drawDeath(Lion my_lion){
	glClear(GL_COLOR_BUFFER_BIT);

	void *font = GLUT_BITMAP_TIMES_ROMAN_24;
	char string[] ="GAME OVER";
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(my_lion.x,50);
	int len = 9;
	for(int i=0;i<len;i++)
		glutBitmapCharacter(font,string[i]);
}

void Lion::drawClear(Lion my_lion){
	glClear(GL_COLOR_BUFFER_BIT);

	void *font = GLUT_BITMAP_TIMES_ROMAN_24;
	char string[] ="GAME CLEAR";
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(my_lion.x+15,50);
	int len = 10;
	for(int i=0;i<len;i++)
		glutBitmapCharacter(font,string[i]);
}

void Lion::drawLeg(){
	//front leg

if(state==0){
glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
	glVertex3f(x, y-0.3*size,0.0);
	glVertex3f( x+0.01*size, y-0.67*size,0.0);
	glVertex3f( x, y-0.7*size,0.0);
	glVertex3f( x-0.1*size, y-0.7*size,0.0);
	glVertex3f( x-0.11*size, y-0.67*size,0.0);
	glVertex3f( x-0.1*size, y-0.3*size,0.0);
glEnd();
glBegin(GL_POLYGON);
	glVertex3f( x-0.15*size, y-0.3*size,0.0);
	glVertex3f( x-0.14*size, y-0.67*size,0.0);
	glVertex3f( x-0.15*size, y-0.7*size,0.0);
	glVertex3f( x-0.25*size, y-0.7*size,0.0);
	glVertex3f( x-0.26*size, y-0.67*size,0.0);
	glVertex3f( x-0.25*size, y-0.3*size,0.0);
glEnd();
//back leg

glBegin(GL_POLYGON);
	glVertex3f( x-0.75*size, y-0.3*size,0.0);
	glVertex3f( x-0.74*size, y-0.67*size,0.0);
	glVertex3f( x-0.75*size, y-0.7*size,0.0);
	glVertex3f( x-0.85*size, y-0.7*size,0.0);
	glVertex3f( x-0.86*size, y-0.67*size,0.0);
	glVertex3f( x-0.85*size, y-0.3*size,0.0);
glEnd();

glBegin(GL_POLYGON);
	glVertex3f( x-0.9*size, y-0.2*size,0.0);
	glVertex3f( x-0.89*size, y-0.67*size,0.0);
	glVertex3f( x-0.9*size, y-0.7*size,0.0);
	glVertex3f( x-1.0*size, y-0.7*size,0.0);
	glVertex3f( x-1.01*size, y-0.67*size,0.0);
	glVertex3f( x-1.0*size, y-0.2*size,0.0);
glEnd();
}
else if(state==1){
	glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
	glVertex3f(x, y-0.2*size,0.0);
	glVertex3f( x+0.39*size, y-0.39*size,0.0);
	glVertex3f( x+0.39*size, y-0.41*size,0.0);
	glVertex3f( x+0.34*size, y-0.49*size,0.0);
	glVertex3f( x+0.32*size, y-0.495*size,0.0);
	glVertex3f( x-0.1*size, y-0.3*size,0.0);
glEnd();
glBegin(GL_POLYGON);
	glVertex3f( x-0.15*size, y-0.3*size,0.0);
	glVertex3f( x+0.29*size, y-0.54*size,0.0);
	glVertex3f( x+0.29*size, y-0.56*size,0.0);
	glVertex3f( x+0.21*size, y-0.64*size,0.0);
	glVertex3f( x+0.19*size, y-0.645*size,0.0);
	glVertex3f( x-0.25*size, y-0.35*size,0.0);
glEnd();
//back leg

glBegin(GL_POLYGON);
	glVertex3f( x-0.65*size, y-0.3*size,0.0);
	glVertex3f( x-0.99*size, y-0.64*size,0.0);
	glVertex3f( x-1.01*size, y-0.64*size,0.0);
	glVertex3f( x-1.09*size, y-0.61*size,0.0);
	glVertex3f( x-1.09*size, y-0.59*size,0.0);
	glVertex3f( x-0.85*size, y-0.3*size,0.0);
glEnd();

glBegin(GL_POLYGON);
	glVertex3f( x-0.8*size, y-0.2*size,0.0);
	glVertex3f( x-1.12*size, y-0.54*size,0.0);
	glVertex3f( x-1.13*size, y-0.54*size,0.0);
	glVertex3f( x-1.22*size, y-0.51*size,0.0);
	glVertex3f( x-1.22*size, y-0.49*size,0.0);
	glVertex3f( x-1.0*size, y-0.2*size,0.0);
glEnd();

}
else if(state==2){
	glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
	glVertex3f(x, y-0.3*size,0.0);
	glVertex3f( x-0.07*size, y-0.65*size,0.0);
	glVertex3f( x-0.08*size, y-0.68*size,0.0);
	glVertex3f( x-0.18*size, y-0.68*size,0.0);
	glVertex3f( x-0.19*size, y-0.65*size,0.0);
	glVertex3f( x-0.1*size, y-0.3*size,0.0);
glEnd();
glBegin(GL_POLYGON);
	glVertex3f( x-0.15*size, y-0.3*size,0.0);
	glVertex3f( x-0.22*size, y-0.65*size,0.0);
	glVertex3f( x-0.23*size, y-0.68*size,0.0);
	glVertex3f( x-0.33*size, y-0.68*size,0.0);
	glVertex3f( x-0.34*size, y-0.65*size,0.0);
	glVertex3f( x-0.25*size, y-0.3*size,0.0);
glEnd();
//back leg

glBegin(GL_POLYGON);
	glVertex3f( x-0.75*size, y-0.3*size,0.0);
	glVertex3f( x-0.64*size, y-0.65*size,0.0);
	glVertex3f( x-0.65*size, y-0.68*size,0.0);
	glVertex3f( x-0.75*size, y-0.68*size,0.0);
	glVertex3f( x-0.76*size, y-0.65*size,0.0);
	glVertex3f( x-0.85*size, y-0.3*size,0.0);
glEnd();

glBegin(GL_POLYGON);
	glVertex3f( x-0.9*size, y-0.2*size,0.0);
	glVertex3f( x-0.79*size, y-0.65*size,0.0);
	glVertex3f( x-0.80*size, y-0.68*size,0.0);
	glVertex3f( x-0.90*size, y-0.68*size,0.0);
	glVertex3f( x-0.91*size, y-0.65*size,0.0);
	glVertex3f( x-1.0*size, y-0.2*size,0.0);
glEnd();
}
}

void Lion::drawLion(){

int i;
// lion BODY start //

//torso

glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
	glVertex3f( x, y,0.0);
	glVertex3f( x-0.8*size, y,0.0);
	glVertex3f( x-0.95*size, y-0.07*size,0.0);
	glVertex3f( x-1.0*size, y-0.15*size,0.0);
	glVertex3f( x-1.0*size, y-0.23*size,0.0);
	glVertex3f( x-0.95*size, y-0.35*size,0.0);
	glVertex3f( x-0.5*size, y-0.37*size,0.0);
	glVertex3f( x, y-0.35*size,0.0);
glEnd();
//tail
glBegin(GL_POLYGON);
	glVertex3f( x-0.93*size, y-0.09*size,0.0);
	glVertex3f( x-1.2*size, y+0.3*size,0.0);
	glVertex3f( x-1.23*size, y+0.3*size,0.0);
	glVertex3f( x-0.95*size, y-0.09*size,0.0);
glEnd();
glColor3f(1.0,0.5,0.0);
glBegin(GL_POLYGON);
for(i=0;i<36;i++){

	float x1 =  x-1.19*size+(float)cos(i*PI/18)*0.025*size;
	float y1 =  y+0.3*size+(float)sin(i*PI/18)*0.025*size;
	glVertex3f(x1,y1,0.0);
}
glEnd();
glBegin(GL_POLYGON);
for(i=0;i<36;i++){

	float x1 =  x-1.22*size+(float)cos(i*PI/18)*0.025*size;
	float y1 =  y+0.3*size+(float)sin(i*PI/18)*0.025*size;
	glVertex3f(x1,y1,0.0);
}
glEnd();
glBegin(GL_POLYGON);
for(i=0;i<36;i++){

	float x1 =  x-1.21*size+(float)cos(i*PI/18)*0.025*size;
	float y1 =  y+0.33*size+(float)sin(i*PI/18)*0.025*size;
	glVertex3f(x1,y1,0.0);
}
glEnd();


// lion BODY end   //

// lion HEAD start //


//gal gi botton
glColor3f(1.0,0.5,0.0);
glBegin(GL_POLYGON);
for(i=0;i<60;i++){

	float x1 =  x-0.01*size+(float)cos(i*PI/30)*0.15*size;
	float y1 =  y-0.35*size+(float)sin(i*PI/30)*0.15*size;
	glVertex3f(x1,y1,0.0);
}
glEnd();
//gal gi top
glColor3f(1.0,0.5,0.0);
glBegin(GL_POLYGON);
for(i=0;i<60;i++){

	float x1 =  x-0.01*size+(float)cos(i*PI/30)*0.15*size;
	float y1 =  y+0.35*size+(float)sin(i*PI/30)*0.15*size;
	glVertex3f(x1,y1,0.0);
}
glEnd();
//gal gi left
glColor3f(1.0,0.5,0.0);
glBegin(GL_POLYGON);
for(i=0;i<60;i++){

	float x1 =  x-0.3*size+(float)cos(i*PI/30)*0.15*size;
	float y1 =  y+(float)sin(i*PI/30)*0.15*size;
	glVertex3f(x1,y1,0.0);
}
glEnd();
//gal gi right
glColor3f(1.0,0.5,0.0);
glBegin(GL_POLYGON);
for(i=0;i<60;i++){

	float x1 =  x+0.27*size+(float)cos(i*PI/30)*0.15*size;
	float y1 =  y+(float)sin(i*PI/30)*0.15*size;
	glVertex3f(x1,y1,0.0);
}
glEnd();
////
glBegin(GL_POLYGON);
for(i=0;i<60;i++){

	float x1 =  x+0.197*size+(float)cos(i*PI/30)*0.15*size;
	float y1 =  y+0.23*size+(float)sin(i*PI/30)*0.15*size;
	glVertex3f(x1,y1,0.0);
}
glEnd();
glBegin(GL_POLYGON);
for(i=0;i<60;i++){

	float x1 =  x+0.197*size+(float)cos(i*PI/30)*0.15*size;
	float y1 =  y-0.23*size+(float)sin(i*PI/30)*0.15*size;
	glVertex3f(x1,y1,0.0);
}
glEnd();
glBegin(GL_POLYGON);
for(i=0;i<60;i++){

	float x1 =  x-0.23*size+(float)cos(i*PI/30)*0.15*size;
	float y1 =  y+0.23*size+(float)sin(i*PI/30)*0.15*size;
	glVertex3f(x1,y1,0.0);
}
glEnd();
glBegin(GL_POLYGON);
for(i=0;i<60;i++){

	float x1 =  x-0.23*size+(float)cos(i*PI/30)*0.15*size;
	float y1 =  y-0.23*size+(float)sin(i*PI/30)*0.15*size;
	glVertex3f(x1,y1,0.0);
}
glEnd();

//face
glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
for(i=0;i<60;i++){

	float x1 =  x+(float)cos(i*PI/30)*0.225*size;
	float y1 =  y+(float)sin(i*PI/30)*0.3*size;
	glVertex3f(x1,y1,0.0);

}
glEnd();
//left eye
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
for(i=0;i<36;i++){

	float x1 =  x-0.09*size+(float)cos(i*PI/18)*0.025*size;
	float y1 =  y+0.05*size+(float)sin(i*PI/18)*0.025*size;
	glVertex3f(x1,y1,0.0);
}
glEnd();
//right eye
glBegin(GL_POLYGON);
for(i=0;i<36;i++){

	float x1 =  x+0.15*size+(float)cos(i*PI/18)*0.025*size;
	float y1 =  y+0.05*size+(float)sin(i*PI/18)*0.025*size;
	glVertex3f(x1,y1,0.0);
}
glEnd();
//mouth
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
for(i=0;i<36;i++){

	float x1 =  x+0.075*size+(float)cos(i*PI/18)*0.065*size;
	float y1 =  y-0.085*size+(float)sin(i*PI/18)*0.07*size;
	glVertex3f(x1,y1,0.0);
}
glEnd();
glBegin(GL_POLYGON);
for(i=0;i<36;i++){

	float x1 =  x-0.005*size+(float)cos(i*PI/18)*0.065*size;
	float y1 =  y-0.085*size+(float)sin(i*PI/18)*0.07*size;
	glVertex3f(x1,y1,0.0);
}
glEnd();
//nose
glColor3f(1.0,0.5,0.0);
glBegin(GL_POLYGON);
for(i=0;i<36;i++){

	float x1 =  x+0.05*size+(float)cos(i*PI/18)*0.025*size;
	float y1 =  y-0.05*size+(float)sin(i*PI/18)*0.025*size;
	glVertex3f(x1,y1,0.0);
}
glEnd();
// lion HEAD end //
}