//PURELY DEMO FILLED FILE
//Main file for absolute freedom, all draw programming not opengl-core specifc should be done in here.
//Standard libraries
#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
//External engine dependencies
#include "figureslib.hpp"
#include "cameralib.hpp"
#include "interfacelib.hpp"
#include "shaderslib.hpp"
//CROSS-FILE VALUES: Freely change these
char VERTEXSHADERFILE[BUFSIZE] = "samplevs.vert";
char FRAGMENTSHADERFILE[BUFSIZE] = "samplefg.frag";
char WINDOWTITLE[BUFSIZE] = "EAGLE Demo";
unsigned int DISPLAYFLAGS = GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA;
unsigned int ENABLEFLAGS = GL_DEPTH_TEST;
object3d terrain;
object3d treeholder;
object3d rockholder;
std::vector<object3d> trees(300);
std::vector<object3d> rocks(300);

void glsetup (void) {
    terrain.importmesh3d("mountainscene.obj");
    treeholder.importmesh3d("tree.obj");
    rockholder.importmesh3d("stone.obj");
    int n = 0, n2 = 0;
    terrain.scaleobj3d(17);
    for (int i = 0; i < 300; i++) {
        n = rand() % terrain.vertexbuf.size();
        n2 = rand() % terrain.vertexbuf.size()-1;
        trees[i].vertexbuf = treeholder.vertexbuf;
        rocks[i].vertexbuf = rockholder.vertexbuf;
        rocks[i].scaleobj3d(0.5);
        trees[i].translateobj3f(terrain.vertexbuf[n].xcoord, terrain.vertexbuf[n].ycoord, terrain.vertexbuf[n].zcoord);
        rocks[i].translateobj3f(terrain.vertexbuf[n2].xcoord, terrain.vertexbuf[n2].ycoord, terrain.vertexbuf[n2].zcoord);

    }
}

void bindinterface (void) {
    bindmousecontrol();
    bindarrowkeycontrol();
    bindnormalkeycontrol();
}

void mainprocess (void) {
    terrain.rendermesh3d(255, 255, 255, 255, GL_TRIANGLES);
    terrain.rendermesh3d(60, 60, 60, 255, GL_LINES);
    for(int i = 0; i < 300; i++) {
        rocks[i].rendermesh3d(97, 97, 97, 255, GL_TRIANGLE_STRIP);
        rocks[i].rendermesh3d(20, 20, 20, 255, GL_LINES);
        trees[i].rendermesh3d(100, 220, 100, 255, GL_TRIANGLES);
        trees[i].rendermesh3d(60, 200, 60, 255, GL_LINES);
    }
    //gridlines(2);
    return;
}