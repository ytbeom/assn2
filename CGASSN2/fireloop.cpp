#include "fireloop.h"
#include "lion.h"

float top = 100.0;
extern float mapsize;
extern int NumofLoop;
float RadiusofLoop = 30.0;
float WidthofLoop = 8.0;
extern Lion my_lion;

void display_fireloop_front(vector<int> LoopList, int toggle) {
	// 고리의 앞부분을 그리는 부분, 사자보다 먼저 그려져야 함
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(25);
	for (int i = 0; i < NumofLoop; i++) {
		if (LoopList[i] < mapsize+200) {
			
			glBegin(GL_LINE_STRIP);
			for (float angle = (-1.0/2.0)*PI; angle > (-3.0/2.0)*PI; angle -= 0.1) {
				float x = LoopList[i] + WidthofLoop * cos(angle);
				float y = top - RadiusofLoop + RadiusofLoop * sin(angle);
				x += ((rand()%10)-5)/3;
				y += ((rand()%10)-5)/4;
				glVertex2f(x, y);
				}
			glEnd();
			glColor3f(1.0, 0.7, 0.0);
			glLineWidth(5);
			glBegin(GL_LINE_STRIP);
			for (float angle = (-1.0/2.0)*PI; angle > (-3.0/2.0)*PI; angle -= 0.1) {
				float x = LoopList[i] + WidthofLoop * cos(angle);
				float y = top - RadiusofLoop + RadiusofLoop * sin(angle);
				x += ((rand()%10)-5)/4;
				glVertex2f(x, y);
				}
			glEnd();
			glColor3f(1.0, 0.5, 0.0);
			glLineWidth(5);
			glBegin(GL_LINE_STRIP);
			for (float angle = (-1.0/2.0)*PI; angle > (-3.0/2.0)*PI; angle -= 0.1) {
				float x = LoopList[i] + WidthofLoop * cos(angle);
				float y = top - RadiusofLoop + RadiusofLoop * sin(angle);
				x += ((rand()%10)-5)/3;
				y += ((rand()%10)-5)/4;
				glVertex2f(x, y);
				}
			glEnd();
		}
			

	}
}

void display_fireloop_back(vector<int> LoopList, int toggle) {
	// 고리의 뒷부분을 그리는 부분, 사자보다 나중에 그려져야 함
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(25);
	for (int i = 0; i < NumofLoop; i++) {
		if (LoopList[i] < mapsize+200) {
			glBegin(GL_LINE_STRIP);
			for (float angle = (-1.0/2.0)*PI; angle < (1.0/2.0)*PI; angle += 0.1) {
				float x = LoopList[i] + WidthofLoop * cos(angle);
				float y = top - RadiusofLoop + RadiusofLoop * sin(angle);
				x += ((rand()%10)-5)/3;
				y += ((rand()%10)-5)/4;
				glVertex2f(x, y);
			}
			glEnd();
			glColor3f(1.0, 0.7, 0.0);
			glLineWidth(5);
			glBegin(GL_LINE_STRIP);
			for (float angle = (-1.0/2.0)*PI; angle < (1.0/2.0)*PI; angle += 0.1) {
				float x = LoopList[i] + WidthofLoop * cos(angle);
				float y = top - RadiusofLoop + RadiusofLoop * sin(angle);
				x += ((rand()%10)-5)/4;
				glVertex2f(x, y);
			}
			glEnd();
			glColor3f(1.0, 0.5, 0.0);
			glLineWidth(5);
			glBegin(GL_LINE_STRIP);
			for (float angle = (-1.0/2.0)*PI; angle < (1.0/2.0)*PI; angle += 0.1) {
				float x = LoopList[i] + WidthofLoop * cos(angle);
				float y = top - RadiusofLoop + RadiusofLoop * sin(angle);
				x += ((rand()%10)-5)/3;
				y += ((rand()%10)-5)/4;
				glVertex2f(x, y);
			}
			glEnd();
		}
	}
}