#include "fireloop.h"
#include "lion.h"

float top = 100.0;
extern float mapsize;
extern int NumofLoop;
float RadiusofLoop = 30.0;
float WidthofLoop = 8.0;
extern Lion my_lion;

void display_fireloop_front(vector<int> LoopList) {
	// ���� �պκ��� �׸��� �κ�, ���ں��� ���� �׷����� ��
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(10);
	for (int i = 0; i < NumofLoop; i++) {
		if (LoopList[i] < mapsize+200) {
			glBegin(GL_LINE_STRIP);
			for (float angle = (-1.0/2.0)*PI; angle > (-3.0/2.0)*PI; angle -= 0.1) {
				float x = LoopList[i] + WidthofLoop * cos(angle);
				float y = top - RadiusofLoop + RadiusofLoop * sin(angle);
				glVertex2f(x, y);
			}
		}
		glEnd();
	}
}

void display_fireloop_back(vector<int> LoopList) {
	// ���� �޺κ��� �׸��� �κ�, ���ں��� ���߿� �׷����� ��
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(10);
	for (int i = 0; i < NumofLoop; i++) {
		if (LoopList[i] < mapsize+200) {
			glBegin(GL_LINE_STRIP);
			for (float angle = (-1.0/2.0)*PI; angle < (1.0/2.0)*PI; angle += 0.1) {
				float x = LoopList[i] + WidthofLoop * cos(angle);
				float y = top - RadiusofLoop + RadiusofLoop * sin(angle);
				glVertex2f(x, y);
			}
			glEnd();
		}
	}
}