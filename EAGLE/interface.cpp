//Standard libraries
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
//External engine dependencies
#include "figureslib.hpp"
#include "cameralib.hpp"
#include "interfacelib.hpp"

GLfloat swidth = 700;
GLfloat sheight = 700;

void mousecameracontrol(int xx, int yy) {
    static GLfloat px = 0;
    static GLfloat py = 0;
    GLfloat x1 = xx / (GLfloat)(swidth / 2) - 1.0;
    GLfloat y1 = yy / (GLfloat)(sheight / 2) - 1.0;
    if (px == 0 && py == 0) {
        px = x1;
        py = y1;
    }
    else {
        angle += (x1 - px) * yawsensitivity;
        lx = sin(angle);
        lz = -cos(angle);
        ly += (py - y1) * pitchsensitivity;
        px = x1;
        py = y1;
    }
    return;
}

void normalkeycameracontrol(unsigned char key, int xx, int yy) {
    if (key == 'w') { // W
        camx += lx * movincrement;
        camz += lz * movincrement;
    }
    if (key == 's') { // S
        camx -= lx * movincrement;
        camz -= lz * movincrement;
    }
    if (key == 'd') { // D
        angle += angleincrement;
        lx = sin(angle);
        lz = -cos(angle);
    }
    if (key == 'a') { // A
        angle -= angleincrement;
        lx = sin(angle);
        lz = -cos(angle);
    }
    if (key == 27)
        exit(0);
}

void arrowkeycameracontrol(int key, int xx, int yy) {
    switch (key) {
    case GLUT_KEY_UP:
        camy += movincrement;
        break;
    case GLUT_KEY_DOWN:
        camy -= movincrement;
        break;
    }
}

void bindmousecontrol (void) {
    glutMotionFunc(mousecameracontrol);
}

void bindarrowkeycontrol (void) {
    glutSpecialFunc(arrowkeycameracontrol);
}

void bindnormalkeycontrol (void) {
    glutKeyboardFunc(normalkeycameracontrol);
}