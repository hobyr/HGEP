#version 460 core

in vec4 outColor;

uniform vec4 ourColor;

out vec4 outputColor;

void main()
{
  outputColor = outColor + ourColor;
}

