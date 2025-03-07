#ifndef BSD_H
#define BSD_H
#include <ft2build.h>
#include FT_FREETYPE_H
#include <glm/glm.hpp>
#include <map>
#include "Shader.h"
#include <string>
#include <iostream>

struct Character
{
    unsigned int TextureID;
    glm::ivec2 Size;
    glm::ivec2 Bearing;
    unsigned int Advance;
};


class BSD
{
public:
    BSD();
    ~BSD();
    void renderText(std::string text, float x, float y);
    // void printShaderID()
    // {
    //     std::cout << "The shader ID is " << m_shader_ID << '\n';
    // }
private:
    unsigned int m_VAO;
    unsigned int m_VBO;
    FT_Face m_face;
    std::map<char, Character> m_characters;
    void textLoading();
    void loadCharacters();
    Shader m_shader;
};

#endif