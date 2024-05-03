#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include<GL/glut.h>
//#include<glaux.h>
//OpenGL十二讲代码
//https://blog.csdn.net/weixin_47692652/article/details/122456474?ops_request_misc

void myDisplay0(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //glBegin(GL_POINTS);
    glBegin(GL_POLYGON);//单个简单填充多边形
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
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//为了使窗口居中
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("几何图形的绘制");
    glutDisplayFunc(&myDisplay0);
    glutMainLoop();
    return 0;
}

const int n = 1000;
//修改const int n的值，观察当n=3,4,5,8,10,15,20,30,50等不同数值时输出的变化情况
const GLfloat R = 0.5f;
const GLfloat Pi = 3.1415926536;

void myDisplay1(void)
{
    //画一个五角星
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
    // 按照A->C->E->B->D->A的顺序，可以一笔将五角星画出
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
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//为了使窗口居中
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("第二讲——画一个五角星");
    glutDisplayFunc(&myDisplay1);
    glutMainLoop();
    return 0;
}

void myDisplay2(void)
{
    //画一个圆
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);//单个简单填充多边形
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
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//为了使窗口居中
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("第二讲——画一个圆");
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
    glVertex2f(1.0f, 0.0f);        // 以上两个点可以画x轴
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);        // 以上两个点可以画y轴
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
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//为了使窗口居中
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("第二讲——画一个正弦函数");
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
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//为了使窗口居中
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("第三讲——画两个点");
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
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//为了使窗口居中
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("第三讲——画虚线");
    glutDisplayFunc(&myDisplay5);
    glutMainLoop();
    return 0;
}

void myDisplay6(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT, GL_FILL); // 设置正面为填充模式
    glPolygonMode(GL_BACK, GL_LINE);  // 设置反面为线形模式
    glFrontFace(GL_CCW);              // 设置逆时针方向为正面
    glBegin(GL_POLYGON);              // 按逆时针绘制一个正方形，在左下方
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.0f, -0.5f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.5f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);              // 按顺时针绘制一个正方形，在右上方
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
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//为了使窗口居中
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("第三讲——多边形正反面");
    glutDisplayFunc(&myDisplay6);
    glutMainLoop();
    return 0;
}


//glEnable(GL_CULL_FACE); 来启动剔除功能
//glEnable(GL_POLYGON_STIPPLE);来启动镂空模式
void myDisplay7(void)
{
    //镂空效果
    glClear(GL_COLOR_BUFFER_BIT);
    static GLubyte Mask[128];
    FILE* fp;
    fopen_s(&fp, "mask.bmp", "rb");//读取图片
    if (!fp)
        exit(0);
    if (fseek(fp, -(int)sizeof(Mask), SEEK_END))
        exit(0);
    if (!fread(Mask, sizeof(Mask), 1, fp))
        exit(0);
    fclose(fp);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_POLYGON_STIPPLE);//启动剔除功能
    glPolygonStipple(Mask);
    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);   // 绘制一个有镂空效果的正方形     	 
    glFlush();
}

