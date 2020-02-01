#pragma once
#include <GL/glew.h>
#include <glfw3.h>
#include "Texture.h"
#include "../Utils/Macro.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
class AssetDatabase {
public:
	static Texture* LoadTexture(const char* file_name) {
		Texture* texture = new Texture();
		texture->data = stbi_load(file_name, &texture->width, &texture->height,
			&texture->normal_channel_count, 0);

		if (texture->data) {
			glGenTextures(1, &texture->texture_id);
			glBindTexture(GL_TEXTURE_2D, texture->texture_id);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->width, texture->height, 0,
				GL_RGB, GL_UNSIGNED_BYTE, texture->data);

			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			PRINT("Failed to load texture");
		}
		stbi_image_free(texture->data);
		texture->isValid = true;
		return texture;
	}
};
