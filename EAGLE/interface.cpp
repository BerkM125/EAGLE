/*
* EXTERNAL INTERFACING CPP FILE
* Contains functions pertaining to and providing functionality for
* interfaces, such as keyboard and mouse. Also contains sample player movement
* and camera movement functions that can be bound to the main OpenGL process. 
*/
//Standard libraries
#include <GL/freeglut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
//External engine dependencies
#include "vectorlib.hpp"
#include "cameralib.hpp"
#include "interfacelib.hpp"

void mainmousecontrol(int xx, int yy) {
    //Put any mouse code and controls you want in here, the code below is simply an example
    mousecameracontrol(xx, yy);
}

void mainnormalkeycontrol(unsigned char key, int xx, int yy) {
    //Put any normal key code and controls you want in here, the code below is simply an example
    normalkeycameracontrol(key, xx, yy);
}

void mainarrowkeycontrol(int key, int xx, int yy) {
    //Put any arrow key involving code and controls you want in here, the code below is simply an example
    //arrowkeycameracontrol(key, xx, yy);
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
    glutMotionFunc(mainmousecontrol);
}

void bindarrowkeycontrol (void) {
    glutSpecialFunc(mainarrowkeycontrol);
}

void bindnormalkeycontrol (void) {
    glutKeyboardFunc(mainnormalkeycontrol);
}