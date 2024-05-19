#version 330 core
out vec4 FragColor; //一个特殊的内置输出变量。
in vec3 ourColor;

void main() //计算每个像素的最终颜色
{
   FragColor = vec4(ourColor, 1.0f);
}
