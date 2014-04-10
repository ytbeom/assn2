#ifndef lion_H
#define lion_H

#include <iostream>
#include <windows.h>
#include <gl/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include <gl/freeglut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <math.h>

#define PI 3.1415926535
#define g 9.80665

class Lion{
public:
	float x;
	float y;
	float size;
	int c_state;
	int state;
	float velocity;

	Lion(){ x = 0; y = 0; size = 1; state = 0; c_state = 0;}
	void drawLeg();
	void drawLion();
	void drawDeath(Lion my_lion);
	void drawClear(Lion my_lion);
	int IsCollisionPot(float x, float y, float radius);
	int IsCollisionLoop(float x, float y, float radius);
};

#endif