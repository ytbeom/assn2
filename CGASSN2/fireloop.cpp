#include "fireloop.h"
#include "lion.h"

Fireloop::Fireloop(int jumplength){
	top = 100.0;
	RadiusofLoop = 30.0;
	WidthofLoop = 8.0;
	// 불고리 개수/위치 설정 (게임 map 밖에 있어도 됨)
	NumofLoop = rand()%1000+500; // 500에서 1000개 사이의 Loop 생성

}

void Fireloop::init(int _jumplength, float _mapsize, int stage){
	jumplength = _jumplength;
	LoopList.clear();
	NumofLoop = rand()%1000+500;// 0~2*jumplength 사이의 위치에 첫 Loop 생성
//	printf("num of loop : %d",NumofLoop);
	LoopList.push_back(rand()%(2*jumplength+1)+jumplength);
	for (int i=0; i<NumofLoop-1; i++) {
		// 앞 고리와 jumplength~3*jumplength 의 간격을 갖는 고리를 생성
		LoopList.push_back(LoopList[i]+((rand()%(7-stage))*jumplength));
	}
	mapsize = _mapsize;
}

void Fireloop::display_fireloop_front(int toggle) {
	// 고리의 앞부분을 그리는 부분, 사자보다 먼저 그려져야 함
	
	for (int i = 0; i < NumofLoop; i++) {
		if (LoopList[i] < mapsize+200) {
			glColor3f(1.0, 0.0, 0.0);
			glLineWidth(25);
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

void Fireloop::display_fireloop_back(int toggle) {
	// 고리의 뒷부분을 그리는 부분, 사자보다 나중에 그려져야 함
	
	for (int i = 0; i < NumofLoop; i++) {
		if (LoopList[i] < mapsize+200) {
			glColor3f(1.0, 0.0, 0.0);
			glLineWidth(25);
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