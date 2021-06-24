/*
* MAIN RENDERING LOOP AND OPENGL PROCESS CPP FILE
* Contains the main OpenGL process and rendering function/loop.
* Callback functions and function references can be bound to GLUT via the main loop below.
*/
//Standard libraries
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
//External engine dependencies
#include "figureslib.hpp"
#include "cameralib.hpp"
#include "interfacelib.hpp"
#include "shaderslib.hpp"
extern char WINDOWTITLE[BUFSIZE];
extern char VERTEXSHADERFILE[BUFSIZE];
extern char FRAGMENTSHADERFILE[BUFSIZE];
extern unsigned int DISPLAYFLAGS;
extern unsigned int ENABLEFLAGS;

extern void glsetup(void);
extern void bindinterface(void);
extern void mainprocess(void);  
extern void eventhandler(void);
GLuint vs = 0;
GLuint fs = 0;
GLuint shaderprogram = 0;
void renderScene(void) {
    static int direction = 0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    rendercameraview();
    //DRAWING LOOP HERE: Add any drawing or graphics programming right below here before buffer swap
    mainprocess();
    eventhandler();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glsetup();
    glutInit(&argc, argv);
    glutInitDisplayMode(DISPLAYFLAGS);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);
    glutCreateWindow(WINDOWTITLE);
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);
    //Freedom for interface control here, bind or unbind any of the following controls
    bindinterface();
      GLenum err = glewInit();
    if (err != GLEW_OK)
      exit(1); // or handle the error in a nicer way
    if (!GLEW_VERSION_2_1)  // check that the machine supports the 2.1 API.
      exit(1); 
    initshaders(&vs, &fs, &shaderprogram, FRAGMENTSHADERFILE, VERTEXSHADERFILE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glAlphaFunc(GL_GREATER, 0.5);
    glEnable(ENABLEFLAGS);
    glDepthFunc(GL_LESS); 

    glutMainLoop();
    return 1;
}