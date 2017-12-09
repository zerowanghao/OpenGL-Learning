#pragma once

#include <glad/glad.h>

#include <vector>
#include "Buffer.h"

namespace Renderer
{
	class VertexArray
	{
	private:
		GLuint mVertexArrayID;
		std::vector<Buffer*> mBuffers;
	public:
		VertexArray();
		~VertexArray();


	public:
		void enable() const;
		void disable() const;

		void addBuffer(Buffer * pBuffer, GLuint pIndex);
	};

};
