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

extern object3d plane, car, ball;

void mainmousecontrol(int xx, int yy) {
    //Put any mouse code and controls you want in here, the code below is simply an example
}

void mainnormalkeycontrol(unsigned char key, int xx, int yy) {
    //Put any normal key code and controls you want in here, the code below is simply an example
}

void mainarrowkeycontrol(int key, int xx, int yy) {
    //Put any arrow key involving code and controls you want in here, the code below is simply an example
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