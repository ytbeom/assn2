#include "fireloop.h"
#include "lion.h"

Fireloop::Fireloop(int jumplength){
	top = 100.0;
	RadiusofLoop = 30.0;
	WidthofLoop = 8.0;
	// �Ұ� ����/��ġ ���� (���� map �ۿ� �־ ��)
	NumofLoop = rand()%1000+500; // 500���� 1000�� ������ Loop ����

}

void Fireloop::init(int _jumplength, float _mapsize, int stage){
	jumplength = _jumplength;
	LoopList.clear();
	NumofLoop = rand()%1000+500;// 0~2*jumplength ������ ��ġ�� ù Loop ����
//	printf("num of loop : %d",NumofLoop);
	LoopList.push_back(rand()%(2*jumplength+1)+jumplength);
	for (int i=0; i<NumofLoop-1; i++) {
		// �� ���� jumplength~3*jumplength �� ������ ���� ���� ����
		LoopList.push_back(LoopList[i]+((rand()%(7-stage))*jumplength));
	}
	mapsize = _mapsize;
}

void Fireloop::display_fireloop_front(int toggle) {
	// ���� �պκ��� �׸��� �κ�, ���ں��� ���� �׷����� ��
	
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
	// ���� �޺κ��� �׸��� �κ�, ���ں��� ���߿� �׷����� ��
	
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