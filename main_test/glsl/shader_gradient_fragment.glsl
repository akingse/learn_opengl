#version 330 core
out vec4 FragColor; //һ��������������������
in vec3 ourColor;

void main() //����ÿ�����ص�������ɫ
{
   FragColor = vec4(ourColor, 1.0f);
}
