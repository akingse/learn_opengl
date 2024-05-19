#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <glad/glad.h> // 需要依赖glad这个库
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "linmath.h" // 这个是glfw3里面的一个文件，可以从里面拿到，不过编译安装的时候不会安装到系统目录
#include <gl/GL.h>

//https://glm.g-truc.net/0.9.8/index.html
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//using namespace glm;

#include"Shader.h"
#include"Camera.h"
#include "commonFunction.h"

