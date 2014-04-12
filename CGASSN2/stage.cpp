#include "stage.h"




Background::Background(){
	season = 1;
	// ��� ������ ��ġ �ʱ�ȭ
	for (int i = 0; i < mapsize/10; i++) {
		int x = rand()%((int)mapsize+200)-100;
		int y = rand()%100+10;
		BackgroundX.push_back(x);
		BackgroundY.push_back(y);
	}
}
void Background::init(float _mapsize, float _bottom, int _season){
	mapsize = _mapsize;
	bottom = _bottom;
	season = _season;

}
void Background::draw(int BackgroundChange){
	//�ϴ� ����?
	glColor3f(0.529,0.807,0.980);
	glRectf(-mapsize,10,mapsize+200,100);
	
	// ���� ȭ�� �ٴ��� ��ȫ������ ��ĥ
	glColor3f(1.0,0.5,0.5);
	glRectf(-mapsize,0,mapsize+200,bottom-10);

	// ���� �׸���
	if (BackgroundChange < 9) {
		for (unsigned int i = 0; i < BackgroundX.size(); i++) {
			glColor3f(1.0,0.4,0.4);
			glBegin(GL_POLYGON);
			glVertex2f(BackgroundX[i], BackgroundY[i]);
			glVertex2f(BackgroundX[i]+1, BackgroundY[i]);
			glVertex2f(BackgroundX[i]+1, BackgroundY[i]+1);
			glVertex2f(BackgroundX[i], BackgroundY[i]+1);
			glEnd();
		}
	}
	else { // ���� ��ġ update
		BackgroundX.clear();
		BackgroundY.clear();
		for (int i = 0; i < mapsize/10; i++) {
			int x = rand()%((int)mapsize+200)-100;
			int y = rand()%100+10;
			BackgroundX.push_back(x);
			BackgroundY.push_back(y);
		}
		for (unsigned int i = 0; i < BackgroundX.size(); i++) {
			glColor3f(1.0,0.4,0.4);
			glBegin(GL_POLYGON);
			glVertex2f(BackgroundX[i], BackgroundY[i]);
			glVertex2f(BackgroundX[i]+1, BackgroundY[i]);
			glVertex2f(BackgroundX[i]+1, BackgroundY[i]+1);
			glVertex2f(BackgroundX[i], BackgroundY[i]+1);
			glEnd();
		}
	}

	// ���� ��ġ�� ����� ��� ǥ��
	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-10, 6);
	glVertex2f(-10, 46);
	glVertex2f(-10+20, 36);
	glVertex2f(-10, 30);
	glEnd();

	// ������ ��ġ�� ����� ��� ǥ��
	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	glVertex2f(mapsize, 6);
	glVertex2f(mapsize, 46);
	glVertex2f(mapsize+20, 36);
	glVertex2f(mapsize, 30);
	glEnd();
}