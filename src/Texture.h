#ifndef TEXTURE_H
#define TEXTURE_H
#include <glad/glad.h>
#include <iostream>

class Texture
{
public:
    Texture(const char *path);
    
private:
    unsigned int m_texture{};
};

#endif