//PURELY DEMO FILLED FILE
//Main file for absolute freedom, all draw programming not opengl-core specifc should be done in here.
//Standard libraries
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
//CROSS-FILE VALUES: Freely change these
char VERTEXSHADERFILE[BUFSIZE] = "samplevs.vert";
char FRAGMENTSHADERFILE[BUFSIZE] = "samplefg.frag";
char WINDOWTITLE[BUFSIZE] = "EAGLE";
unsigned int DISPLAYFLAGS = GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA | GLUT_ALPHA | GLUT_MULTISAMPLE;
unsigned int ENABLEFLAGS = GL_DEPTH_TEST;

//Sample variables
GLuint renderlist;
GLuint maintexture;

//Sample demo glsetup, utilizes lighting, texturing, and a legacy display list
void glsetup (void) {
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);
    //glFrontFace(GL_CW);
    //initlightsource(vertex3d(1.0, 1.0, 1.0));

    renderlist = glGenLists(1);
    
    glNewList(renderlist, GL_COMPILE);
    /*glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    
    glBindTexture(GL_TEXTURE_2D, maintexture);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);*/
    gridlines(2);
    //glDisable(GL_TEXTURE_2D);
    glEndList();
}

void bindinterface (void) {
    bindmousecontrol();
    bindarrowkeycontrol();
    bindnormalkeycontrol();
}

void eventhandler(void) {
}

void mainprocess (void) {
    glCallList(renderlist);
    glFlush();
}