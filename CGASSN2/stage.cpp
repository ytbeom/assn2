#include "stage.h"

Background::Background(){
	season = 1;
	int i;
	// 배경 날림의 위치 초기화
	for (i = 0; i < mapsize/10; i++) {
		int x = rand()%((int)mapsize+200)-100;
		int y = rand()%100+10;
		BackgroundX.push_back(x);
		BackgroundY.push_back(y);
	}
	// 배경 데코에 쓸 것
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
	
	//하늘 바탕?
	glColor3f(0.529,0.807,0.980);
	glRectf(-mapsize,10,mapsize+200,100);
	

		// 게임 화면 바닥
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
			// 꽃잎 그리기
			if (BackgroundChange < 9) {
				for (unsigned int i = 0; i < BackgroundX.size(); i++) {
					drawFlying(season,BackgroundX[i],BackgroundY[i]);
				}
			}
			else { // 꽃잎 위치 update
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
	// 시작 위치에 노란색 깃발 표시
	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-10, 6);
	glVertex2f(-10, 46);
	glVertex2f(-10+20, 36);
	glVertex2f(-10, 30);
	glEnd();

	// 끝나는 위치에 노란색 깃발 표시
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
		if(color==0){//단풍
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
		else{//은행
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

void Background::info(float lion_x){
	void *font = GLUT_BITMAP_TIMES_ROMAN_24;
	char string[] ="STAGE : ";
	glColor3f(0,0,0.5);
	glRasterPos2f(lion_x+120,90);
	int len = 8;
	for(int i=0;i<len;i++)
		glutBitmapCharacter(font,string[i]);
	char print_stage;
	print_stage=season+48;
	glutBitmapCharacter(font,print_stage);


	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(lion_x+145, 91);
	int now=lion_x;
	if(lion_x<0)
		now=0;
	for( float angle = 0;angle<((now/mapsize)*2)*PI;angle+=0.1){
		float x = lion_x+145+2*cos(angle);
		float y = 91+2*sin(angle);
		glVertex2f(x,y);
	}
	glEnd();

}