int main7(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    int cx = glutGet(GLUT_SCREEN_WIDTH);
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//为了使窗口居中
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("第三讲——多边形镂空");
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

// 太阳、地球和月亮
// 假设每个月都是30天
// 一年12个月，共是360天
static int day = 200; // day的变化：从0到359
void myDisplay9(void)
{
    glDepthFunc(GL_ALWAYS);//总是绘制
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75, 1, 1, 400000000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);

    // 绘制红色的“太阳”
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidSphere(69600000, 20, 20);
    // 绘制蓝色的“地球”
    glColor3f(0.0f, 0.0f, 1.0f);
    glRotatef(day / 360.0 * 360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(150000000, 0.0f, 0.0f);
    glutSolidSphere(15945000, 20, 20);
    // 绘制黄色的“月亮”
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
    int cy = glutGet(GLUT_SCREEN_HEIGHT);//为了使窗口居中
    glutInitWindowPosition((cx - 400) / 2, (cy - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("第五讲——太阳月亮地球");
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
}//统计该函数自身的调用频率

void myDisplay10(void)
{
    double FPS = CalFrequency();
    printf("FPS = %f\n", FPS);
    glDepthFunc(GL_ALWAYS);//总是绘制
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75, 1, 1, 400000000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);

    // 绘制红色的“太阳”
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidSphere(69600000, 20, 20);
    // 绘制蓝色的“地球”
    glColor3f(0.0f, 0.0f, 1.0f);
    glRotatef(day / 360.0 * 360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(150000000, 0.0f, 0.0f);
    glutSolidSphere(15945000, 20, 20);
    // 绘制黄色的“月亮”
    glColor3f(1.0f, 1.0f, 0.0f);
    glRotatef(day / 30.0 * 360.0 - day / 360.0 * 360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(38000000, 0.0f, 0.0f);
    glutSolidSphere(4345000, 20, 20);

    glFlush();
    glutSwapBuffers();
}

void myIdle(void)
{
    /* 新的函数，在空闲时调用，作用是把日期往后移动一天并重新绘制，达到动画效果 */
    ++day;
    if (day >= 360)
        day = 0;
    myDisplay10();
}

int main10(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // 修改了参数为GLUT_DOUBLE
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("第六讲——太阳，地球和月亮");   // 改了窗口标题
    glutDisplayFunc(&myDisplay10);
    glutIdleFunc(&myIdle);               // CPU空闲的时间调用某一函数
    glutMainLoop();
    return 0;
}

static GLfloat angle = 0.0f; 
void myDisplay11(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    // 创建透视效果视图
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0f, 1.0f, 1.0f, 20.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 5.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // 定义太阳光源，它是一种白色的光源  
    {
        GLfloat sun_light_position[] = { 0.0f, 0.0f, 0.0f, 1.0f };//光源位置
        GLfloat sun_light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; //多次反射后遗留光
        GLfloat sun_light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };//漫反射光
        GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };//镜面反射光

        glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
        glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);

        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
        glEnable(GL_DEPTH_TEST);
    }

    // 定义太阳的材质并绘制太阳
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

    // 定义地球的材质并绘制地球
    {
        GLfloat earth_mat_ambient[] = { 0.0f, 0.0f, 0.5f, 1.0f };
        GLfloat earth_mat_diffuse[] = { 0.0f, 0.0f, 0.5f, 1.0f };//类似于蓝色
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
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // 修改了参数为GLUT_DOUBLE
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("第七讲——太阳，地球和月亮");   // 改了窗口标题
    glutDisplayFunc(&myDisplay11);
    glutIdleFunc(&myIdle);               // CPU空闲的时间调用某一函数
    glutMainLoop();
    return 0;
}

#define ColoredVertex(c, v) do{ glColor3fv(c); glVertex3fv(v); }while(0)
void myDisplay12(void)
{
    static int list = 0;
    if (list == 0)
    {
        // 如果显示列表不存在，则创建
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
        // 平面ABC
        ColoredVertex(ColorR, PointA);
        ColoredVertex(ColorG, PointB);
        ColoredVertex(ColorB, PointC);
        // 平面ACD
        ColoredVertex(ColorR, PointA);
        ColoredVertex(ColorB, PointC);
        ColoredVertex(ColorY, PointD);
        // 平面CBD
        ColoredVertex(ColorB, PointC);
        ColoredVertex(ColorG, PointB);
        ColoredVertex(ColorY, PointD);
        // 平面BAD
        ColoredVertex(ColorG, PointB);
        ColoredVertex(ColorR, PointA);
        ColoredVertex(ColorY, PointD);
        glEnd();
        glEndList();

        glEnable(GL_DEPTH_TEST);
    }
    // 已经创建了显示列表，在每次绘制正四面体时将调用它
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(angle, 1, 0.5, 0);
    glCallList(list);
    glPopMatrix();
    glutSwapBuffers();
}

#include <chrono>  // 用于计时器
#include <thread>  // 用于休眠
constexpr int kRefreshInterval = 1600;  // 刷新间隔（毫秒）
void myIdle12(void)
{
    static auto lastTime = std::chrono::steady_clock::now();  // 记录上一次调用的时间点
    auto currentTime = std::chrono::steady_clock::now();      // 当前时间点
    auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime).count();  // 计算经过的时间
    if (deltaTime >= kRefreshInterval)
    {
        ++angle;
        if (angle >= 360.0f)
            angle = 0.0f;
        myDisplay12();
    }
    else
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(kRefreshInterval - deltaTime));  // 休眠一段时间以控制刷新间隔
    }
}

