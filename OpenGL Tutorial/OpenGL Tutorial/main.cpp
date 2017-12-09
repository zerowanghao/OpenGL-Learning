#include "Window.h"
#include "SimpleRenderer2D.h"
#include "Renderable2D.h"

#include "Texture2D.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;
const char *WINDOW_TITLE = "OpenGL Engine";

int main()
{
	using namespace Renderer;

	Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	
#if 0
	SimpleRenderer2D *sRenderer2D = new SimpleRenderer2D();
	Shader shader("triangle.vs", "triangle.fs");
	Renderable2D *renderable2d = new Renderable2D(glm::vec3(0.0f), glm::vec2(0.5), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f), shader);
#else
	Texture2D mTex("texture_01.jpg");

#endif

	while (!window.closed())
	{

		window.clear();

#if 0
		double x, y;
		window.getMousePosition(&x, &y);

		renderable2d->getShader().setVec3("cursor_position", glm::vec3(x / 800.0f, y / 600.0f, 1.0f));
		sRenderer2D->submit(renderable2d);
		sRenderer2D->flush();
#else 
		mTex.draw();

#endif

		window.update();
	}

	
	
	return 0;
}
