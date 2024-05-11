//#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <iostream>

/*
include
C:\Users\Aking\source\repos\TPL\glfw\deps
C:\Users\Aking\source\repos\TPL\glfw\include
C:\Users\Aking\source\repos\TPL\glad\include
library
C:\Users\Aking\source\repos\TPL\glfw\build\src\Debug\
C:\Users\Aking\source\repos\TPL\glfw\build\src\$(Configuration)
*/
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "linmath.h"
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
static const char* vertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main(){\n"
"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);}\n";

static const char* fragmentShaderSource =
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main(){\n"
"    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);} \n";

float vertices[] = {
     0.5f,  -0.5f, 0.0f, 
     0.0f,  0.5f, 0.0f,
     -0.5f, -0.5f, 0.0f, 
};

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void test0()
{
    glfwSetErrorCallback(error_callback);
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
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);//设置垂直同步。

    //create VAO
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

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
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
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

    while (!glfwWindowShouldClose(window))
    {
        glUseProgram(program);
        glBindVertexArray(VBO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //释放内存

}

static void test1()
{


}

static int enrol = []()
    {
        test0();
        //test1();
        return 0;
    }();