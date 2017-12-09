#include "Common.h"

namespace Input 
{
	void processInput(GLFWwindow *pWindow)
	{
		if (glfwGetKey(pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(pWindow, true);
		}
	}

};


namespace View
{
	void framebuffer_size_callback(GLFWwindow *pWindow, int pWidth, int pHeight)
	{
		glViewport(0, 0, pWidth, pHeight);
	}

};