//#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <iostream>
#include "commonFunction.h"

/*
include
C:\Users\Aking\source\repos\TPL\glfw\deps
C:\Users\Aking\source\repos\TPL\glfw\include
C:\Users\Aking\source\repos\TPL\glad\include
library
C:\Users\Aking\source\repos\TPL\glfw\build\src\Debug\
C:\Users\Aking\source\repos\TPL\glfw\build\src\$(Configuration)
*/

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glfw3.lib")

/*
* shader变量的精度：

    highp, mediump, lowp

shader内置变量：

    gl_Position: 用于vertex shader, 写顶点位置；被图元收集、裁剪等固定操作功能所使用；
                 其内部声明是：highp vec4 gl_Position;

    gl_PointSize: 用于vertex shader, 写光栅化后的点大小，像素个数；
                 其内部声明是：mediump float gl_Position;

    gl_FragColor: 用于Fragment shader，写fragment color；被后续的固定管线使用；
                  mediump vec4 gl_FragColor;

    gl_FragData: 用于Fragment shader，是个数组，写gl_FragData[n] 为data n；被后续的固定管线使用；
                  mediump vec4 gl_FragData[gl_MaxDrawBuffers];

    gl_FragColor和gl_FragData是互斥的，不会同时写入；

    gl_FragCoord: 用于Fragment shader,只读， Fragment相对于窗口的坐标位置 x,y,z,1/w; 这个是固定管线图元差值后产生的；z 是深度值; mediump vec4 gl_FragCoord;

    gl_FrontFacing: 用于判断 fragment是否属于 front-facing primitive；只读；
                    bool gl_FrontFacing;

    gl_PointCoord: 仅用于 point primitive; mediump vec2 gl_PointCoord;

    shader内置常量：

    const mediump int gl_MaxVertexAttribs = 8;
    const mediump int gl_MaxVertexUniformVectors = 128;
    const mediump int gl_MaxVaryingVectors = 8;
    const mediump int gl_MaxVertexTextureImageUnits = 0;
    const mediump int gl_MaxCombinedTextureImageUnits = 8;
    const mediump int gl_MaxTextureImageUnits = 8;
    const mediump int gl_MaxFragmentUnitformVectors = 16;
    const mediump int gl_MaxDrawBuffers = 1;

    uniform变量
    uniform变量是外部application程序传递给（vertex和fragment）shader的变量。因此它是application通过

    函数glUniform**（）函数赋值的。在（vertex和fragment）shader程序内部，uniform变量就像是C语言里面

    的常量（const ），它不能被shader程序修改。（shader只能用，不能改）

    如果uniform变量在vertex和fragment两者之间声明方式完全一样，则它可以在vertex和fragment共享使用。

    （相当于一个被vertex和fragment shader共享的全局变量）

    uniform变量一般用来表示：变换矩阵，材质，光照参数和颜色等信息。

    以下是例子：

    uniform mat4 viewProjMatrix; //投影+视图矩阵
    uniform mat4 viewMatrix;        //视图矩阵
    uniform vec3 lightPosition;     //光源位置

    attribute变量
    attribute变量是只能在vertex shader中使用的变量。（它不能在fragment shader中声明attribute变量，也不能被fragment shader中使用）
    一般用attribute变量来表示一些顶点的数据，如：顶点坐标，法线，纹理坐标，顶点颜色等。
    在application中，一般用函数glBindAttribLocation（）来绑定每个attribute变量的位置，然后用函数

    uniform mat4 u_matViewProjection;
    attribute vec4 a_position;
    attribute vec2 a_texCoord0;
    varying vec2 v_texCoord;

    varying变量
    varying变量是vertex和fragment shader之间做数据传递用的。一般vertex shader修改varying变量的值，
    然后fragment shader使用该varying变量的值。因此varying变量在vertex和fragment shader二者之间的声
    明必须是一致的。



*/

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

//static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}
//
//static void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//}

