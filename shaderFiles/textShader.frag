#version 430 core

in vec2 Tex;

out vec4 FinalColor;
uniform sampler2D text;

void main()
{
    FinalColor = vec4(1.0, 1.0, 1.0, texture(text, Tex).r);
}