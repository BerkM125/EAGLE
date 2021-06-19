//PURELY DEMO FILLED FILE
//Main file for absolute freedom, all draw programming not opengl-core specifc should be done in here.
//Standard libraries
#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
//External engine dependencies
#include "figureslib.hpp"
#include "cameralib.hpp"
#include "interfacelib.hpp"
#include "shaderslib.hpp"
//CROSS-FILE VALUES: Freely change these
char VERTEXSHADERFILE[BUFSIZE] = "samplevs.vert"; //Put vertex shader file name here, this is just a placeholder
char FRAGMENTSHADERFILE[BUFSIZE] = "samplefg.frag"; //Put fragment shader file name here, this is just a placeholder
char WINDOWTITLE[BUFSIZE] = "EAGLE";
unsigned int DISPLAYFLAGS = GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA; //These are automatic flags, you can add on to the list
unsigned int ENABLEFLAGS = GL_DEPTH_TEST;

void glsetup (void) {
    return;
}

void bindinterface (void) {
    bindmousecontrol();
    bindarrowkeycontrol();
    bindnormalkeycontrol();
    return;
}

void mainprocess (void) {
    return;
}