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

//����-���������
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
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//����glViewport���������ô��ڵ�ά��
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSwapInterval(1);//���ô�ֱͬ����

    //create VAO
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //create EBO
    GLuint EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);//�����Դ�ռ䣬��ʼ������

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
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);//end sign
    glCompileShader(vertexShader); //��ɫ����������ӵ���һ��������
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
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //change context
    glBindVertexArray(0);//���
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //������ɫ
        glClear(GL_COLOR_BUFFER_BIT); //��ջ���
        glUseProgram(program);
        glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 3); //first, count
        //glDrawArrays(GL_TRIANGLES, 1, 4); //first, count
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
	//�ͷ��ڴ�
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(program);

}

//����-��ɫ�� //using uniform
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
    
    //����������ɫ��
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexShaderSource = gl_read_string("glsl/shader_uniform_vertex.glsl");
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);//end sign
    glCompileShader(vertexShader); //��ɫ����������ӵ���һ��������
    //����Ƭ����ɫ��
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentShaderSource = gl_read_string("glsl/shader_uniform_fragment.glsl");
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    //������ɫ������
    const GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);//����Ⱦ���ߴ�������
    //glGetProgramiv(shaderProgram, GL_LINK_STATUS, NULL);//iv=�������ص���һ������ GLint ���͵�����ֵ
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f   // top 
    };

    GLuint VBO, VAO;
    //VAO����һ�������������Ե�״̬,�Լ���صĶ��㻺��������
    //VBO��һ��OpenGL����������,���ڴ洢�͹��������ݡ�
    glGenVertexArrays(1, &VAO); //��һ��1��size,��VAO��ֵ1û��ϵ
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(VAO);

    while (!glfwWindowShouldClose(window))
    {
        // ����
        processInput(window);
        // �����ɫ����
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);

        // ����uniform��ɫ
        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

        // ����������
        //glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // �������岢��ѯIO�¼�
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    glfwTerminate();
    return;
}

//����-��ɫ�� //����ɫ
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

    //����������ɫ��
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexShaderSource = gl_read_string("glsl/shader_gradient_vertex.glsl");
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);//end sign
    glCompileShader(vertexShader); //��ɫ����������ӵ���һ��������
    //����Ƭ����ɫ��
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentShaderSource = gl_read_string("glsl/shader_gradient_fragment.glsl");
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    //������ɫ������
    const GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);//����Ⱦ���ߴ�������
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
    //VAO����һ�������������Ե�״̬,�Լ���صĶ��㻺��������
    //VBO��һ��OpenGL����������,���ڴ洢�͹��������ݡ�
    glGenVertexArrays(1, &VAO); //��һ��1��size,��VAO��ֵ1û��ϵ
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    auto a0 = (void*)0;
    auto a1 = (void*)1;

    // position attribute
    //(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);//��δӵ�ǰ�󶨵Ķ��㻺����(VBO)�н��Ͷ������ݡ�
    /*
    0 �Ƕ������Ե�λ��ֵ(location)��������������λ��0�����ԡ���Ӧglsl��layout (location = 0)
    3 ��ÿ���������Ե������������������3��(x, y, z)��
    GL_FLOAT ָ����������Ϊ�����͡�
    GL_FALSE ��ʾ���ݲ�Ӧ�ñ���һ����
    6 * sizeof(float) �Ƕ������ݵĲ�������һ������������ռ���ֽ���������ÿ���������6��floatֵ(3��λ�� + 3����ɫ)��
    (void*)0 ��λ�������ڶ��������е���ʼƫ������������0����Ϊλ������������ǰ�档
    */
    glEnableVertexAttribArray(0);//���ö����������� 0����λ�����ԡ�
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1); //���ö����������� 1������ɫ���ԡ�
    glUseProgram(shaderProgram);

    while (!glfwWindowShouldClose(window))
    {
        // ����
        processInput(window);
        // �����ɫ����
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // ����uniform��ɫ
        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

        // ����������
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // �������岢��ѯIO�¼�
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