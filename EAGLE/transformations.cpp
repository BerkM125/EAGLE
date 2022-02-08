//Standard libraries
#include <GL/freeglut.h>
#include <stdio.h>
#include <iostream>
//External engine dependencies
#include "vectorlib.hpp"
#include "cameralib.hpp"
#include "interfacelib.hpp"

void object3d::translateobj3f (GLfloat xmov, GLfloat ymov, GLfloat zmov) {
	xcoord += xmov;
	ycoord += ymov;
	zcoord += zmov;
	for(int n = 0; n < vertexbuf.size(); n++) {
		vertexbuf[n].xcoord += xmov;
		vertexbuf[n].ycoord += ymov;
		vertexbuf[n].zcoord += zmov;
	}
	for(int n = 0; n < uvbuf.size(); n++) {
		uvbuf[n].xcoord += xmov;
		uvbuf[n].ycoord += ymov;
	}
}

void object3d::scaleobj3d (GLfloat sf) {
	xcoord *= sf;
	ycoord *= sf;
	zcoord *= sf;
	for(int n = 0; n < vertexbuf.size(); n++) {
		vertexbuf[n].xcoord *= sf;
		vertexbuf[n].ycoord *= sf;
		vertexbuf[n].zcoord *= sf;
	}
	for(int n = 0; n < uvbuf.size(); n++) {
		uvbuf[n].xcoord *= (sf*texturetransformfactor);
		uvbuf[n].ycoord *= (sf*texturetransformfactor);
	}
}

void object3d::rotateobj3d(GLfloat angle) {
	GLfloat origx = vertexbuf[0].xcoord;
	GLfloat origy = vertexbuf[0].ycoord;
	GLfloat origz = vertexbuf[0].zcoord;
	translateobj3f(0 - origx, 0 - origy, 0 - origz);
	for (int n = 0; n < vertexbuf.size(); n++) {
		GLfloat xprime = vertexbuf[n].xcoord * cosf(angle) - vertexbuf[n].zcoord * sinf(angle);
		GLfloat zprime = vertexbuf[n].xcoord * sin(angle) + vertexbuf[n].zcoord * cosf(angle);
		vertexbuf[n].xcoord = xprime;
		vertexbuf[n].zcoord = zprime;
	}
	translateobj3f(origx - vertexbuf[0].xcoord, origy - vertexbuf[0].ycoord, origz - vertexbuf[0].zcoord);
}