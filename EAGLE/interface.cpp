/*
* EXTERNAL INTERFACING CPP FILE
* Contains functions pertaining to and providing functionality for
* interfaces, such as keyboard and mouse. Also contains sample player movement
* and camera movement functions that can be bound to the main OpenGL process. 
*/
//Standard libraries
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
//External engine dependencies
#include "figureslib.hpp"
#include "cameralib.hpp"
#include "interfacelib.hpp"

GLfloat swidth = 700;
GLfloat sheight = 700;
extern sphere player;
extern cylinder player2;
extern cube player3;
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
    if (key == 'p') {
        player.renderfigure(180, 180, 255, 255, GL_LINE_STRIP);
        player2.renderfigure(180, 180, 255, 255, GL_LINE_STRIP);
        player3.renderfigure(180, 180, 255, 255, GL_TRIANGLE_STRIP);
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