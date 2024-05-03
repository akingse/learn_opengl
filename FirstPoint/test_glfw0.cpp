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

    while (!glfwWindowShouldClose(window))//glfwWindowShouldClose������ÿ��ѭ����ʼǰ���һ��GLFW�Ƿ�Ҫ���˳�������ǵĻ��ú�������true����Ⱦѭ��������
    {
        processInput(window);//ѭ��ÿ�ε���ʱ���øú���������û��Ƿ�����ESC��
        //��Ⱦָ��
        //glBlendColor(0.2f, 0.3f, 0.3f, 1.0f);
        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//�����ɫ����ΪXɫ
        //glClear(GL_COLOR_BUFFER_BIT);//ִ�����
        //��鲢�����¼�����������
        glfwSwapBuffers(window);//glfwSwapBuffers�����ύ����ɫ���壨������GLFW����ÿһ��������ɫֵ�Ĵ󻺳壩��������һ�����б��������ƣ����ҽ�����Ϊ�����ʾ����Ļ�ϡ�
        glfwPollEvents();//glfwPollEvents��������Ƿ񴥷��¼�������������롢����ƶ��������´���״̬�������ö�Ӧ�ػص�����������ͨ���ص������ֶ����ã�
    }


    glfwTerminate();
    return 0;

}

static int _enrol = []()->int
{
    //glfw_test_0();
    return 0;
}();

