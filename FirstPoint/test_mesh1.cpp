#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

//������
static void test0()
{
    const float vertices[] = {
        // ǰ�棨˳ʱ�붨�嶥�㣩
        -0.5f, -0.5f, 0.5f,  // 0
        0.5f, -0.5f, 0.5f,   // 1
        0.5f, 0.5f, 0.5f,    // 2
        -0.5f, 0.5f, 0.5f,   // 3

        // ����
        -0.5f, -0.5f, -0.5f, // 4
        0.5f, -0.5f, -0.5f,  // 5
        0.5f, 0.5f, -0.5f,   // 6
        -0.5f, 0.5f, -0.5f   // 7
    };

    const unsigned int indices[] = {
        // ǰ��
        0, 1, 2,
        2, 3, 0,

        // ����
        4, 0, 3,
        3, 7, 4,

        // ����
        5, 4, 7,
        7, 6, 5,

        // ����
        1, 5, 6,
        6, 2, 1,

        // ����
        3, 2, 6,
        6, 7, 3,

        // ����
        4, 5, 1,
        1, 0, 4
    };
    // ��ʼ��OpenGL�ʹ���
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "Unit Cube", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glewInit();

    // �����Ͱ�VBO
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // �����Ͱ�IBO
    GLuint ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // ��ѭ��
    while (!glfwWindowShouldClose(window)) {
        // �����Ļ
        glClear(GL_COLOR_BUFFER_BIT);

        // ����������
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(indices[0]), GL_UNSIGNED_INT, 0);
        glDisableVertexAttribArray(0);

        // �����������ʹ����¼�
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // ������Դ
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ibo);
    glfwTerminate();

    return;
}

//������
static void test1()
{
    double a = 1e-7;//
    const float vertices[] = {
        // ����
        0.0f, -0.5f, 0.0f,    // 0
        0.5f, -0.5f, 0.5f,    // 1
        -0.5f, -0.5f, 0.5f,   // 2
        // ����
        0.0f, 0.5f, 0.0f,     // 3
    };

    const unsigned int indices[] = {
        // ����
        0, 1, 2,
        // ����1
        0, 3, 1,
        // ����2
        1, 3, 2,
        // ����3
        2, 3, 0
    };

    // ��ʼ��OpenGL�ʹ���
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "Unit Tetrahedron", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glewInit();

    // �����Ͱ�VBO
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // �����Ͱ�IBO
    GLuint ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // ��ѭ��
    while (!glfwWindowShouldClose(window)) {
        // �����Ļ
        glClear(GL_COLOR_BUFFER_BIT);

        // ������������
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(indices[0]), GL_UNSIGNED_INT, 0);
        glDisableVertexAttribArray(0);

        // �����������ʹ����¼�
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // ������Դ
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ibo);
    glfwTerminate();

    return;
}


static int enrol = []()
    {
        //test0();
        //test1();
        return 0;
    }();