//PURELY DEMO FILLED FILE
//Main file for absolute freedom, all draw programming not opengl-core specifc should be done in here.
//Standard libraries
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
//External engine dependencies
#include "figureslib.hpp"
#include "cameralib.hpp"
#include "interfacelib.hpp"

//CROSS-FILE VALUES: Freely change these
char WINDOWTITLE[BUFSIZE] = "EAGLE Demo";
unsigned int DISPLAYFLAGS = GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA;
unsigned int ENABLEFLAGS = GL_DEPTH_TEST | GL_BLEND | GL_ALPHA_TEST;

void glsetup (void) {
}

void bindinterface (void) {
    bindmousecontrol();
    bindarrowkeycontrol();
    bindnormalkeycontrol();
}

void mainprocess (void) {
    return;
}