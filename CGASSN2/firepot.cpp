#include "firepot.h"

Firepot::Firepot(int jumplength){
	PotList.push_back((rand()%2+1)*jumplength*2); 
	BottomofPot = 6.0;
	HeightofPot = 10.0;
	RadiusofPot = 10.0;
	HeightofFire = 15.0;
	RadiusofFire = 8.0;
	RadiusofShadow = 6.0;
	RadiusofBigFire = 18.0;
	TopofFire = 31.5;
	WidthofTriangle = 6.5;
}

void Firepot::init(int _jumplength, float mapsize, int stage){
	jumplength = _jumplength;
	// 불항아리 개수/위치 설정 (게임 map 안에 있게끔)
//	PotList.clear();
	for (int i=0; i<mapsize/jumplength; i++) {
		 // 앞 항아리와 1*jumplength~2*jumplength 의 간격을 갖는 항아리를 생성
		int position = PotList[i]+((rand()%(7-stage))*jumplength*2);
		if (position < mapsize)
			PotList.push_back(position);
		else
			break;
	}
	NumofPot = PotList.size();
}

void Firepot::display_firepot(int toggle) {
	// 항아리를 그리는 부분
	for (int i = 0; i < NumofPot; i++) {
		glColor3f(0.5, 0.5, 0.5);
		glBegin(GL_POLYGON);
		for (float angle = (-7.0/6.0)*PI; angle < (1.1/6.0)*PI; angle += 0.1) {
			float x = PotList[i] + RadiusofPot * cos(angle);
			float y = BottomofPot + HeightofPot + RadiusofPot * sin(angle);
			glVertex2f(x, y);
		}
		glEnd();

		// 불꽃을 그리는 부분

		glPushMatrix();
		if(toggle<5)
			glTranslatef(0.3,0,0);
		else
			glTranslatef(-0.3,0,0);

		
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		for (float angle = (5.0/4.0)*PI; angle > (3.0/4.0)*PI; angle -= 0.1) {
			float x = PotList[i] + RadiusofFire * cos(angle);
			float y = (BottomofPot + HeightofFire + RadiusofFire/sqrt(2.0)) + RadiusofFire * sin(angle);
			glVertex2f(x, y);
		}
		for (float angle = (0.9/4.0)*PI; angle >(-1.1/4.0)*PI; angle -= 0.1) {
			float x = PotList[i] + RadiusofFire * cos(angle);
			float y = (BottomofPot + HeightofFire + RadiusofFire/sqrt(2.0)) + RadiusofFire * sin(angle);
			glVertex2f(x, y);
		}
		glShadeModel(GL_FLAT);
		glEnd();
		
		
		glColor3f(0.0, 0.0, 0.0);
		glColor3f(0.529,0.807,0.980);
		glBegin(GL_POLYGON);
		for (float angle = (-6.8/6.0)*PI; angle < (0.9/6.0)*PI; angle += 0.1) {
			float x = PotList[i] + RadiusofShadow * cos(angle);
			float y = (BottomofPot + HeightofFire + RadiusofFire/sqrt(2.0) + 3.0) + RadiusofShadow * sin(angle);
			glVertex2f(x, y);
		}
		glShadeModel(GL_FLAT);
		glEnd();
		
		glPopMatrix();
		glPushMatrix();
		if(toggle<5)
			glTranslatef(0.7,0,0);
		else
			glTranslatef(-0.7,0,0);
		
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		
		glVertex2f(PotList[i], BottomofPot + TopofFire);

		glVertex2f(PotList[i], (BottomofPot + HeightofFire + RadiusofFire/sqrt(2.0) + 3.0) + RadiusofShadow * sin(-0.5*PI));
		glVertex2f(PotList[i]-WidthofTriangle, (BottomofPot + HeightofFire + RadiusofFire/sqrt(2.0) + 3.0) + RadiusofShadow * sin(-0.5*PI));
		glShadeModel(GL_FLAT);
		glEnd();
		
		
		glColor3f(0.0, 0.0, 0.0);
		glColor3f(0.529,0.807,0.980);
		glBegin(GL_POLYGON);
		for (float angle = (-1.0/4.0)*PI; angle < 0; angle += 0.1) {
			float x = PotList[i] - RadiusofBigFire + RadiusofBigFire * cos(angle);
			float y = BottomofPot + TopofFire + 1.5 + RadiusofBigFire * sin(angle);
			glVertex2f(x, y);
		}
		glShadeModel(GL_FLAT);
		glEnd();
		
		
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(PotList[i], BottomofPot + TopofFire);
		glVertex2f(PotList[i], (BottomofPot + HeightofFire + RadiusofFire/sqrt(2.0) + 3.0) + RadiusofShadow * sin(-0.5*PI));
		glVertex2f(PotList[i]+WidthofTriangle, (BottomofPot + HeightofFire + RadiusofFire/sqrt(2.0) + 3.0) + RadiusofShadow * sin(-0.5*PI));
		glShadeModel(GL_FLAT);
		glEnd();
		
		
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		for (float angle = (1.0/4.0)*PI; angle > 0; angle -= 0.1) {
			float x = (PotList[i] - RadiusofBigFire/sqrt(2.0)) + RadiusofBigFire * cos(angle);
			float y = (BottomofPot + TopofFire - RadiusofBigFire/sqrt(2.0)) +RadiusofBigFire * sin(angle);
			glVertex2f(x, y);
		}
		glShadeModel(GL_FLAT);
		glEnd();
		
		glPopMatrix();


		glPushMatrix();
		glTranslatef(0,10,0);
		glScalef(1,0.5,0);
		if(toggle<5)
			glTranslatef(0.5,0,0);
		else
			glTranslatef(-0.5,0,0);

		
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		for (float angle = (5.0/4.0)*PI; angle > (3.0/4.0)*PI; angle -= 0.1) {
			float x = PotList[i] + (RadiusofFire * cos(angle))/2.5;
			float y = (BottomofPot + HeightofFire + RadiusofFire/sqrt(2.0)) + RadiusofFire * sin(angle);
			glVertex2f(x, y);
		}
		for (float angle = (0.9/4.0)*PI; angle >(-1.1/4.0)*PI; angle -= 0.1) {
			float x = PotList[i] + (RadiusofFire * cos(angle))/2.5;
			float y = (BottomofPot + HeightofFire + RadiusofFire/sqrt(2.0)) + RadiusofFire * sin(angle);
			glVertex2f(x, y);
		}
		glShadeModel(GL_FLAT);
		glEnd();
		
		
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		for (float angle = (-6.8/6.0)*PI; angle < (0.9/6.0)*PI; angle += 0.1) {
			float x = PotList[i] + (RadiusofShadow * cos(angle))/2.5;
			float y = (BottomofPot + HeightofFire + RadiusofFire/sqrt(2.0) + 3.0) + RadiusofShadow * sin(angle);
			glVertex2f(x, y);
		}
		glShadeModel(GL_FLAT);
		glEnd();
		

		
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		
		glVertex2f(PotList[i], BottomofPot + TopofFire);

		glVertex2f(PotList[i], (BottomofPot + HeightofFire + RadiusofFire/sqrt(2.0) + 3.0) + RadiusofShadow * sin(-0.5*PI));
		glVertex2f(PotList[i]-WidthofTriangle/2.5, (BottomofPot + HeightofFire + RadiusofFire/sqrt(2.0) + 3.0) + RadiusofShadow * sin(-0.5*PI));
		glShadeModel(GL_FLAT);
		glEnd();
		
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(PotList[i], BottomofPot + TopofFire);
		glVertex2f(PotList[i], (BottomofPot + HeightofFire + RadiusofFire/sqrt(2.0) + 3.0) + RadiusofShadow * sin(-0.5*PI));
		glVertex2f(PotList[i]+WidthofTriangle/2, (BottomofPot + HeightofFire + RadiusofFire/sqrt(2.0) + 3.0) + RadiusofShadow * sin(-0.5*PI));
		glShadeModel(GL_FLAT);
		glEnd();
		
		glPopMatrix();
	}
}
