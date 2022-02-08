//Standard libraries
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <stdio.h>
#include <iostream>
//External engine dependencies
#include "vectorlib.hpp"
#include "cameralib.hpp"
#include "shaderslib.hpp"
#include "interfacelib.hpp"
#define WIDTH 64

char vertexshader[256];
char fragmentshader[256];
void bindvertexbuffer(GLuint* vao, GLuint* vbo, GLfloat *vertexbuf) {
    //Vertex buffer
    glGenBuffers(1, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexbuf), vertexbuf, GL_STATIC_DRAW);
    //Vertex array
    glGenVertexArrays(1, vao);
    glBindVertexArray(*vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

void initshaders(GLuint* vs, GLuint* fs, GLuint* shaderprogram, const char* fragshader, const char* vertshader) {
    //Load the shaders
    loadvertexshader(vertshader);
    loadfragmentshader(fragshader);
    //For shader source, put the loaded shader code into const char buffers
    const char* vertex_shader = vertexshader;
    const char* fragment_shader = fragmentshader;
    *vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(*vs, 1, &vertex_shader, NULL);
    glCompileShader(*vs);
    *fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(*fs, 1, &fragment_shader, NULL);
    glCompileShader(*fs);

    *shaderprogram = glCreateProgram();
    glAttachShader(*shaderprogram, *fs);
    glAttachShader(*shaderprogram, *vs);
    glLinkProgram(*shaderprogram);
}

void loadvertexshader(const char* fn) {
    int n = 0;
    char t = ' ';
    FILE* fp = fopen(fn, "r+");
    if (!fp) {
        std::cout << "No such file, shader cannot be loaded.\n";
        return;
    }
    t = fgetc(fp);
    while (t != EOF) {
        vertexshader[n] = t;
        t = fgetc(fp);
        n++;   
    }
    vertexshader[n] = '\0';
    fclose(fp);
    std::cout << "VERTEX SHADING: \n" << vertexshader << "\n";
    return;
}

void loadfragmentshader(const char* fn) {
    int n = 0;
    char t = ' ';
    FILE* fp = fopen(fn, "r+");
    if (!fp) {
        std::cout << "No such file, shader cannot be loaded.\n";
        return;
    }
    while (t != EOF) {
        t = getc(fp);
        fragmentshader[n] = t;
        n++;
    }
    fragmentshader[n-1] = '\0';
    fclose(fp);
    std::cout << "FRAGMENT SHADING: \n" << fragmentshader << "\n";
    return;
}