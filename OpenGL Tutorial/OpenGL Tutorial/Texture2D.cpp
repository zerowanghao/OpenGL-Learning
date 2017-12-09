#include "Texture2D.h"
#include "stb_image.h"

#include <iostream>


namespace Renderer
{
	Texture2D::Texture2D(const char *pTexFileName)
		:
		mShader(new Shader("texture.vs", "texture.fs"))
	{
		mVertexArray = new VertexArray();
		GLfloat vertices[] =
		{
			-0.5f, -0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f
		};
		mVertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);

		GLfloat texcoord[] =
		{
			0.0f, 0.0f,
			0.0f, 1.0f, 
			1.0f, 1.0f,
			1.0f, 0.0f
		};
		mVertexArray->addBuffer(new Buffer(texcoord, 4 * 2, 2), 1);

		GLushort indices[] = { 0, 1, 2, 2, 3, 0 }; 
		mIndexBuffer = new IndexBuffer(indices, 6);

		glGenTextures(1, &mTextureID);
		glBindTexture(GL_TEXTURE_2D, mTextureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	    int width, height, nrChannels;
		unsigned char *data = stbi_load(pTexFileName, &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);

		
	}

	Texture2D::~Texture2D()
	{
		delete mShader;
		delete mVertexArray;
		delete mIndexBuffer;
	}

	void Texture2D::draw() const
	{
		enable();
		mVertexArray->enable();
		mIndexBuffer->enable();
		mShader->enable();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		mShader->disable();
		mIndexBuffer->disable();
		mVertexArray->disable();
		disable();
	}

	void Texture2D::enable() const
	{
		glBindTexture(GL_TEXTURE_2D, mTextureID);
	}

	void Texture2D::disable() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}