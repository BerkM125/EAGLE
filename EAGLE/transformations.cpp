//Standard libraries
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
//External engine dependencies
#include "figureslib.hpp"
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
}