#pragma once
class MyShader
{
};

#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader
{
public:
	unsigned int ID;//Program ID
	std::string vertexString;
	std::string fragmentString;
	const char* vertexSource;
	const char* fragmentSource;
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	void use();
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;

};

#endif
