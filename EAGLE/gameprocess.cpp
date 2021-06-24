//PURELY DEMO FILLED FILE
//Main file for absolute freedom, all draw programming not opengl-core specifc should be done in here.
//Standard libraries
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <thread>
//External engine dependencies
#include "figureslib.hpp"
#include "cameralib.hpp"
#include "interfacelib.hpp"
#include "shaderslib.hpp"
//CROSS-FILE VALUES: Freely change these
char VERTEXSHADERFILE[BUFSIZE] = "samplevs.vert";
char FRAGMENTSHADERFILE[BUFSIZE] = "samplefg.frag";
char WINDOWTITLE[BUFSIZE] = "EAGLE Demo";
unsigned int DISPLAYFLAGS = GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA;
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

void eventhandler(void) {
    return;
}

void mainprocess (void) {
    return;
}