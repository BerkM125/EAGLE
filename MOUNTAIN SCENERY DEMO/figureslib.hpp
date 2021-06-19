/*
* 3D FIGURES + OBJECTS HEADER FILE
* Contains declarations of all three-dimensional-based 
* classes and functions involving those classes. Definitions
* and implementations are located in "figures.cpp".
*/
#pragma once
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#define LIMIT 360
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923
#define BUFSIZE 32
#define GENTYPE_VBUF 1
#define GENTYPE_DRAW 2

class color4ub {
public:
	GLubyte R = 255;
	GLubyte G = 255;
	GLubyte B = 255;
	GLubyte A = 255;
	color4ub(GLubyte red = 255, GLubyte blue = 255, GLubyte green = 255, GLubyte alpha = 255) {
		R = red;
		B = blue;
		G = green;
		A = alpha;
	}
	void setcolor4ub(GLubyte red, GLubyte blue, GLubyte green, GLubyte alpha);
};

class vertex2d {
public:
	GLfloat xcoord;
	GLfloat ycoord;
};

class vertex3d {
public:
	GLfloat xcoord;
	GLfloat ycoord;
	GLfloat zcoord;
	vertex3d(GLfloat xcrd = 0, GLfloat ycrd = 0, GLfloat zcrd = 0) {
		xcoord = xcrd;
		ycoord = ycrd;
		zcoord = zcrd;
	}
	void setvertex3d(GLfloat xcrd, GLfloat ycrd, GLfloat zcrd);
};

class object3d {
public:
	//Not using a vertex3d object here for the origin coordinates for reasons of convenience and simplicity
	GLfloat xcoord;
	GLfloat ycoord;
	GLfloat zcoord;
	color4ub objcolor;
	std::vector<vertex2d> uvbuf;
	std::vector<vertex3d> vertexbuf; //not to be confused with a VBO or VAO
	std::vector<vertex3d> normalsbuf;
	void pushvertex3f(GLfloat xcoord, GLfloat ycoord, GLfloat zcoord);
	void translateobj3f (GLfloat xmov, GLfloat ymov, GLfloat zmov);
	void scaleobj3d (GLfloat sf);
	void importvertex3dbuf(const char* fn);
	void importmesh3d(const char* fn);
	void rendermesh3d(GLubyte R, GLubyte G, GLubyte B, GLubyte A, GLenum primtype);
	void rendervertexbuffer(GLenum primtype);
	void rendervertexbuffer(GLubyte R, GLubyte G, GLubyte B, GLubyte A, GLenum primtype);
};

class cone : public object3d {
public:
	GLfloat radius;
	GLfloat height;
	GLfloat vertexnum;
	void renderfigure(GLenum primtype);
	void renderfigure(GLubyte R, GLubyte G, GLubyte B, GLubyte A, GLenum primtype);
	cone(GLfloat x = 0, GLfloat y = 0, GLfloat z = 0, GLfloat rad = 0, GLfloat hgt = 0, GLfloat vertices = 360);
};

class cylinder : public object3d {
public:
	GLfloat radius;
	GLfloat height;
	GLfloat vertexnum;
	void renderfigure(GLenum primtype);
	void renderfigure(GLubyte R, GLubyte G, GLubyte B, GLubyte A, GLenum primtype);
	cylinder(GLfloat x = 0, GLfloat y = 0, GLfloat z = 0, GLfloat rad = 0, GLfloat hgt = 0, GLfloat vertices = 360);
};

class cube : public object3d {
public:
	GLfloat cubewidth;
	void renderfigure(GLenum primtype);
	void renderfigure(GLubyte R, GLubyte G, GLubyte B, GLubyte A, GLenum primtype);
	cube(GLfloat x = 0, GLfloat y = 0, GLfloat z = 0, GLfloat cw = 0);
};

class sphere : public object3d {
public:
	GLfloat radius;
	GLint stacks;
	GLint sectors;
	void renderfigure(GLenum primtype);
	void renderfigure(GLubyte R, GLubyte G, GLubyte B, GLubyte A, GLenum primtype);
	sphere(GLfloat x = 0, GLfloat y = 0, GLfloat z = 0, GLfloat r = 0, GLint sec = 0, GLint stk = 0);
};

class triprism : public object3d {
public:
	GLfloat height;
	GLfloat horizlength;
	GLfloat vertlength;
	void renderfigure(GLenum primtype);
	void renderfigure(GLubyte R, GLubyte G, GLubyte B, GLubyte A, GLenum primtype);
	triprism(GLfloat x = 0, GLfloat y = 0, GLfloat z = 0, GLfloat hlength = 0, GLfloat vlength = 0, GLfloat hgt = 0);
};

extern void RenderString(float x, float y, float z, void* font, const char* string);
extern void gridlines(double step);
GLuint LoadTexture(const char* filename);