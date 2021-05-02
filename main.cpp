#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#endif
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int win;
GLint m_viewport[4];
bool mButtonPressed = false;
enum view { INTRO , MENU , LINEAR , BINARY , EXIT};
view currentView = INTRO;
int mouseX , mouseY;
int val = 0;
void *font = GLUT_BITMAP_9_BY_15;

void init(){
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_VIEWPORT);
    glLoadIdentity();
    gluOrtho2D(0,700,0,700);
}


void output(int x , int y , char *str){
    int len, i;
      glRasterPos2f(x, y);
      len = (int) strlen(str);
      for (i = 0; i < len; i++) {
        glutBitmapCharacter(font, str[i]);
      }
}

void backButton() {

    glBegin(GL_LINE_LOOP);
        glVertex2f(69,46);
        glVertex2f(69,75);
        glVertex2f(138,75);
        glVertex2f(138,46);
    glEnd();

	if(mouseX <= 138 && mouseX >= 69 && mouseY >= 46 && mouseY <= 75){
			glColor3f(0, 0, 1);
			if(mButtonPressed) {
				currentView = MENU;
				mButtonPressed = false;
				glutPostRedisplay();
			}
	}
	else
        glColor3f(1, 0, 0);

	output(82 ,58 , "Back");
}

void rasterDisp(int x , int y , int z , char *str){
    glColor3b(1,1,1);
    glRasterPos3f(x, y, z);
	for(char* c = str; *c != '\0'; c++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24  , *c);
	}
}

void introScreen(){
    glClear(GL_COLOR_BUFFER_BIT);
    //OUTER LINE
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        glVertex2f(7,7);
        glVertex2f(696,7);
        glVertex2f(696,696);
        glVertex2f(7,696);
    glEnd();
    //END OUTER LINE

    //INNER LINE
    glColor3f(0,0,0);
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(14 , 14);
        glVertex2f(689,14);
        glVertex2f(689,689);
        glVertex2f(14,689);
    glEnd();
    //END INNER LINE

    glColor3f(0,0,1);
    output(160, 660 ,"N.M.A.M INSTITUTE OF TECHNOLOGY");
    glColor3f(0,0,0);
    output(120, 630,"Department of Computer Science and Engineering");

    //LINE BELOW COLLEGE LOGO
    glBegin(GL_LINES);
        glVertex2f(20,620);
        glVertex2f(680,620);
    glEnd();
    //END LINE BELOW LOGO

    output(90, 590, "Mini Project Title:");
    output(230, 590, "     Visualization of Searching Algorithms");

    output(129, 565 , "Course Code : ");
    output(230, 565 , "18CS603");

    output(129, 540, "Course Name : ");
    output(230, 540, "Computer Graphics");


    output(148, 515, "Semester : ");
    output(230, 515, "6th ");

    output(155, 495, "Section : ");
    output(230, 495, "C ");

    output(124, 475, "Submitted By : ");
    output(230 , 475 , "4NM18CS164");
    output(230 , 455 , "(Sharma Rahul Munna)");

    output(370 , 475 , "4NM18CS128");
    output(370 , 455 , "(Ramsharavan)");

    output(124, 425, "Submitted To :");
    output(230, 425, "Mr Puneeth R.P ");
    output(230 , 405 , "Assistant Professor Grade II");
    output(190 , 380 , "Department Of Computer Science And Engineering");

    output(150 , 300,"Press ENTER");
	glFlush();
 	glutSwapBuffers();
}


void tick(){
    glutPostRedisplay();
}

void passiveMotionFunc(int x,int y) {
	mouseX = float(x)/(m_viewport[2]/700.0);
	mouseY = 700.0-(float(y)/(m_viewport[3]/700.0));
	glutPostRedisplay();
}

void startScreen(){

    //LINEAR BUTTON
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
        glVertex2f(240 , 550);
        glVertex2f(240 , 650);
        glVertex2f(440 , 650);
        glVertex2f(440 , 550);
    glEnd();

    if(mouseX >= 240 && mouseX <= 440 && mouseY>=550 && mouseY<=650){
		glColor3f(0 ,0 ,1);
		if(mButtonPressed){
            currentView = LINEAR;
			mButtonPressed = false;
		}
	} else
		glColor3f(1 , 0, 0);

    rasterDisp(300 , 590 , 0.4 , "LINEAR");
    //END LINEAR BUTTON




    //BINARY BUTTON
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
        glVertex2f(240 , 350);
        glVertex2f(240 , 450);
        glVertex2f(440 , 450);
        glVertex2f(440 , 350);
    glEnd();

    if(mouseX>=240 && mouseX<=440 && mouseY>=350 && mouseY<=450){
		glColor3f(0 ,0 ,1);
		if(mButtonPressed){
            currentView = BINARY;
			mButtonPressed = false;
		}
	} else
		glColor3f(1 , 0, 0);

    rasterDisp(300 , 390 , 0.4 , "BINARY");
    //END  BINARY BUTTON


    //EXIT BUTTON
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
        glVertex2f(240 , 150);
        glVertex2f(240 , 250);
        glVertex2f(440 , 250);
        glVertex2f(440 , 150);
    glEnd();

    if(mouseX>=240 && mouseX<=440 && mouseY>=150 && mouseY<=250){
		glColor3f(0 ,0 ,1);
		if(mButtonPressed){
            currentView = EXIT;
			mButtonPressed = false;
		}
	} else
		glColor3f(1 , 0, 0);

    rasterDisp(300 , 190 , 0.4 , "QUIT");
    //END  EXIT BUTTON


    glutPostRedisplay();

}



void mouseClick(int buttonPressed ,int state ,int x, int y) {

	if(buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mButtonPressed = true;
		printf("mousex = %d \nmouseY = %d\n", mouseX, mouseY);
	}
	else
		mButtonPressed = false;
	glutPostRedisplay();
}

void keyPressed(unsigned char k, int x, int y){
	printf("key pressed\n");
	switch (k)
	{
		case 13:
			if(currentView == INTRO) {
				currentView = MENU;
				printf("view value changed to %d", currentView);
			}
			printf("enter key pressed\n");
			break;
	}
	glutPostRedisplay();
}

void linear(){
    backButton();
    glutPostRedisplay();
}

void exitScreen(){
    backButton();
    glutDestroyWindow(win);
    exit(0);
}

void binary(){
    backButton();
    glutPostRedisplay();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	switch (currentView)
	{
		case INTRO:
			introScreen();
			break;
        case MENU:
            startScreen();
            break;
        case LINEAR:
            linear();
            break;
        case BINARY:
            binary();
            break;
        case EXIT:
            exitScreen();
            break;
        default:
            introScreen();
            break;
	}
	glFlush();
	glutSwapBuffers();
}

int main(int argc , char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(500,90);
    glutInitWindowSize(700, 700);
	win = glutCreateWindow("Dynamic Searching Visualizer");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyPressed);
	glutMouseFunc(mouseClick);
	glGetIntegerv(GL_VIEWPORT ,m_viewport);
    glutPassiveMotionFunc(passiveMotionFunc);
	glutMainLoop();
    return 0;
}
