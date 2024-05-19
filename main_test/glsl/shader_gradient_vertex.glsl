#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
out vec3 ourColor;

void main() //着色器的主函数,在每个顶点上都会被执行一次
{
   gl_Position = vec4(aPos, 1.0);
   ourColor = aColor;
}