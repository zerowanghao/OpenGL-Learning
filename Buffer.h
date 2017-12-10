#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Renderer 
{

	class Buffer
	{
	public:
		Buffer(GLfloat *data, GLsizei count, GLuint componentCount);
		~Buffer();

	public:
		void enable() const;
		void disable() const;

		inline GLuint getComponentCount() const { return mComponentCount; }

	private:
		GLuint mBufferID;
		GLuint mComponentCount;
	};
};

