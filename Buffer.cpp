#include "Buffer.h"



namespace Renderer
{

	Buffer::Buffer(GLfloat *pData, GLsizei pCount, GLuint pComponentCount)
		:
		mComponentCount(pComponentCount)
	{
		glGenBuffers(1, &mBufferID);
		glBindBuffer(GL_ARRAY_BUFFER, mBufferID);
		glBufferData(GL_ARRAY_BUFFER, pCount * sizeof(GLfloat), pData, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}


	Buffer::~Buffer()
	{
		glDeleteBuffers(1, &mBufferID);
	}

	void Buffer::enable() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, mBufferID);
	}
	
	void Buffer::disable() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}
