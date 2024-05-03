#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include<GL/glut.h>
//#include<glaux.h>
//OpenGLʮ��������
//https://blog.csdn.net/weixin_47692652/article/details/122456474?ops_request_misc

void myDisplay0(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //glBegin(GL_POINTS);
    glBegin(GL_POLYGON);//�������������
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
    //glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
    glFlush();
}

int main0(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    int cx = glutGet(GLUT_SCREEN_WIDTH);
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//Ϊ��ʹ���ھ���
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("����ͼ�εĻ���");
    glutDisplayFunc(&myDisplay0);
    glutMainLoop();
    return 0;
}

const int n = 1000;
//�޸�const int n��ֵ���۲쵱n=3,4,5,8,10,15,20,30,50�Ȳ�ͬ��ֵʱ����ı仯���
const GLfloat R = 0.5f;
const GLfloat Pi = 3.1415926536;

void myDisplay1(void)
{
    //��һ�������
    GLfloat a = 1 / (2 - 2 * cos(72 * Pi / 180));
    GLfloat bx = a * cos(18 * Pi / 180);
    GLfloat by = a * sin(18 * Pi / 180);
    GLfloat cy = -a * cos(18 * Pi / 180);
    GLfloat
        PointA[2] = { 0, a },
        PointB[2] = { bx, by },
        PointC[2] = { 0.5, cy },
        PointD[2] = { -0.5, cy },
        PointE[2] = { -bx, by };

    glClear(GL_COLOR_BUFFER_BIT);
    // ����A->C->E->B->D->A��˳�򣬿���һ�ʽ�����ǻ���
    glBegin(GL_LINE_LOOP);
    glVertex2fv(PointA);
    glVertex2fv(PointC);
    glVertex2fv(PointE);
    glVertex2fv(PointB);
    glVertex2fv(PointD);
    glEnd();
    glFlush();
}

int main1(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    int cx = glutGet(GLUT_SCREEN_WIDTH);
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//Ϊ��ʹ���ھ���
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("�ڶ���������һ�������");
    glutDisplayFunc(&myDisplay1);
    glutMainLoop();
    return 0;
}

void myDisplay2(void)
{
    //��һ��Բ
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);//�������������
    for (i = 0; i < n; i++) {
        glVertex2f(R * cos(2 * Pi / n * i), R * sin(2 * Pi / n * i));
    }
    glEnd();
    glFlush();
}

int main2(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    int cx = glutGet(GLUT_SCREEN_WIDTH);
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//Ϊ��ʹ���ھ���
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("�ڶ���������һ��Բ");
    glutDisplayFunc(&myDisplay2);
    glutMainLoop();
    return 0;
}

const GLfloat factor = 0.1f;
void myDisplay3(void)
{
    GLfloat x;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);        // ������������Ի�x��
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);        // ������������Ի�y��
    glEnd();
    glBegin(GL_LINE_STRIP);
    for (x = -1.0f / factor; x < 1.0f / factor; x += 0.01f)
    {
        glVertex2f(x * factor, sin(x) * factor);
    }
    glEnd();
    glFlush();
}

int main3(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    int cx = glutGet(GLUT_SCREEN_WIDTH);
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//Ϊ��ʹ���ھ���
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("�ڶ���������һ�����Һ���");
    glutDisplayFunc(&myDisplay3);
    glutMainLoop();
    return 0;
}


void myDisplay4(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.5f, 0.5f);
    glEnd();
    glFlush();
}


int main4(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    int cx = glutGet(GLUT_SCREEN_WIDTH);
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//Ϊ��ʹ���ھ���
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("������������������");
    glutDisplayFunc(&myDisplay4);
    glutMainLoop();
    return 0;
}


void myDisplay5(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(2, 0x0F0F);
    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.5f, 0.5f);
    glEnd();
    glFlush();
}



int main5(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    int cx = glutGet(GLUT_SCREEN_WIDTH);
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//Ϊ��ʹ���ھ���
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("����������������");
    glutDisplayFunc(&myDisplay5);
    glutMainLoop();
    return 0;
}

