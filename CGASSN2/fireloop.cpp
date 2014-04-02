#include "fireloop.h"
#include "lion.h"

float top = 100.0;
extern float mapsize;
extern int NumofLoop;
float RadiusofLoop = 30.0;
float WidthofLoop = 8.0;
extern Lion my_lion;

void display_fireloop_front(vector<int> LoopList) {
	// 고리의 앞부분을 그리는 부분, 사자보다 먼저 그려져야 함
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
	// 고리의 뒷부분을 그리는 부분, 사자보다 나중에 그려져야 함
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