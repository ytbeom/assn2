#include "stage.h"

Background::Background(){
	season = 1;
	int i;
	// ��� ������ ��ġ �ʱ�ȭ
	for (i = 0; i < mapsize/10; i++) {
		int x = rand()%((int)mapsize+200)-100;
		int y = rand()%100+10;
		BackgroundX.push_back(x);
		BackgroundY.push_back(y);
	}
	// ��� ���ڿ� �� ��
	for (i = 0; i < 200; i++) {
		int d = (rand()+i)%(100);
		dec[i] = d;
	}
}
void Background::init(float _mapsize, float _bottom, int _season){
	mapsize = _mapsize;
	bottom = _bottom;
	season = _season;
	for (int i = 0; i < 200; i++) {
		int d = (rand())%((int)mapsize);
		dec[i] = d;
		//printf("%d\n",d);
	}

}
void Background::draw(int BackgroundChange){
	
	//�ϴ� ����?
	glColor3f(0.529,0.807,0.980);
	glRectf(-mapsize,10,mapsize+200,100);
	

		// ���� ȭ�� �ٴ�
		if(season==1)
			glColor3f(0,0.6,0);
		else if(season==2)
			glColor3f(0,0.4,0);
		else if(season==3)
			glColor3f(0.4,0.2,0);
		else if(season==4)
			glColor3f(1.0,1.0,1.0);
		glRectf(-mapsize,0,mapsize+200,bottom-10);

		if(season==3){
			int i;
			int k=0;
			for(i=0;i<(mapsize+200)/2;i++){
				k++;
				if(k>190)
					k=0;
				int temp3 = dec[k]%3;
				int temp7 = dec[k]%7;
				for(int j=0;j<(temp7*k)%5;j++){
					float tempY = bottom-10-j*(float)(temp7/6);
					glColor3f((float)((temp3+j)%3+8)/10,(float)(temp7+4-j)/10,0);
					glBegin(GL_POLYGON);
					glVertex2f(1.5*i-50,tempY);
					glVertex2f(1.5*i-51, tempY-1);
					glVertex2f(1.5*i-50.2+temp3, tempY-2.4);
					glVertex2f(1.5*i+50.8, tempY-0.3);
					glEnd();
				}
			}
		}
		if(season!=2){
			// ���� �׸���
			if (BackgroundChange < 9) {
				for (unsigned int i = 0; i < BackgroundX.size(); i++) {
					drawFlying(season,BackgroundX[i],BackgroundY[i]);
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

void Background::drawFlying(int season, float X, float Y){
	
	if(season==3){
		int color;
		color = (int)X%2;
		if(color==0){//��ǳ
			glPushMatrix();
			glRotatef(((int)X*10)%360,0,0,1);
			glColor3f(1,0,0);
			glBegin(GL_TRIANGLES);
			glVertex2f(X+1,Y);
			glVertex2f(X-2,Y+0.5);
			glVertex2f(X+1,Y+1);
			glEnd();
			glBegin(GL_TRIANGLES);
			glVertex2f(X,Y+1);
			glVertex2f(X+1.5,Y+2.5);
			glVertex2f(X+1,Y+0.5);
			glEnd();
			glBegin(GL_TRIANGLES);
			glVertex2f(X,Y);
			glVertex2f(X+1.5,Y-1.5);
			glVertex2f(X+1,Y+0.5);
			glEnd();
			glBegin(GL_TRIANGLES);
			glVertex2f(X,Y+0.5);
			glVertex2f(X-1.5,Y+2.5);
			glVertex2f(X+0.5,Y+1);
			glEnd();
			glBegin(GL_TRIANGLES);
			glVertex2f(X,Y+0.5);
			glVertex2f(X-1.5,Y-1.5);
			glVertex2f(X+0.5,Y);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex2f(X, Y);
			glVertex2f(X+1, Y);
			glVertex2f(X+1, Y+1);
			glVertex2f(X, Y+1);
			glEnd();
			glPopMatrix();
		}
		else{//����
			glColor3f(1,1,0);
			glPushMatrix();
			glRotatef(((int)X*10)%360,0,0,1);
			glBegin(GL_POLYGON);
			glVertex2f(X, Y);
			for( float angle = (-3.0/6.0)*PI;angle<(1.1/6.0)*PI;angle+=0.1){
				float x = X+2*cos(angle);
				float y = Y+2*sin(angle);
				glVertex2f(x,y);
			}
			glEnd();
			glPopMatrix();	
		}
	}
	else{
		if(season==1)
			glColor3f(1.0,0.4,0.4);
		int fsize = 1;
		glBegin(GL_POLYGON);
		glVertex2f(X, Y);
		glVertex2f(X+fsize, Y);
		glVertex2f(X+fsize, Y+fsize);
		glVertex2f(X, Y+fsize);
		glEnd();
	}

}