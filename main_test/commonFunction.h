#pragma once
#include <string>
#include <fstream>
#include"pch.h"
inline const char* gl_read_string(const std::string& filename)
{
	std::ifstream fs(filename);
	if (!fs.is_open())
	{
		//std::cout << "open " << filename << " fail!" << std::endl; //<iostream>
		return nullptr;
	}
	std::string* text = new std::string(std::istreambuf_iterator<char>(fs), std::istreambuf_iterator<char>());
	return text->c_str();
	//std::string text = std::string(std::istreambuf_iterator<char>(fs), std::istreambuf_iterator<char>());
	//return text.c_str();
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
inline void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
inline void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}
