#version 330 core
out vec4 FragColor;

/*
全局意味着uniform变量必须在每个着色器程序对象中都是独一无二的，而且它可以被着色器程序的任意着色器在任意阶段访问。
第二，无论你把uniform值设置成什么，uniform会一直保存它们的数据，直到它们被重置或更新。
*/
uniform vec4 ourColor; // 在OpenGL程序代码中设定这个变量

void main()
{
    FragColor = ourColor;
}