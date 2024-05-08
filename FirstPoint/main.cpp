#include <GL/glut.h>
//using Nuget
// 项目右键-管理NuGet程序包
// nupengl.core


void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);//正投影
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);//范围
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