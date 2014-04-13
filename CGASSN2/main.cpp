#include <time.h>
#include <stdlib.h>
#include "lion.h"
#include "firepot.h"
#include "fireloop.h"
#include "stage.h"


//vector<int> PotList; // ���׾Ƹ��� x ��ǥ�� �����ϴ� vector
vector<int> LoopList; // �Ұ��� x ��ǥ�� �����ϴ� vector
float mapsize;
float bottom = 20.0;
int jumplength = 80; // ���ڰ� 1ȸ ������ �� �����̴� �Ÿ�
int NumofLoop;
int xposition = 0.0;
extern float RadiusofLoop;
extern float top;
int BackgroundChange = 0;
int translateLoop = 0;
int stage=1;
Lion my_lion;
Background my_bg;
Firepot my_pot(jumplength);

void init(void)
{
	my_lion.x = 0;
	my_lion.y = bottom;
	my_lion.size = 20;

	srand((unsigned int)time(NULL));
	
	// 1000���� 2000 ������ mapsize ����
	mapsize = rand()%1000+000;

	my_bg.init(mapsize,bottom,stage);
	my_pot.init(jumplength,mapsize,stage);


	// �Ұ� ����/��ġ ���� (���� map �ۿ� �־ ��)
	NumofLoop = rand()%1000+500; // 500���� 1000�� ������ Loop ����
	LoopList.push_back(rand()%(2*jumplength+1)+jumplength); // 0~2*jumplength ������ ��ġ�� ù Loop ����
	for (int i=0; i<NumofLoop-1; i++) {
		// �� ���� jumplength~3*jumplength �� ������ ���� ���� ����
		LoopList.push_back(LoopList[i]+(rand()%(jumplength+1)+2*jumplength));
	}

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}
int collision(){

	for(int i = 0; i < my_pot.NumofPot; i++){
		if(my_lion.IsCollisionPot(my_pot.PotList[i]/2, (my_pot.BottomofPot + my_pot.TopofFire)/2, my_pot.RadiusofFire/2))
			return true;
	}
/*	
	for(int i = 0; i < NumofLoop; i++){
		if(my_lion.IsCollisionLoop(LoopList[i]+translateLoop, top - RadiusofLoop, RadiusofLoop))
			return true;
	}
	*/
	return false;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	if (BackgroundChange < 9) 
		BackgroundChange++;
	else
		BackgroundChange=0;

	
	my_bg.draw(BackgroundChange);

	if (!collision() && my_lion.x > mapsize && my_bg.season<4) {
		my_lion.drawClear(my_lion);
		glFlush();
		glutSwapBuffers();
		Sleep(2000);
		stage++;
		init();
		//exit(1);
	}
	else if (!collision() && my_lion.x > mapsize && my_bg.season==4) {
		my_lion.drawClear(my_lion);
		glFlush();
		glutSwapBuffers();
		Sleep(2000);
		exit(1);
	}
	else if(!collision()) {

		//translate Loop
		glPushMatrix();
		glTranslatef(translateLoop,0,0);
		display_fireloop_front(LoopList, BackgroundChange);
		glPopMatrix();

		//draw lion
		my_lion.drawLeg();
		my_lion.drawLion();

		//translate Loop
		glPushMatrix();
		glTranslatef(translateLoop,0,0);
		display_fireloop_back(LoopList, BackgroundChange);
		glPopMatrix();

		//draw firepot
		glPushMatrix();
		glScalef(0.5f,0.5f,1.0f);
		my_pot.display_firepot(BackgroundChange);
		glPopMatrix();


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
	// Ű���� �Է�(��, ��, ��) �޾Ƽ� �̺�Ʈ �߻���Ű��
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
	translateLoop-=1;
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
