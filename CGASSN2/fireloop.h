#include <windows.h>
#include <math.h>
#include <vector>
#include <GL/glut.h>
#include "main.h"

#ifndef FIRELOOP_H
#define FIRELOOP_H

using namespace std;

class Fireloop{
public:
	vector<int> LoopList;
	vector<int>::iterator pointer;
	int NumofLoop;
	int jumplength;
	float mapsize;
	float top;
	float RadiusofLoop;
	float WidthofLoop;

	Fireloop(int jumplength);
	void init(int jumplentgh, float mapsize, int stage);
	void display_fireloop_front(int toggle);
	void display_fireloop_back(int toggle);
	//void update_fireloop(vector<int> LoopList);
};
#endif FIRELOOP_H