//Standard libraries
#include <GL/freeglut.h>
#include <stdio.h>
#include <iostream>
extern void processNormalKeys(unsigned char key, int xx, int yy);
extern void processSpecialKeys(int key, int xx, int yy);
extern void mousemove(int xx, int yy);
extern void bindmousecontrol(void);
extern void bindnormalkeycontrol(void);
extern void bindarrowkeycontrol(void);
extern GLfloat swidth;
extern GLfloat sheight;