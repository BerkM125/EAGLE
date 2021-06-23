//PURELY DEMO FILLED FILE
//Main file for absolute freedom, all draw programming not opengl-core specifc should be done in here.
//Standard libraries
#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <vector>
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
extern std::vector<object3d> sceneassets;
object3d terrain;
object3d treeholder;
object3d treeholder2;
object3d rockholder;
object3d player;
std::vector<object3d> trees(300);
std::vector<object3d> rocks(300);

void glsetup (void) {
       
    terrain.importmesh3d("lowpolydesert.obj");
    treeholder.importmesh3d("AS12_9.obj");
    treeholder2.importmesh3d("tree.obj");
    rockholder.importmesh3d("rock.obj");
    player.importmesh3d("jet3.obj");
    int n = 0, n2 = 0;
    terrain.scaleobj3d(10);
    player.translateobj3f(-20000, 12000, 10000);
    player.scaleobj3d(0.25);
    srand (time(NULL));
    for (int i = 0; i < 300; i++) {
        n = rand() % terrain.vertexbuf.size()-1;
        n2 = rand() % terrain.vertexbuf.size()-1;
        trees[i].vertexbuf = (i % 2 == 0) ? treeholder.vertexbuf : treeholder2.vertexbuf;
        if(i%2==0)trees[i].scaleobj3d(24.0);
        else trees[i].scaleobj3d(4.0);
        rocks[i].vertexbuf = rockholder.vertexbuf;
        rocks[i].scaleobj3d(8.0);
        
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
    camx = player.xcoord+230;
    camy = player.ycoord+70.0;
    camz = player.zcoord;
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    terrain.rendermesh3d(60, 60, 60, 255, GL_TRIANGLES);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    terrain.rendermesh3d(247, 169, 42, 255, GL_TRIANGLES);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    player.rendermesh3d(60, 60, 60, 255, GL_TRIANGLES);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    player.rendermesh3d(240, 240, 240, 255, GL_TRIANGLES);
    for(int i = 0; i < 300; i++) {
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        rocks[i].rendermesh3d(155, 155, 155, 255, GL_TRIANGLE_STRIP);
        trees[i].rendermesh3d(100, 220, 100, 255, GL_TRIANGLES);
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        rocks[i].rendermesh3d(20, 20, 20, 255, GL_TRIANGLE_STRIP);
        trees[i].rendermesh3d(60, 200, 60, 255, GL_TRIANGLES);
    }
    //gridlines(2);
    return;
}