//Standard libraries
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
//External engine dependencies
#include "figureslib.hpp"
#include "cameralib.hpp"
#include "interfacelib.hpp"

void demo (void) {
    cylinder maincylinder(2.0, 12.0, 30.0, 0.0, 0.0, 180);
    sphere mainsphere(30.0, 7.0, 0.0, 2.0, 180, 180);
    maincylinder.drawCylinder(200, 200, 200, GL_TRIANGLE_STRIP);
    mainsphere.rendersphere(100, 100, 100, GL_LINE_STRIP);
    mainsphere.rendersphere(200, 200, 200, GL_POLYGON);
    gridlines(2);
    return;
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    rendercameraview();
    //DRAWING LOOP HERE: Add any drawing or graphics programming right below here before buffer swap
    demo();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
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
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 1;
}