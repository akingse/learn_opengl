#include "pch.h"


void error_callback(int code, const char* description)
{
    std::cout << code << ":" << description << std::endl;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int glfw_test_0()
{
    GLFWwindow* window;

    /* Handle GLFW Error */
    glfwSetErrorCallback(error_callback);

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    ///* Loop until the user closes the window */
    //while (!glfwWindowShouldClose(window))
    //{
    //    /* Render here */
    //    glClear(GL_COLOR_BUFFER_BIT);

    //    /* Swap front and back buffers */
    //    glfwSwapBuffers(window);

    //    /* Poll for and process events */
    //    glfwPollEvents();
    //}

    while (!glfwWindowShouldClose(window))//glfwWindowShouldClose函数在每次循环开始前检查一次GLFW是否被要求退出，如果是的话该函数返回true，渲染循环结束。
    {
        processInput(window);//循环每次迭代时调用该函数，检测用户是否输入ESC键
        //渲染指令
        //glBlendColor(0.2f, 0.3f, 0.3f, 1.0f);
        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//清除颜色设置为X色
        //glClear(GL_COLOR_BUFFER_BIT);//执行清除
        //检查并调用事件，交换缓冲
        glfwSwapBuffers(window);//glfwSwapBuffers函数会交换颜色缓冲（储存着GLFW窗口每一个像素颜色值的大缓冲），它在这一迭代中被用来绘制，并且将会作为输出显示在屏幕上。
        glfwPollEvents();//glfwPollEvents函数检查是否触发事件（比如键盘输入、鼠标移动）、更新窗口状态，并调用对应地回调函数（可以通过回调方法手动设置）
    }


    glfwTerminate();
    return 0;

}

static int _enrol = []()->int
{
    //glfw_test_0();
    return 0;
}();

