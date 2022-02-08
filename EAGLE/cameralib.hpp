//Standard libraries
#include <GL/freeglut.h>
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
extern void mousecameracontrol(int xx, int yy);
extern void normalkeycameracontrol(unsigned char key, int xx, int yy);
extern void arrowkeycameracontrol(int key, int xx, int yy);