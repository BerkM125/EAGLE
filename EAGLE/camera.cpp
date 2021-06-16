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
float angle = 0.0;
//rotation (yaw, pitch) sensitivity factors for mouse control
float yawsensitivity = 3.0;
float pitchsensitivity = 0.8;
//increment for camera movement
float movincrement = 0.5;
float angleincrement = 0.05;
//"look-at" pointers for camera, trio of x y z coords represents the point at which the camera "focuses" on
float lx = 2.0f, ly = 0.0f, lz = 0.0f;
//position of the camera in 3d space, when paired with look-at coordinates it forms 3d vector for camera position and focus
float camx = 5.0f, camy = 2.0f, camz = 0.0f;
//perspective variables
float viewlimit = 100000;
float viewmin = 1;
float yfov = 45;

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