int main12(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("第八讲——显示列表");
    glutDisplayFunc(&myDisplay12);
    glutIdleFunc(&myIdle12);
    glutMainLoop();
    return 0;
}

void myDisplay13(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    //glBlendFunc(GL_ONE, GL_ZERO);//与不混和没有区别
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//表示使用源颜色的alpha值来作为因子，表示用1.0减去源颜色的alpha值来作为因子。
    glBlendFunc(GL_ONE, GL_ONE);//两种颜色混合
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
    glutCreateWindow("第九讲——颜色混合");
    glutDisplayFunc(&myDisplay13);
    glutMainLoop();
    return 0;
}


void draw_sphere()
{
    // 设置光源
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    {
        GLfloat
            pos[] = { 5.0f, 5.0f, 0.0f, 1.0f },
            ambient[] = { 0.0f, 1.0f, 1.0f, 1.0f };
        glLightfv(GL_LIGHT0, GL_POSITION, pos);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    }

    // 绘制一个球体
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(0, 0, 2);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();
}

void display15(void)
{
    // 清除屏幕
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 设置观察点
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 5, 25);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5, 0, 6.5, 0, 0, 0, 0, 1, 0);

    glEnable(GL_DEPTH_TEST);

    // 绘制球体
    glDisable(GL_STENCIL_TEST);
    draw_sphere();

    // 绘制一个平面镜。在绘制的同时注意设置模板缓冲。
    // 另外，为了保证平面镜之后的镜像能够正确绘制，在绘制平面镜时需要将深度缓冲区设置为只读的。
    // 在绘制时暂时关闭光照效果
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

    // 绘制一个与先前球体关于平面镜对称的球体，注意光源的位置也要发生对称改变
    // 因为平面镜是在X轴和Y轴所确定的平面，所以只要Z坐标取反即可实现对称
    // 为了保证球体的绘制范围被限制在平面镜内部，使用模板测试
    glStencilFunc(GL_EQUAL, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
    glScalef(1.0f, 1.0f, -1.0f);
    draw_sphere();

    // 交换缓冲
    glutSwapBuffers();
}
int main15(int argc, char* argv[])
{
    // GLUT初始化
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("第十二讲——模板测试");
    glutDisplayFunc(&display15);
    glutMainLoop();
    return 0;
    glEnable(GL_DEPTH_TEST); // 启用深度测试 glDisable(GL_DEPTH_TEST); // 禁用深度测试
}

/*
深度测试
深度测试需要深度缓冲区，跟模板测试需要模板缓冲区是类似的。如果使用GLUT工具包，可以在调用glutInitDisplayMode函数时在参数中加上GLUT_DEPTH，这样来明确指定要求使用深度缓冲区。

深度测试和模板测试的实现原理很类似，都是在一个缓冲区保存像素的某个值，当需要进行测试时，将保存的值与另一个值进行比较，以确定是否通过测试。
两者的区别在于：模板测试是设定一个值，在测试时用这个设定值与像素的“模板值”进行比较，而深度测试是根据顶点的空间坐标计算出深度，用这个深度与像素的“深度值”进行比较。
也就是说，模板测试需要指定一个值作为比较参考，而深度测试中，这个比较用的参考值是OpenGL根据空间坐标自动计算的。

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