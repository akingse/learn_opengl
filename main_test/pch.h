#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <glad/glad.h> // ��Ҫ����glad�����
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "linmath.h" // �����glfw3�����һ���ļ������Դ������õ����������밲װ��ʱ�򲻻ᰲװ��ϵͳĿ¼
#include <gl/GL.h>

//https://glm.g-truc.net/0.9.8/index.html
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//using namespace glm;

#include"Shader.h"
#include"Camera.h"
#include "commonFunction.h"

