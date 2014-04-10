#include <windows.h>
#include <math.h>
#include <vector>
#include <GL/glut.h>
#include "main.h"

#ifndef FIRELOOP_H
#define FIRELOOP_H

using namespace std;

void display_fireloop_front(vector<int> LoopList);
void display_fireloop_back(vector<int> LoopList);
void update_fireloop(vector<int> LoopList);

#endif FIRELOOP_H