void myDisplay6(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT, GL_FILL); // ��������Ϊ���ģʽ
    glPolygonMode(GL_BACK, GL_LINE);  // ���÷���Ϊ����ģʽ
    glFrontFace(GL_CCW);              // ������ʱ�뷽��Ϊ����
    glBegin(GL_POLYGON);              // ����ʱ�����һ�������Σ������·�
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.0f, -0.5f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.5f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);              // ��˳ʱ�����һ�������Σ������Ϸ�
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, 0.0f);
    glEnd();
    glFlush();
}


int main6(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    int cx = glutGet(GLUT_SCREEN_WIDTH);
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//Ϊ��ʹ���ھ���
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("���������������������");
    glutDisplayFunc(&myDisplay6);
    glutMainLoop();
    return 0;
}


//glEnable(GL_CULL_FACE); �������޳�����
//glEnable(GL_POLYGON_STIPPLE);�������ο�ģʽ
void myDisplay7(void)
{
    //�ο�Ч��
    glClear(GL_COLOR_BUFFER_BIT);
    static GLubyte Mask[128];
    FILE* fp;
    fopen_s(&fp, "mask.bmp", "rb");//��ȡͼƬ
    if (!fp)
        exit(0);
    if (fseek(fp, -(int)sizeof(Mask), SEEK_END))
        exit(0);
    if (!fread(Mask, sizeof(Mask), 1, fp))
        exit(0);
    fclose(fp);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_POLYGON_STIPPLE);//�����޳�����
    glPolygonStipple(Mask);
    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);   // ����һ�����ο�Ч����������     	 
    glFlush();
}

int main7(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    int cx = glutGet(GLUT_SCREEN_WIDTH);
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//Ϊ��ʹ���ھ���
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("����������������ο�");
    glutDisplayFunc(&myDisplay7);
    glutMainLoop();
    return 0;
}

#include<GL/glut.h>
//#include<GL/glaux.h>
//#include <time.h>
//#include "tex.h"
//void myDisplay(void)
//{
//    int i;
//    for (i = 0; i < 8; ++i)
//        auxSetOneColor(i, (float)(i & 0x04), (float)(i & 0x02), (float)(i & 0x01));
//    glShadeModel(GL_FLAT);
//    glClear(GL_COLOR_BUFFER_BIT);
//    glBegin(GL_TRIANGLE_FAN);
//    glVertex2f(0.0f, 0.0f);
//    for (i = 0; i <= 8; ++i)
//    {
//        glIndexi(i);
//        glVertex2f(cos(i * Pi / 4), sin(i * Pi / 4));
//    }
//    glEnd();
//    glFlush();
//}
//
//int main(void)
//{
//    auxInitDisplayMode(AUX_SINGLE | AUX_INDEX);
//    auxInitPosition(0, 0, 400, 400);
//    auxInitWindow(L"");
//    myDisplay();
//    Sleep(10 * 1000);
//    return 0;
//}

