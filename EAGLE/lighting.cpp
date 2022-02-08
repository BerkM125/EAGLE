//Test file; ignore for now
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <thread>
//External engine dependencies
#include "vectorlib.hpp"
#include "cameralib.hpp"
#include "interfacelib.hpp"
#include "shaderslib.hpp"
#include "lightinglib.hpp"

void applylightingflags (void) {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
}

void initlightsource (vertex3d point) {
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 100.0 };
    GLfloat light_position[] = { point.xcoord*0.01f, point.ycoord, point.zcoord*0.01f, 1.0 };
    GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat dim_light[] = {0.3f, 0.3f, 0.3f, 1.0f};

    glShadeModel (GL_FLAT);
    //glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1.0f);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, dim_light);
    glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1.0f);
    glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
}