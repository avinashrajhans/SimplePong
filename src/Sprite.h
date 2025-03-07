#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include "Shader.h"

class Sprite
{
public:
    Sprite();
    ~Sprite();
    void draw();

protected:
    unsigned int m_VAO;
    unsigned int m_VBO;
    unsigned int m_EBO;
    Shader m_shader;    
};

#endif