// ̫�������������
// ����ÿ���¶���30��
// һ��12���£�����360��
static int day = 200; // day�ı仯����0��359
void myDisplay9(void)
{
    glDepthFunc(GL_ALWAYS);//���ǻ���
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75, 1, 1, 400000000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);

    // ���ƺ�ɫ�ġ�̫����
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidSphere(69600000, 20, 20);
    // ������ɫ�ġ�����
    glColor3f(0.0f, 0.0f, 1.0f);
    glRotatef(day / 360.0 * 360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(150000000, 0.0f, 0.0f);
    glutSolidSphere(15945000, 20, 20);
    // ���ƻ�ɫ�ġ�������
    glColor3f(1.0f, 1.0f, 0.0f);
    glRotatef(day / 30.0 * 360.0 - day / 360.0 * 360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(38000000, 0.0f, 0.0f);
    glutSolidSphere(4345000, 20, 20);
    glFlush();
}

int  main9(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    int cx = glutGet(GLUT_SCREEN_WIDTH);
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//Ϊ��ʹ���ھ���
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("���彲����̫����������");
    glutDisplayFunc(myDisplay9);
    glutMainLoop();
    return 0;
}

//-------------------------------------------------------------------------------------------
double CalFrequency()
{
    static int count;
    static double save;
    static clock_t last, current;
    double timegap;
    ++count;
    if (count <= 50)
        return save;
    count = 0;
    last = current;
    current = clock();
    timegap = (current - last) / (double)CLK_TCK;
    save = 50.0 / timegap;
    return save;
}//ͳ�Ƹú�������ĵ���Ƶ��

void myDisplay10(void)
{
    double FPS = CalFrequency();
    printf("FPS = %f\n", FPS);
    glDepthFunc(GL_ALWAYS);//���ǻ���
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75, 1, 1, 400000000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);

    // ���ƺ�ɫ�ġ�̫����
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidSphere(69600000, 20, 20);
    // ������ɫ�ġ�����
    glColor3f(0.0f, 0.0f, 1.0f);
    glRotatef(day / 360.0 * 360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(150000000, 0.0f, 0.0f);
    glutSolidSphere(15945000, 20, 20);
    // ���ƻ�ɫ�ġ�������
    glColor3f(1.0f, 1.0f, 0.0f);
    glRotatef(day / 30.0 * 360.0 - day / 360.0 * 360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(38000000, 0.0f, 0.0f);
    glutSolidSphere(4345000, 20, 20);

    glFlush();
    glutSwapBuffers();
}

void myIdle(void)
{
    /* �µĺ������ڿ���ʱ���ã������ǰ����������ƶ�һ�첢���»��ƣ��ﵽ����Ч�� */
    ++day;
    if (day >= 360)
        day = 0;
    myDisplay10();
}

int main10(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // �޸��˲���ΪGLUT_DOUBLE
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("����������̫�������������");   // ���˴��ڱ���
    glutDisplayFunc(&myDisplay10);
    glutIdleFunc(&myIdle);               // CPU���е�ʱ�����ĳһ����
    glutMainLoop();
    return 0;
}

static GLfloat angle = 0.0f; 
void myDisplay11(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    // ����͸��Ч����ͼ
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0f, 1.0f, 1.0f, 20.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 5.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // ����̫����Դ������һ�ְ�ɫ�Ĺ�Դ  
    {
        GLfloat sun_light_position[] = { 0.0f, 0.0f, 0.0f, 1.0f };//��Դλ��
        GLfloat sun_light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; //��η����������
        GLfloat sun_light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };//�������
        GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };//���淴���

        glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
        glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);

        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
        glEnable(GL_DEPTH_TEST);
    }

    // ����̫���Ĳ��ʲ�����̫��
    {
        GLfloat sun_mat_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
        GLfloat sun_mat_diffuse[] = { 0.0f, 0.0f, 0.0f, 1.0f };
        GLfloat sun_mat_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
        GLfloat sun_mat_emission[] = { 0.5f, 0.0f, 0.0f, 1.0f };
        GLfloat sun_mat_shininess = 0.0f;

        glMaterialfv(GL_FRONT, GL_AMBIENT, sun_mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, sun_mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, sun_mat_specular);
        glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);
        glMaterialf(GL_FRONT, GL_SHININESS, sun_mat_shininess);

        glutSolidSphere(2.0, 40, 32);
    }

    // �������Ĳ��ʲ����Ƶ���
    {
        GLfloat earth_mat_ambient[] = { 0.0f, 0.0f, 0.5f, 1.0f };
        GLfloat earth_mat_diffuse[] = { 0.0f, 0.0f, 0.5f, 1.0f };//��������ɫ
        GLfloat earth_mat_specular[] = { 0.0f, 0.0f, 1.0f, 1.0f };
        GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
        GLfloat earth_mat_shininess = 30.0f;

        glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
        glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
        glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);

        glRotatef(angle, 0.0f, -1.0f, 0.0f);
        glTranslatef(5.0f, 0.0f, 0.0f);
        glutSolidSphere(2.0, 40, 32);
    }

    glutSwapBuffers();
}

