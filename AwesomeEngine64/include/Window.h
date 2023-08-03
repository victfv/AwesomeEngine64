#pragma once
#include <exception>
#include <GLFW/glfw3.h>
#include <string>

class Window
{
public:
	Window(int width, int height, std::string title);
	static void initGLContext();
	bool getWindowShouldClose();
	GLFWwindow* getGlfwWindow() { return glfwWindow; }
private:
	unsigned short width;
	unsigned short height;
	std::string title;
	GLFWwindow* glfwWindow;
};

