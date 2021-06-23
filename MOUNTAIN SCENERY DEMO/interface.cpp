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

extern object3d player;

void mainmousecontrol(int xx, int yy) {
    //Put any mouse code and controls you want in here, the code below is simply an example
    mousecameracontrol(xx, yy);
}

void mainnormalkeycontrol(unsigned char key, int xx, int yy) {
    //Put any normal key code and controls you want in here, the code below is simply an example
    //normalkeycameracontrol(key, xx, yy);
    if (key == 'w') { // W
        player.translateobj3f(lx * movincrement, 0, lz * movincrement);
    }
    if (key == 's') { // S
        player.translateobj3f(-lx * movincrement, 0, -lz * movincrement);
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

void mainarrowkeycontrol(int key, int xx, int yy) {
    //Put any arrow key involving code and controls you want in here, the code below is simply an example
    //arrowkeycameracontrol(key, xx, yy);
    switch (key) {
    case GLUT_KEY_UP:
        player.translateobj3f(0, movincrement, 0);
        break;
    case GLUT_KEY_DOWN:
        player.translateobj3f(0, -movincrement, 0);
        break;
    }
}

void bindmousecontrol (void) {
    glutMotionFunc(mainmousecontrol);
}

void bindarrowkeycontrol (void) {
    glutSpecialFunc(mainarrowkeycontrol);
}

void bindnormalkeycontrol (void) {
    glutKeyboardFunc(mainnormalkeycontrol);
}