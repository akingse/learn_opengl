#version 330 core
out vec4 FragColor;

/*
ȫ����ζ��uniform����������ÿ����ɫ����������ж��Ƕ�һ�޶��ģ����������Ա���ɫ�������������ɫ��������׶η��ʡ�
�ڶ����������uniformֵ���ó�ʲô��uniform��һֱ�������ǵ����ݣ�ֱ�����Ǳ����û���¡�
*/
uniform vec4 ourColor; // ��OpenGL����������趨�������

void main()
{
    FragColor = ourColor;
}