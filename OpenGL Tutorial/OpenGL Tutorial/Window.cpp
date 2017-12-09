#include "Window.h"
#include "Common.h"

namespace Renderer {


	Window::Window(unsigned int pWidth, unsigned int pHeight, const char *pTitle)
		:
		mWidth(pWidth),
		mHeight(pHeight),
		mTitle(pTitle)
	{
		if (!init())
		{
			std::cout << "window init error." << std::endl;
		}
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(mWindow) == 1 ? true : false;
	}

	void Window::update() const
	{
		Input::processInput(mWindow);

		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}

	void Window::clear() const
	{
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::getMousePosition(double * x, double * y)
	{
		glfwGetCursorPos(mWindow, x, y);
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::init()
	{
		if (!glfwInit())
			return false;
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
		mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, nullptr, nullptr);
		if (!mWindow)
		{
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(mWindow);
		glfwSetWindowSizeCallback(mWindow, View::framebuffer_size_callback);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			return false;
		}

		return true;
	}
}
