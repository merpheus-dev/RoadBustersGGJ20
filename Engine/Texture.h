#pragma once
class Texture {
public:
	int width;
	int height;
	unsigned char* data;
	unsigned int texture_id;
	int normal_channel_count;
	bool isValid = false;
};