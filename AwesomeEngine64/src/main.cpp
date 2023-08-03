#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "main.h"

int main()
{
	Window::initGLContext();
	Window myWindow(640, 480, "Poop");
	while (!myWindow.getWindowShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(myWindow.getGlfwWindow());
		glfwPollEvents();
	}
}