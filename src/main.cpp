/* Created on 04/19/2023 22:02:20
 * main.cpp
 * Author: Hoby Ratefimandimby
 *
 */

#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main(int argc, char *argv[])
{
  std::cout << "Hello world!" << std::endl;

  // Initialize GLFW
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);;

  // Create an application window where we can draw
  GLFWwindow* window = glfwCreateWindow(800, 600, "My new OpenGL Window", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  // Create an OpenGL context
  glfwMakeContextCurrent(window);

  // Initialize GLAD to make OpenGL functions available to use
  if (!gladLoadGL(glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // Set viewport to proper window size
  glViewport(0, 0, 800, 600);


  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  // render loop
  while(!glfwWindowShouldClose(window)) {

    // input
    processInput(window);


    // Rendering commands here
    glClear(GL_COLOR_BUFFER_BIT);

    // check and call events and swap the buffers => no flickering between frames
    glfwSwapBuffers(window);
    glfwPollEvents();
    // When window is resized, resize viewport accordingly
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  }

  glfwTerminate();
  return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}


void processInput(GLFWwindow* window) {
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  } else if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
    GLfloat bkColor[4];
    glGetFloatv(GL_COLOR_CLEAR_VALUE, bkColor);
    glClearColor(0.2f, bkColor[1]+0.1f, 0.3f, 1.0f);
  } else if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
    GLfloat bkColor[4];
    glGetFloatv(GL_COLOR_CLEAR_VALUE, bkColor);
    glClearColor(0.2f, bkColor[1]-0.1f, 0.3f, 1.0f);
  }else if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
    GLfloat bkColor[4];
    glGetFloatv(GL_COLOR_CLEAR_VALUE, bkColor);
    glClearColor(0.2f, 0.3f, bkColor[2]+0.1f, 1.0f);
  } else if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
    GLfloat bkColor[4];
    glGetFloatv(GL_COLOR_CLEAR_VALUE, bkColor);
    glClearColor(0.2f, 0.3f, bkColor[2]-0.1f, 1.0f);
  }

}
