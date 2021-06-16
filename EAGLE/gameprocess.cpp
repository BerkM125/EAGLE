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

object3d car;
object3d ball;
object3d plane;

void glsetup (void) {
    car.importvertex3dbuf("mercedes.obj", 1000000);
    car.scaleobj3d(2.0);
    ball.importvertex3dbuf("ball.obj", 10000);
    ball.scaleobj3d(0.02);
    ball.translateobj3f(3.0, 10.0, 6.0);
}

void bindinterface (void) {
    bindmousecontrol();
    bindarrowkeycontrol();
    bindnormalkeycontrol();
}

void mainprocess (void) {
    ball.rendervertexbuffer(255, 255, 255, 255, GL_POINTS);
    car.rendervertexbuffer(180, 180, 255, 255, GL_POINTS);
    gridlines(2);
    return;
}