//入门-你好三角形
static void test0()
{
    const char* vertexShaderSource =
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main(){\n"
        "    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);}\n";

    const char* fragmentShaderSource =
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main(){\n"
        "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);} \n";

    float vertices[] = {
         0.0f,  0.5f, 0.0f,
         0.5f,  -0.5f, 0.0f,
         -0.5f, -0.5f, 0.0f,
         0.0f,  -1.5f, 0.0f,
    };

    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 2,  // first Triangle
        1, 2, 3   // second Triangle
    };

    //glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Triangle", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//调用glViewport函数来设置窗口的维度
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSwapInterval(1);//设置垂直同步。

    //create VAO
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //create EBO
    GLuint EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);//开辟显存空间，初始化数据

    //create VBO
    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);//开辟显存空间，初始化数据
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//如何解析缓冲里的数据
    glEnableVertexAttribArray(0);

    //创建顶点着色器
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //将顶点着色器附着在着色器对象上
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);//end sign
    glCompileShader(vertexShader); //着色器输出会链接到下一个的输入
    //创建片段着色器
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    //将片段着色器附着在着色器对象上
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    //检错
    int  vsuccess, fsuccess, success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vsuccess);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fsuccess);
    if (!vsuccess)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    else if (!fsuccess)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    //program 创建着色器程序
    const GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);//将渲染管线串联起来
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);//回收好习惯
    glDeleteShader(fragmentShader); 
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //change context
    glBindVertexArray(0);//解绑
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //设置颜色
        glClear(GL_COLOR_BUFFER_BIT); //清空缓存
        glUseProgram(program);
        glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 3); //first, count
        //glDrawArrays(GL_TRIANGLES, 1, 4); //first, count
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
	//释放内存
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(program);

}

//入门-着色器 //using uniform
static void test1()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(640, 480, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
        return;
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        return;
    
    //创建顶点着色器
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexShaderSource = gl_read_string("glsl/shader_uniform_vertex.glsl");
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);//end sign
    glCompileShader(vertexShader); //着色器输出会链接到下一个的输入
    //创建片段着色器
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentShaderSource = gl_read_string("glsl/shader_uniform_fragment.glsl");
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    //创建着色器程序
    const GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);//将渲染管线串联起来
    //glGetProgramiv(shaderProgram, GL_LINK_STATUS, NULL);//iv=函数返回的是一个或多个 GLint 类型的整数值
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f   // top 
    };

    GLuint VBO, VAO;
    //VAO保存一个或多个顶点属性的状态,以及相关的顶点缓冲区对象。
    //VBO是一种OpenGL缓冲区对象,用于存储和管理顶点数据。
    glGenVertexArrays(1, &VAO); //第一个1是size,跟VAO的值1没关系
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(VAO);

    while (!glfwWindowShouldClose(window))
    {
        // 输入
        processInput(window);
        // 清除颜色缓冲
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);

        // 更新uniform颜色
        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

        // 绘制三角形
        //glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // 交换缓冲并查询IO事件
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    glfwTerminate();
    return;
}

//入门-着色器 //渐变色
static void test2()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(640, 480, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
        return;
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        return;

    int nrAttributes; //default 16
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

    //创建顶点着色器
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexShaderSource = gl_read_string("glsl/shader_gradient_vertex.glsl");
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);//end sign
    glCompileShader(vertexShader); //着色器输出会链接到下一个的输入
    //创建片段着色器
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentShaderSource = gl_read_string("glsl/shader_gradient_fragment.glsl");
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    //创建着色器程序
    const GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);//将渲染管线串联起来
    //glGetProgramiv(shaderProgram, GL_LINK_STATUS, NULL);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {
        // positions         // colors
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
    };

    GLuint VBO, VAO;
    //VAO保存一个或多个顶点属性的状态,以及相关的顶点缓冲区对象。
    //VBO是一种OpenGL缓冲区对象,用于存储和管理顶点数据。
    glGenVertexArrays(1, &VAO); //第一个1是size,跟VAO的值1没关系
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    auto a0 = (void*)0;
    auto a1 = (void*)1;

    // position attribute
    //(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);//如何从当前绑定的顶点缓冲区(VBO)中解释顶点数据。
    /*
    0 是顶点属性的位置值(location)。这里我们设置位置0的属性。对应glsl中layout (location = 0)
    3 是每个顶点属性的组件数量，在这里是3个(x, y, z)。
    GL_FLOAT 指定数据类型为浮点型。
    GL_FALSE 表示数据不应该被归一化。
    6 * sizeof(float) 是顶点数据的步长，即一个顶点数据所占的字节数。这里每个顶点包含6个float值(3个位置 + 3个颜色)。
    (void*)0 是位置属性在顶点数据中的起始偏移量，这里是0，因为位置属性是在最前面。
    */
    glEnableVertexAttribArray(0);//启用顶点属性数组 0，即位置属性。
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1); //启用顶点属性数组 1，即颜色属性。
    glUseProgram(shaderProgram);

    while (!glfwWindowShouldClose(window))
    {
        // 输入
        processInput(window);
        // 清除颜色缓冲
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 更新uniform颜色
        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

        // 绘制三角形
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // 交换缓冲并查询IO事件
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    glfwTerminate();
    return;
}

static int enrol = []()
    {
        //test0();
        test1();
        //test2();
        return 0;
    }();