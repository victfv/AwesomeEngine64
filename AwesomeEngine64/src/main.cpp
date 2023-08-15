#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "MemoryPoolAllocator.h"

#define WORLD_SIZE 4503599627370496

int main()
{
	Window::initGLContext();
	Window myWindow(640, 480, "Poop");

	MemoryPoolAllocator myAllocator(1000000, 500);

	while (!myWindow.getWindowShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(myWindow.getGlfwWindow());
		glfwPollEvents();
	}
}