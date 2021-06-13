#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923
#define CYLINDER 1
#define CONE 2
#define CUBE 3
#define SPHERE 4

class cone {
public:
	GLfloat radius;
	GLfloat height;
	GLfloat xcoord;
	GLfloat ycoord;
	GLfloat zcoord;
	GLfloat vertexnum;
	void drawCone(GLubyte R, GLubyte G, GLubyte B, GLenum primtype);
	cone(GLfloat rad = 0, GLfloat hgt = 0, GLfloat x = 0, GLfloat y = 0, GLfloat z = 0, GLfloat vertices = 360);
};

class cylinder {
public:
	GLfloat radius;
	GLfloat height;
	GLfloat xcoord;
	GLfloat ycoord;
	GLfloat zcoord;
	GLfloat vertexnum;
	void drawCylinder(GLubyte R, GLubyte G, GLubyte B, GLenum primtype);
	cylinder(GLfloat rad = 0, GLfloat hgt = 0, GLfloat x = 0, GLfloat y = 0, GLfloat z = 0, GLfloat vertices = 360);
};

class cube {
public:
	GLfloat xcoord;
	GLfloat ycoord;
	GLfloat zcoord;
	GLfloat cubewidth;
	void drawCube(GLubyte R, GLubyte G, GLubyte B, GLenum primtype);
	cube(GLfloat x = 0, GLfloat y = 0, GLfloat z = 0, GLfloat cw = 0);
};

class sphere {
public:
	GLfloat xcoord;
	GLfloat ycoord;
	GLfloat zcoord;
	GLfloat radius;
	GLint stacks;
	GLint sectors;
	void rendersphere(GLubyte R, GLubyte G, GLubyte B, GLenum primtype);
	sphere(GLfloat x = 0, GLfloat y = 0, GLfloat z = 0, GLfloat r = 0, GLint sec = 0, GLint stk = 0);
};

class triprism {
public:
	GLfloat height;
	GLfloat horizlength;
	GLfloat vertlength;
	GLfloat xcoord;
	GLfloat ycoord;
	GLfloat zcoord;
	void drawPrism(GLubyte R, GLubyte G, GLubyte B, GLenum primtype);
	triprism(GLfloat hlength = 0, GLfloat vlength = 0, GLfloat hgt = 0, GLfloat x = 0, GLfloat y = 0, GLfloat z = 0);
};

extern void RenderString(float x, float y, float z, void* font, const char* string);
extern void gridlines(double step);
GLuint LoadTexture(const char* filename);