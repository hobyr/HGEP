#version 460 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

uniform vec4 posOffset;

out vec4 outColor;

void main()
{
  gl_Position = vec4(position.x, position.y, position.z, 1.0f) + posOffset;
  outColor = color;
}
