#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Renderer
{
	class IndexBuffer
	{
	public:
		IndexBuffer(GLushort *pData, GLsizei pCount);
		~IndexBuffer();

	public:
		inline GLsizei getCount() const { return mCount; }
		void enable() const;
		void disable() const;

	private:
		GLuint mIndexBufferID;
		GLsizei mCount;
	};

};