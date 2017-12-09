#include "SimpleRenderer2D.h"
#include "Renderable2D.h"

namespace Renderer 
{

	void SimpleRenderer2D::submit(const Renderable2D * pRenderable2D)
	{
		mRendererDeque.push_back(pRenderable2D);
	}

	void SimpleRenderer2D::flush()
	{
		while (!mRendererDeque.empty())
		{
			const Renderable2D *renderable2D = mRendererDeque.front();
			renderable2D->getVAO()->enable();
			renderable2D->getIBO()->enable();

			renderable2D->getShader().enable();
			glDrawElements(GL_TRIANGLES, renderable2D->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);

			renderable2D->getIBO()->disable();
			renderable2D->getVAO()->disable();

			mRendererDeque.pop_front();
		}
	}

	SimpleRenderer2D::SimpleRenderer2D()
	{

	}


	SimpleRenderer2D::~SimpleRenderer2D()
	{

	}
}