#define WIDTH 400
#define HEIGHT 400
int main11(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // �޸��˲���ΪGLUT_DOUBLE
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("���߽�����̫�������������");   // ���˴��ڱ���
    glutDisplayFunc(&myDisplay11);
    glutIdleFunc(&myIdle);               // CPU���е�ʱ�����ĳһ����
    glutMainLoop();
    return 0;
}

#define ColoredVertex(c, v) do{ glColor3fv(c); glVertex3fv(v); }while(0)
void myDisplay12(void)
{
    static int list = 0;
    if (list == 0)
    {
        // �����ʾ�б����ڣ��򴴽�
        GLfloat
            PointA[] = { 0.5f, (GLfloat)(-sqrt(6.0f) / 12) , (GLfloat)(-sqrt(3.0f) / 6) },
            PointB[] = { -0.5f, (GLfloat)(-sqrt(6.0f) / 12) , (GLfloat)(-sqrt(3.0f) / 6) },
            PointC[] = { 0.0f, (GLfloat)(-sqrt(6.0f) / 12) ,   (GLfloat)(sqrt(3.0f) / 3) },
            PointD[] = { 0.0f,   (GLfloat)(sqrt(6.0f) / 4),             0 };
        GLfloat
            ColorR[] = { 1, 0, 0 },
            ColorG[] = { 0, 1, 0 },
            ColorB[] = { 0, 0, 1 },
            ColorY[] = { 1, 1, 0 };

        list = glGenLists(1);
        glNewList(list, GL_COMPILE);
        glBegin(GL_TRIANGLES);
        // ƽ��ABC
        ColoredVertex(ColorR, PointA);
        ColoredVertex(ColorG, PointB);
        ColoredVertex(ColorB, PointC);
        // ƽ��ACD
        ColoredVertex(ColorR, PointA);
        ColoredVertex(ColorB, PointC);
        ColoredVertex(ColorY, PointD);
        // ƽ��CBD
        ColoredVertex(ColorB, PointC);
        ColoredVertex(ColorG, PointB);
        ColoredVertex(ColorY, PointD);
        // ƽ��BAD
        ColoredVertex(ColorG, PointB);
        ColoredVertex(ColorR, PointA);
        ColoredVertex(ColorY, PointD);
        glEnd();
        glEndList();

        glEnable(GL_DEPTH_TEST);
    }
    // �Ѿ���������ʾ�б���ÿ�λ�����������ʱ��������
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(angle, 1, 0.5, 0);
    glCallList(list);
    glPopMatrix();
    glutSwapBuffers();
}

#include <chrono>  // ���ڼ�ʱ��
#include <thread>  // ��������
constexpr int kRefreshInterval = 1600;  // ˢ�¼�������룩
void myIdle12(void)
{
    static auto lastTime = std::chrono::steady_clock::now();  // ��¼��һ�ε��õ�ʱ���
    auto currentTime = std::chrono::steady_clock::now();      // ��ǰʱ���
    auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime).count();  // ���㾭����ʱ��
    if (deltaTime >= kRefreshInterval)
    {
        ++angle;
        if (angle >= 360.0f)
            angle = 0.0f;
        myDisplay12();
    }
    else
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(kRefreshInterval - deltaTime));  // ����һ��ʱ���Կ���ˢ�¼��
    }
}

int main12(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("�ڰ˽�������ʾ�б�");
    glutDisplayFunc(&myDisplay12);
    glutIdleFunc(&myIdle12);
    glutMainLoop();
    return 0;
}

void myDisplay13(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    //glBlendFunc(GL_ONE, GL_ZERO);//�벻���û������
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//��ʾʹ��Դ��ɫ��alphaֵ����Ϊ���ӣ���ʾ��1.0��ȥԴ��ɫ��alphaֵ����Ϊ���ӡ�
    glBlendFunc(GL_ONE, GL_ONE);//������ɫ���
    glColor4f(1, 0, 0, 0.5);
    glRectf(-1, -1, 0.5, 0.5);
    glColor4f(0, 1, 0, 0.5);
    glRectf(-0.5, -0.5, 1, 1);

    glutSwapBuffers();
}


