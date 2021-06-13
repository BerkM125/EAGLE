//Standard libraries
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
//.hpp library for external dependencies, do not tamper
extern float angle;
extern float yawsensitivity;
extern float pitchsensitivity;
extern float movincrement;
extern float angleincrement;
extern float lx;
extern float ly;
extern float lz;
extern float camx;
extern float camy;
extern float camz;
extern void rendercameraview(void);
extern void changeSize(int w, int h);