#include "IndexBuffer.h"


namespace Renderer
{
	IndexBuffer::IndexBuffer(GLushort *pData, GLsizei pCount)
		:
	mCount(pCount)
	{
		glGenBuffers(1, &mIndexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, pCount * sizeof( GLushort ), pData, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &mIndexBufferID);
	}

	void Renderer::IndexBuffer::enable() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBufferID);
	}

	void Renderer::IndexBuffer::disable() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

};