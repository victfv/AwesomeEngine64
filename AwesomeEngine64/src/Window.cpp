#include "Window.h"

Window::Window(int width, int height, std::string title)
{
	this->width = width;
	this->height = height;
	this->title = title;
	glfwWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (!glfwWindow)
	{
		glfwTerminate();
		throw new std::exception("This shit failed!");
	}
	glfwMakeContextCurrent(glfwWindow);
}

void Window::initGLContext()
{
	if (!glfwInit())
		throw new std::exception("You fucked up!");
}

bool Window::getWindowShouldClose()
{
	return bool(glfwWindowShouldClose(glfwWindow));
}
