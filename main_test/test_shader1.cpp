#include "pch.h"

#include<stdio.h>
#include<stdlib.h>
#include <math.h>
//#include "GL/glew.h"

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

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void test0()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);


    //����������ɫ��
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //��������ɫ����������ɫ��������
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    //����Ƭ����ɫ��
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    //��Ƭ����ɫ����������ɫ��������
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    //���
    int  vsuccess, fsuccess;
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
    //glUseProgram(shaderProgram);//û��дshader��
    ////myShader.use();//ʹ��shader��
    //glBindVertexArray(VAO);
    //glDrawArrays(GL_TRIANGLES, 0, 3);
}

static void test1()
{


}

static int enrol = []()
    {
        //test0();
        //test1();
        return 0;
    }();