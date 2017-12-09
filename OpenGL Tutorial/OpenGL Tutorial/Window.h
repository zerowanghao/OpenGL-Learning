#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>



namespace Renderer {

	class Window
	{
	public:
		Window(unsigned int pWidth, unsigned int pHeight, const char *pTitle);
		~Window();

	public:
		bool closed() const;
		void update() const;
		void clear() const;
		void getMousePosition(double *x, double *y);

	private:
		bool init();

	private:
		unsigned int mWidth;
		unsigned int mHeight;
		const char *mTitle;
		GLFWwindow *mWindow;
	};

}
#endif // !_WINDOW_H_
