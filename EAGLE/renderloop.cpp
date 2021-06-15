/*
* MAIN RENDERING LOOP AND OPENGL PROCESS CPP FILE
* Contains the main OpenGL process and rendering function/loop.
* Callback functions and function references can be bound to GLUT via the main loop below.
*/
//Standard libraries
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
//External engine dependencies
#include "figureslib.hpp"
#include "cameralib.hpp"
#include "interfacelib.hpp"

sphere player(0, 0, 0, 2.0, 360, 360);
cylinder player2(0, 0, 8.0, 2.0, 10.0, 360);
cube player3(0, 0, 24.0, 4.0);
object3d model;
object3d ball;
object3d plane;
void demo (void) {
    /*player.rendervertexbuffer(180, 180, 255, 255, GL_LINE_STRIP);
    player2.rendervertexbuffer(180, 180, 255, 255, GL_TRIANGLE_STRIP);
    player3.rendervertexbuffer(180, 180, 255, 255, GL_TRIANGLE_STRIP);*/
    plane.rendervertexbuffer(255, 255, 255, 255, GL_POINTS);
    //ball.rendervertexbuffer(255, 255, 255, 255, GL_LINES);
    //gridlines(2);
    return;
}

void renderScene(void) {
    static int direction = 0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glLoadIdentity();
    rendercameraview();
    //DRAWING LOOP HERE: Add any drawing or graphics programming right below here before buffer swap
    demo();
    player.xcoord += 0.075;
    player2.xcoord += 0.1;
    player3.xcoord += 0.04;
    if (player.radius >= 3.0)
        direction = 1;
    if (player.radius <= 2.0)
        direction = 0;

    if (direction == 1) {
        player.radius -= 0.01;
        player2.radius -= 0.01;
        player3.cubewidth -= 0.01;
    }
    if (direction == 0) {
        player.radius += 0.01;
        player2.radius += 0.01;
        player3.cubewidth += 0.01;
    }
    Sleep(10);
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    plane.importvertex3dbuf("mercedes.obj", 1000000);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);
    glutCreateWindow("EAGLE");
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);
    //Freedom for interface control here, bind or unbind any of the following controls
    bindmousecontrol();
    bindarrowkeycontrol();
    bindnormalkeycontrol();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glAlphaFunc(GL_GREATER, 0.5);
    glEnable(GL_DEPTH_TEST | GL_BLEND | GL_ALPHA_TEST);
    glutMainLoop();
    return 1;
}