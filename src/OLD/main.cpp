/*
 * This is a practice project where I try to create a game engine.
 * I have several libraries I want to use for this project:
 * - OpenGL using GLFW and GLAD
 * - OpenDynamicsEngine for physics
 *
 *
 *   Right now, I'm trying to get used to the OpenGL programming (graphics programming).
 *   I've drawn the circle and now moving it using OpenGL Uniforms.
 *
 *   Using also CMake to compile the project. Have to write a post on how I made that work.
 */

#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "shader.h"

int main(int argc, char *argv[])
{ if (!glfwInit())
    {
        // Initialization failed
        exit(EXIT_FAILURE);
    }

    GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Practice", NULL, NULL);
    if (!window)
    {
        // Window or OpenGL context creation failed std::cout << "Error creating window!" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0) 
    {
        std::cerr << "Failed to initialize OpenGL context" << std::endl;
        exit(EXIT_FAILURE);
    }

//    // Successfully loaded OpenGL?
//    std::cout << "Loaded OpenGL " << GLAD_VERSION_MAJOR(version)
//              << "." << GLAD_VERSION_MINOR(version) << std::endl;
//
//    // Max number of vertex attributes
//    GLint nrAttributes;
//    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
//    std::cout << "Max. no. of vertex attributes: " << nrAttributes << std::endl;

    //------------------------------
    //          OpenGL section
    //------------------------------
    //------------------------------
    //       Shaders & Program
    //------------------------------
    Shader shaderProgram("./shader.vert", "./shader.frag");

    //------------------------------
    //      Vertices & Buffers
    //------------------------------
    // Create vertices
    const float firstTriangle[] = {
       -0.5f, -0.433f, 0.0f, 1.0f, 
        1.0f,  0.0f, 0.0f, 1.0f,
        0.5f, -0.433f, 0.0f, 1.0f,  
        0.0f,  1.0f, 0.0f, 1.0f,
        0.0f,  0.433f, 0.0f, 1.0f,  
        0.0f,  0.0f, 1.0f, 1.0f,
    };

    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
    // position attribute
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(4 * sizeof(float)));
    glEnableVertexAttribArray(1);


    //--------------------------------------
    //              Main Loop
    //--------------------------------------
    while (!glfwWindowShouldClose(window)) 
    {
        glfwPollEvents();

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //--------------------------------------
        //      Uniforms
        //--------------------------------------
        shaderProgram.use();
#if 1
        double timeValue = glfwGetTime();
        double redValue    = std::sin(timeValue + 3.14159f);
        double greenValue  = std::cos(timeValue + 3.14159f);
        double blueValue   = std::sin(timeValue + 3.14159f);
//        double x = std::sin(timeValue + 3.14159f);
//        double y = std::cos(timeValue + 3.14159f);
        GLint vertexColorLocation = glGetUniformLocation(shaderProgram.ID, "ourColor");
        glUniform4f(vertexColorLocation, redValue, greenValue, blueValue, 1.0f);
//        GLint vertexPosLocation = glGetUniformLocation(shaderProgram.ID, "posOffset");
//        glUniform4f(vertexPosLocation, x, 0.0f, 0.0f, 1.0f);
#endif
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);

    return 0;
}
