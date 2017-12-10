#ifndef _TEXTURE_2D_H_
#define _TEXTURE_2D_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "VertexArray.h"
#include "Buffer.h"
#include "IndexBuffer.h"


namespace Renderer
{

	class Texture2D
	{
	public:
		Texture2D(const char *pTexFileName);
		~Texture2D();

		GLuint mTextureID;

	public:
		void enable() const;
		void disable() const;

		void draw() const;

	protected:
		Shader *mShader;
		VertexArray *mVertexArray;
		IndexBuffer *mIndexBuffer;
	};
}

#endif
