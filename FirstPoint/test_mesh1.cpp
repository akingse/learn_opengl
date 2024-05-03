#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

//立方体
static void test0()
{
    const float vertices[] = {
        // 前面（顺时针定义顶点）
        -0.5f, -0.5f, 0.5f,  // 0
        0.5f, -0.5f, 0.5f,   // 1
        0.5f, 0.5f, 0.5f,    // 2
        -0.5f, 0.5f, 0.5f,   // 3

        // 后面
        -0.5f, -0.5f, -0.5f, // 4
        0.5f, -0.5f, -0.5f,  // 5
        0.5f, 0.5f, -0.5f,   // 6
        -0.5f, 0.5f, -0.5f   // 7
    };

    const unsigned int indices[] = {
        // 前面
        0, 1, 2,
        2, 3, 0,

        // 左面
        4, 0, 3,
        3, 7, 4,

        // 后面
        5, 4, 7,
        7, 6, 5,

        // 右面
        1, 5, 6,
        6, 2, 1,

        // 上面
        3, 2, 6,
        6, 7, 3,

        // 底面
        4, 5, 1,
        1, 0, 4
    };
    // 初始化OpenGL和窗口
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "Unit Cube", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glewInit();

    // 创建和绑定VBO
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 创建和绑定IBO
    GLuint ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 主循环
    while (!glfwWindowShouldClose(window)) {
        // 清除屏幕
        glClear(GL_COLOR_BUFFER_BIT);

        // 绘制立方体
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(indices[0]), GL_UNSIGNED_INT, 0);
        glDisableVertexAttribArray(0);

        // 交换缓冲区和处理事件
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 清理资源
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ibo);
    glfwTerminate();

    return;
}

//四面体
static void test1()
{
    double a = 1e-7;//
    const float vertices[] = {
        // 底面
        0.0f, -0.5f, 0.0f,    // 0
        0.5f, -0.5f, 0.5f,    // 1
        -0.5f, -0.5f, 0.5f,   // 2
        // 正面
        0.0f, 0.5f, 0.0f,     // 3
    };

    const unsigned int indices[] = {
        // 底面
        0, 1, 2,
        // 侧面1
        0, 3, 1,
        // 侧面2
        1, 3, 2,
        // 侧面3
        2, 3, 0
    };

    // 初始化OpenGL和窗口
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "Unit Tetrahedron", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glewInit();

    // 创建和绑定VBO
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 创建和绑定IBO
    GLuint ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 主循环
    while (!glfwWindowShouldClose(window)) {
        // 清除屏幕
        glClear(GL_COLOR_BUFFER_BIT);

        // 绘制正四面体
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(indices[0]), GL_UNSIGNED_INT, 0);
        glDisableVertexAttribArray(0);

        // 交换缓冲区和处理事件
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 清理资源
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