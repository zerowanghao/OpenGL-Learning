#include "VertexArray.h"



namespace Renderer
{


	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &mVertexArrayID);
	}


	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &mVertexArrayID);
		for (size_t i = 0; i < mBuffers.size(); i++)
		{
			delete mBuffers[i];
		}
	}

	void VertexArray::enable() const
	{
		glBindVertexArray(mVertexArrayID);
	}

	void VertexArray::disable() const
	{
		glBindVertexArray(0);
	}

	void VertexArray::addBuffer(Buffer * pBuffer, GLuint pIndex)
	{
		enable();
		pBuffer->enable();

		glEnableVertexAttribArray(pIndex);
		glVertexAttribPointer(pIndex, pBuffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
		
		mBuffers.push_back(pBuffer);

		pBuffer->disable();
		disable();
	}

};
