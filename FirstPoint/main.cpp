#include <GL/glut.h>

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);//ÕýÍ¶Ó°
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);//·¶Î§
}

void myPoint()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3);// 3 pixel
	glBegin(GL_POINTS); //assign draw points
	glColor3f(1.0, 0, 0); //red
	glVertex2i(-3, 3);
	glColor3f(0, 1.0, 0); //green
	glVertex2i(10, 20);
	glColor3f(0, 0, 1.0); //blue
	glVertex2i(0, -15);
	glEnd();
	glFlush(); //

}

void glutDisplayFunc()
{

}

static void test0()
{
	glutInit(NULL, NULL);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(200, 300);
	glutInitWindowSize(200, 300);
	glutCreateWindow("dispay point");

	init();
	glutDisplayFunc(myPoint);
	glutMainLoop();
}

int main(int argc, char* argv[])
{


	return 0;
}