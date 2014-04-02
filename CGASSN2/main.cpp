#include <time.h>
#include <stdlib.h>
#include "lion.h"
#include "firepot.h"
#include "fireloop.h"

Lion my_lion;
vector<int> PotList; // 불항아리의 x 좌표를 저장하는 vector
vector<int> LoopList; // 불고리의 x 좌표를 저장하는 vector
float mapsize;
float bottom = 20.0;
int jumplength = 80; // 사자가 1회 점프할 때 움직이는 거리
int NumofPot = 0;
int NumofLoop;
int xposition = 0.0;
extern float RadiusofLoop;
extern float top;
extern float RadiusofFire;
extern float BottomofPot;
extern float TopofFire;
int BackgroundChange = 0;
vector<int> BackgroundX;
vector<int> BackgroundY;

void init(void)
{
	my_lion.x = 0;
	my_lion.y = bottom;
	my_lion.size = 20;

	srand((unsigned int)time(NULL));
	
	// 2000에서 3000 사이의 mapsize 생성
	mapsize = rand()%1000+2000;

	// 배경 꽃잎의 위치 초기화
	for (int i = 0; i < mapsize/10; i++) {
		int x = rand()%((int)mapsize+200)-100;
		int y = rand()%100+10;
		BackgroundX.push_back(x);
		BackgroundY.push_back(y);
	}

	// 불항아리 개수/위치 설정 (게임 map 안에 있게끔)
	PotList.push_back(rand()%(jumplength+1)+jumplength*2); // 0~jumplength 사이의 위치에 첫 Pot 생성
	for (int i=0; i<mapsize/jumplength; i++) {
		 // 앞 항아리와 jumplength~2*jumplength 의 간격을 갖는 항아리를 생성
		int position = PotList[i]+(rand()%(jumplength+1)+jumplength*2);
		if (position < mapsize)
			PotList.push_back(position);
		else
			break;
	}
	NumofPot = PotList.size();

	// 불고리 개수/위치 설정 (게임 map 밖에 있어도 됨)
	NumofLoop = rand()%1000+500; // 500에서 1000개 사이의 Loop 생성
	LoopList.push_back(rand()%(2*jumplength+1)+jumplength); // 0~2*jumplength 사이의 위치에 첫 Loop 생성
	for (int i=0; i<NumofLoop-1; i++) {
		// 앞 고리와 jumplength~3*jumplength 의 간격을 갖는 고리를 생성
		LoopList.push_back(LoopList[i]+(rand()%(jumplength+1)+2*jumplength));
	}

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

int collision(){

	for(int i = 0; i < NumofPot; i++){
		if(my_lion.IsCollisionPot(PotList[i]/2, (BottomofPot + TopofFire)/2, RadiusofFire/2))
			return true;
	}
	
	for(int i = 0; i < NumofLoop; i++){
		if(my_lion.IsCollisionLoop(LoopList[i], top - RadiusofLoop, RadiusofLoop))
			return true;
	}

	return false;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	// 게임 화면 바닥을 분홍색으로 색칠
	glColor3f(1.0,0.5,0.5);
	glRectf(-mapsize,0,mapsize+200,bottom-10);

	// 꽃잎 그리기
	if (BackgroundChange < 9) {
		BackgroundChange++;
		for (int i = 0; i < BackgroundX.size(); i++) {
			glColor3f(1.0,0.4,0.4);
			glBegin(GL_POLYGON);
			glVertex2f(BackgroundX[i], BackgroundY[i]);
			glVertex2f(BackgroundX[i]+1, BackgroundY[i]);
			glVertex2f(BackgroundX[i]+1, BackgroundY[i]+1);
			glVertex2f(BackgroundX[i], BackgroundY[i]+1);
			glEnd();
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
		BackgroundChange = 0;
		for (int i = 0; i < BackgroundX.size(); i++) {
			glColor3f(1.0,0.4,0.4);
			glBegin(GL_POLYGON);
			glVertex2f(BackgroundX[i], BackgroundY[i]);
			glVertex2f(BackgroundX[i]+1, BackgroundY[i]);
			glVertex2f(BackgroundX[i]+1, BackgroundY[i]+1);
			glVertex2f(BackgroundX[i], BackgroundY[i]+1);
			glEnd();
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

	if (!collision() && my_lion.x > mapsize) {
		my_lion.drawClear(my_lion);
		glFlush();
		glutSwapBuffers();
		Sleep(2000);
		exit(1);
	}

	else if(!collision()) {
		display_fireloop_front(LoopList);
		my_lion.drawLeg();
		my_lion.drawLion();
		display_fireloop_back(LoopList);
		glScalef(0.5f,0.5f,1.0f);
		display_firepot(PotList);
		glLoadIdentity();
		glFlush();
		glutSwapBuffers();
	}
	
	else {
		my_lion.drawDeath(my_lion);
		glFlush();
		glutSwapBuffers();
		Sleep(2000);
		exit(1);
	}
}


void Stop(int value){
	int keep;
	if(my_lion.y!=bottom)
		keep=0;
	else{
		if(my_lion.velocity<0.005 && my_lion.velocity>-0.005){
			my_lion.velocity=0;
			my_lion.state=0;
			keep=0;
		}
		else if(my_lion.velocity>0){
			keep=1;
			my_lion.velocity -= 0.005;
		}
		else{
			keep=1;
			my_lion.velocity += 0.005;
		}
	}
	//printf("%f \n",my_lion.velocity);
	if(keep)
		glutTimerFunc(100, Stop, 1);
}



float jump_initX = 0;
float jump_upX = 0;
void Jump(int value){

	int keep = 1;
	float print_x;

	//jump forward
	if(my_lion.velocity>0){
		my_lion.state=1;
		print_x = my_lion.x-jump_initX;
		my_lion.x += 1;
	}

	//jumb backward
	else if(my_lion.velocity<0){
		my_lion.state=1;
		print_x = jump_initX-my_lion.x;
		my_lion.x -= 1;
	}

	//jump up
	else{
		my_lion.state=2;
		if(jump_upX<81)
			jump_upX+=1;
			print_x = jump_upX;
	}

	my_lion.y = bottom + 60 - 0.066*(print_x-30)*(print_x-30);

	glutPostRedisplay();

	if(my_lion.y<bottom){
		keep=0;
		my_lion.state=0;
		my_lion.y=bottom;
		jump_upX=0;
		glutTimerFunc(1, Stop, 1);
//		printf("x = %f\n",print_x);
	}
	if(keep)
		glutTimerFunc(2000/60, Jump, 1);
}



void specialkeyboard(int key, int x, int y)
{
	// TODO
	// 키보드 입력(좌, 우, 상) 받아서 이벤트 발생시키기
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	switch (key) {
	case GLUT_KEY_UP:
		if(my_lion.y==bottom){
			jump_initX = my_lion.x;
			glutTimerFunc(2000/60,Jump,1);
		}
		break;
	case GLUT_KEY_DOWN:
		my_lion.velocity = 0.0;
		my_lion.state=0;
		break;
	case GLUT_KEY_RIGHT:
		if(my_lion.y==bottom){
			my_lion.x += 1;
			my_lion.velocity += 0.05;
			if(my_lion.velocity<0)
				my_lion.velocity=0;
			if(my_lion.c_state>5){
				my_lion.c_state++;
				if(my_lion.c_state==10)
					my_lion.c_state=0;
				my_lion.state=2;
			}
			else{
				my_lion.c_state++;
				my_lion.state=1;
			}
			glutTimerFunc(100, Stop, 1);
		}			
		break;
	case GLUT_KEY_LEFT:
		if(my_lion.y==bottom){
			my_lion.x -= 1;
			my_lion.velocity -= 0.05;
			if(my_lion.velocity>0)
				my_lion.velocity=0;
			if(my_lion.c_state>5){
				my_lion.c_state++;
				if(my_lion.c_state==10)
					my_lion.c_state=0;
				my_lion.state=2;
			}
			else{
				my_lion.c_state++;
				my_lion.state=1;
			}
			glutTimerFunc(100, Stop, 1);
		}
		break;
	}
	gluOrtho2D(-50+my_lion.x, 150+my_lion.x, 0, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	// TODO
	// gluOrtho2D update
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50+xposition, 150+xposition, 0, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void moveObjects(int) {
	for (int i = 0; i < NumofLoop; i++) {
		LoopList[i]-=1;
	}
	glutPostRedisplay();
	glutSpecialFunc(specialkeyboard);
	glutTimerFunc(2000/60,moveObjects,1);
	
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Circus Charlie");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	
	glutTimerFunc(2000/60,moveObjects,1);
	glutMainLoop();
}
