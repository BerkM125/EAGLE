/*
* CAMERA FUNCTIONALITY IN 3D SPACE CPP FILE
* Contains variables and functions pertaining to the functionality
* of many aspects of the engine camera. External declarations of 
* the contained variables and functions are located in "cameralib.hpp".
*/
//Standard libraries
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
//External engine dependencies
#include "figureslib.hpp"
#include "cameralib.hpp"
#include "interfacelib.hpp"
//angle variable representing camera X and Z vectors in terms of degrees
float angle = 5.0;
//rotation (yaw, pitch) sensitivity factors for mouse control
float yawsensitivity = 3.0;
float pitchsensitivity = 0.8;
//increment for camera movement
float movincrement = 5.0;
float angleincrement = 0.05;
//"look-at" pointers for camera, trio of x y z coords represents the point at which the camera "focuses" on
float lx = 2.0f, ly = 0.0f, lz = 0.0f;
//position of the camera in 3d space, when paired with look-at coordinates it forms 3d vector for camera position and focus
float camx = 5.0f, camy = 2.0f, camz = 0.0f;
//perspective variables
float viewlimit = 100000;
float viewmin = 1;
float yfov = 45;

GLfloat swidth = 700;
GLfloat sheight = 700;
extern object3d plane, car, ball;

void rendercameraview (void) {
    gluLookAt(camx, camy, camz, camx + lx, camy + ly, camz + lz, 0.0, 1.0f, 0.0);
}

void changeSize(int w, int h) {
    if (h == 0)
        h = 1;
    float ratio = 1.0 * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(yfov, ratio, viewmin, viewlimit);
    glMatrixMode(GL_MODELVIEW);
    swidth = w;
    sheight = h;
}

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