int main13(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("�ھŽ�������ɫ���");
    glutDisplayFunc(&myDisplay13);
    glutMainLoop();
    return 0;
}


void draw_sphere()
{
    // ���ù�Դ
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    {
        GLfloat
            pos[] = { 5.0f, 5.0f, 0.0f, 1.0f },
            ambient[] = { 0.0f, 1.0f, 1.0f, 1.0f };
        glLightfv(GL_LIGHT0, GL_POSITION, pos);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    }

    // ����һ������
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(0, 0, 2);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();
}

void display15(void)
{
    // �����Ļ
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // ���ù۲��
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 5, 25);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5, 0, 6.5, 0, 0, 0, 0, 1, 0);

    glEnable(GL_DEPTH_TEST);

    // ��������
    glDisable(GL_STENCIL_TEST);
    draw_sphere();

    // ����һ��ƽ�澵���ڻ��Ƶ�ͬʱע������ģ�建�塣
    // ���⣬Ϊ�˱�֤ƽ�澵֮��ľ����ܹ���ȷ���ƣ��ڻ���ƽ�澵ʱ��Ҫ����Ȼ���������Ϊֻ���ġ�
    // �ڻ���ʱ��ʱ�رչ���Ч��
    glClearStencil(0);
    glClear(GL_STENCIL_BUFFER_BIT);
    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
    glEnable(GL_STENCIL_TEST);

    glDisable(GL_LIGHTING);
    glColor3f(0.5f, 0.5f, 0.5f);
    glDepthMask(GL_FALSE);
    glRectf(-1.5f, -1.5f, 1.5f, 1.5f);
    glDepthMask(GL_TRUE);

    // ����һ������ǰ�������ƽ�澵�ԳƵ����壬ע���Դ��λ��ҲҪ�����ԳƸı�
    // ��Ϊƽ�澵����X���Y����ȷ����ƽ�棬����ֻҪZ����ȡ������ʵ�ֶԳ�
    // Ϊ�˱�֤����Ļ��Ʒ�Χ��������ƽ�澵�ڲ���ʹ��ģ�����
    glStencilFunc(GL_EQUAL, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
    glScalef(1.0f, 1.0f, -1.0f);
    draw_sphere();

    // ��������
    glutSwapBuffers();
}
int main15(int argc, char* argv[])
{
    // GLUT��ʼ��
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("��ʮ��������ģ�����");
    glutDisplayFunc(&display15);
    glutMainLoop();
    return 0;
    glEnable(GL_DEPTH_TEST); // ������Ȳ��� glDisable(GL_DEPTH_TEST); // ������Ȳ���
}

/*
��Ȳ���
��Ȳ�����Ҫ��Ȼ���������ģ�������Ҫģ�建���������Ƶġ����ʹ��GLUT���߰��������ڵ���glutInitDisplayMode����ʱ�ڲ����м���GLUT_DEPTH����������ȷָ��Ҫ��ʹ����Ȼ�������

��Ȳ��Ժ�ģ����Ե�ʵ��ԭ������ƣ�������һ���������������ص�ĳ��ֵ������Ҫ���в���ʱ���������ֵ����һ��ֵ���бȽϣ���ȷ���Ƿ�ͨ�����ԡ�
���ߵ��������ڣ�ģ��������趨һ��ֵ���ڲ���ʱ������趨ֵ�����صġ�ģ��ֵ�����бȽϣ�����Ȳ����Ǹ��ݶ���Ŀռ�����������ȣ��������������صġ����ֵ�����бȽϡ�
Ҳ����˵��ģ�������Ҫָ��һ��ֵ��Ϊ�Ƚϲο�������Ȳ����У�����Ƚ��õĲο�ֵ��OpenGL���ݿռ������Զ�����ġ�

*/

static int enrol = []()
    {
        int argc = 1;
        char constString[] = "D:\\Alluser\\akingse\\repos\\learn_opengl\\x64\\Debug\\FirstPoint.exe";
        char* argv[] = { constString };
        //main0(argc, argv);
        //main1(argc, argv);
        //main2(argc, argv);
        //main3(argc, argv);
        main15(argc, argv);
        return 0;
    }();