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
* shader�����ľ��ȣ�

    highp, mediump, lowp

shader���ñ�����

    gl_Position: ����vertex shader, д����λ�ã���ͼԪ�ռ����ü��ȹ̶�����������ʹ�ã�
                 ���ڲ������ǣ�highp vec4 gl_Position;

    gl_PointSize: ����vertex shader, д��դ����ĵ��С�����ظ�����
                 ���ڲ������ǣ�mediump float gl_Position;

    gl_FragColor: ����Fragment shader��дfragment color���������Ĺ̶�����ʹ�ã�
                  mediump vec4 gl_FragColor;

    gl_FragData: ����Fragment shader���Ǹ����飬дgl_FragData[n] Ϊdata n���������Ĺ̶�����ʹ�ã�
                  mediump vec4 gl_FragData[gl_MaxDrawBuffers];

    gl_FragColor��gl_FragData�ǻ���ģ�����ͬʱд�룻

    gl_FragCoord: ����Fragment shader,ֻ���� Fragment����ڴ��ڵ�����λ�� x,y,z,1/w; ����ǹ̶�����ͼԪ��ֵ������ģ�z �����ֵ; mediump vec4 gl_FragCoord;

    gl_FrontFacing: �����ж� fragment�Ƿ����� front-facing primitive��ֻ����
                    bool gl_FrontFacing;

    gl_PointCoord: ������ point primitive; mediump vec2 gl_PointCoord;

    shader���ó�����

    const mediump int gl_MaxVertexAttribs = 8;
    const mediump int gl_MaxVertexUniformVectors = 128;
    const mediump int gl_MaxVaryingVectors = 8;
    const mediump int gl_MaxVertexTextureImageUnits = 0;
    const mediump int gl_MaxCombinedTextureImageUnits = 8;
    const mediump int gl_MaxTextureImageUnits = 8;
    const mediump int gl_MaxFragmentUnitformVectors = 16;
    const mediump int gl_MaxDrawBuffers = 1;

    uniform����
    uniform�������ⲿapplication���򴫵ݸ���vertex��fragment��shader�ı������������applicationͨ��

    ����glUniform**����������ֵ�ġ��ڣ�vertex��fragment��shader�����ڲ���uniform����������C��������

    �ĳ�����const ���������ܱ�shader�����޸ġ���shaderֻ���ã����ܸģ�

    ���uniform������vertex��fragment����֮��������ʽ��ȫһ��������������vertex��fragment����ʹ�á�

    ���൱��һ����vertex��fragment shader�����ȫ�ֱ�����

    uniform����һ��������ʾ���任���󣬲��ʣ����ղ�������ɫ����Ϣ��

    ���������ӣ�

    uniform mat4 viewProjMatrix; //ͶӰ+��ͼ����
    uniform mat4 viewMatrix;        //��ͼ����
    uniform vec3 lightPosition;     //��Դλ��

    attribute����
    attribute������ֻ����vertex shader��ʹ�õı���������������fragment shader������attribute������Ҳ���ܱ�fragment shader��ʹ�ã�
    һ����attribute��������ʾһЩ��������ݣ��磺�������꣬���ߣ��������꣬������ɫ�ȡ�
    ��application�У�һ���ú���glBindAttribLocation��������ÿ��attribute������λ�ã�Ȼ���ú���

    uniform mat4 u_matViewProjection;
    attribute vec4 a_position;
    attribute vec2 a_texCoord0;
    varying vec2 v_texCoord;

    varying����
    varying������vertex��fragment shader֮�������ݴ����õġ�һ��vertex shader�޸�varying������ֵ��
    Ȼ��fragment shaderʹ�ø�varying������ֵ�����varying������vertex��fragment shader����֮�����
    ��������һ�µġ�



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
    glfwSwapInterval(1);//���ô�ֱͬ����

    //create VAO
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //create VBO
    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);//�����Դ�ռ䣬��ʼ������
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//��ν��������������
    glEnableVertexAttribArray(0);

    //����������ɫ��
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //��������ɫ����������ɫ��������
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    //����Ƭ����ɫ��
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    //��Ƭ����ɫ����������ɫ��������
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    //���
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
    //program ������ɫ������
    const GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);//����Ⱦ���ߴ�������
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);//���պ�ϰ��
    glDeleteShader(fragmentShader); 

    while (!glfwWindowShouldClose(window))
    {
        glUseProgram(program);
        glBindVertexArray(VBO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //�ͷ��ڴ�

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