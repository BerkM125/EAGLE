/*
* 3D FIGURES + OBJECTS CPP FILE
* Contains definitions of all three-dimensional-based
* classes and functions involving those classes. Declarations
* of the classes and functions here are located in "figureslib.hpp".
*/
//Standard libraries
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
//External engine dependencies
#include "figureslib.hpp"
#include "cameralib.hpp"
#include "interfacelib.hpp"

//Demonstrational purpose grid line rendering
void gridlines(double step) {
    glBegin(GL_LINES);
    glColor4f(0.9f, 0.9f, 0.9f, 0);
    for (double x = -100; x < 100; x+=step) {
        glVertex3f(x, 0.0f, -100.0f);
        glVertex3f(x, 0.0f, 100.0f);
    }
    for (double y = -100; y < 100; y += step) {
        glVertex3f(-100, 0.0f, y);
        glVertex3f(100, 0.0f, y);
    }
    glEnd();
}

void RenderString(float x, float y, float z, void* font, const char* string) {
    char* c;
    int n = 0;
    glColor3f(255, 255, 255);
    glTranslatef(x, y, z);
    while (string[n] != '\0') {
        glutStrokeCharacter(font, string[n]);
        n++;
    }
}

void color4ub::setcolor4ub(GLubyte red, GLubyte blue, GLubyte green, GLubyte alpha) {
    R = red;
    B = blue;
    G = green;
    A = alpha;
}

void vertex3d::setvertex3d(GLfloat xcrd, GLfloat ycrd, GLfloat zcrd) {
    xcoord = xcrd;
    ycoord = ycrd;
    zcoord = zcrd;
}

void object3d::pushvertex3f(GLfloat xcoord, GLfloat ycoord, GLfloat zcoord) {
    vertex3d tpoint(xcoord, ycoord, zcoord);
    vertexbuf.push_back(tpoint);
}

void object3d::rendervertexbuffer(GLenum primtype) {
    glColor4ub(objcolor.R, objcolor.G, objcolor.B, objcolor.A);
    glBegin(primtype);
    for (int n = 0; n < vertexbuf.size(); n++)
        glVertex3f(vertexbuf[n].xcoord, vertexbuf[n].ycoord, vertexbuf[n].zcoord);
    glEnd();
}

void object3d::rendervertexbuffer(GLubyte R, GLubyte G, GLubyte B, GLubyte A, GLenum primtype) {
    glColor4ub(R, G, B, A);
    glBegin(primtype);
    for (int n = 0; n < vertexbuf.size(); n++)
        glVertex3f(vertexbuf[n].xcoord, vertexbuf[n].ycoord, vertexbuf[n].zcoord);
    glEnd();
}

void object3d::importvertex3dbuf(const char* fn, unsigned int num) {
    FILE* objfp;
    unsigned int index = 0;
    float xcrd, ycrd, zcrd;
    char line[64] = "";
    vertex3d tpoint;
    objfp = fopen(fn, "r+");
    if (!objfp) return;
    vertexbuf.clear();
    while (index < num) {
        {
            fscanf(objfp, "v %f %f %f\n", &xcrd, &ycrd, &zcrd);
            tpoint.xcoord = xcrd;
            tpoint.ycoord = ycrd;
            tpoint.zcoord = zcrd;
            //printf("%s %f %f %f\n", line, tpoint.xcoord, tpoint.ycoord, tpoint.zcoord);
            vertexbuf.push_back(tpoint);
        }
        index++;
    }
    fclose(objfp);
}

cylinder::cylinder(GLfloat x, GLfloat y, GLfloat z, GLfloat rad, GLfloat hgt, GLfloat vertices) {
    radius = rad;
    height = hgt;
    xcoord = x;
    ycoord = y;
    zcoord = z;
    vertexnum = vertices;
}

void cylinder::renderfigure(GLubyte R, GLubyte G, GLubyte B, GLubyte A, GLenum primtype) {
    GLfloat x = xcoord;
    GLfloat y = ycoord;
    GLfloat z = zcoord;
    GLfloat angle = 0.0;
    GLfloat step = (6.33 / vertexnum);
    GLfloat dblPI = 2 * PI;
    GLfloat colortint = 40;
    glColor4ub(R - colortint, G - colortint, B - colortint, A);
    glBegin(primtype);
    angle = 0.0;
    vertexbuf.clear();
    while (angle < dblPI) {
        x = (radius * cos(angle)) + xcoord;
        y = (radius * sin(angle)) - ycoord;
        glVertex3f(x, y, height + z);
        pushvertex3f(x, y, height + z);
        glVertex3f(x, y, z);
        pushvertex3f(x, y, z);
        angle = angle + step;
    }
    glVertex3f(radius + xcoord, -ycoord, height + z);
    pushvertex3f(radius + xcoord, -ycoord, height + z);
    glVertex3f(radius + xcoord, -ycoord, z);
    pushvertex3f(radius + xcoord, -ycoord, z);
    glEnd();
    glColor4ub(R, G, B, A);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while (angle < dblPI) {
        x = (radius * cos(angle)) + xcoord;
        y = (radius * sin(angle)) - ycoord;
        glVertex3f(x, y, z);
        pushvertex3f(x, y, z);
        angle = angle + step;
    }
    glVertex3f(radius + xcoord, -ycoord, z);
    pushvertex3f(radius + xcoord, -ycoord, z);
    glEnd();
}

cone::cone(GLfloat x, GLfloat y, GLfloat z, GLfloat rad, GLfloat hgt, GLfloat vertices) {
    radius = rad;
    height = hgt;
    xcoord = x;
    ycoord = y;
    zcoord = z;
    vertexnum = vertices;
}

void cone::renderfigure(GLubyte R, GLubyte G, GLubyte B, GLubyte A, GLenum primtype) {
    GLfloat x = xcoord;
    GLfloat y = ycoord;
    GLfloat z = zcoord;
    GLfloat angle = 0.0;
    GLfloat step = (6.33 / vertexnum);
    GLfloat dblPI = 2 * PI;
    GLfloat colortint = 40;
    glColor4ub(R - colortint, G - colortint, B - colortint, A);
    glBegin(primtype);
    angle = 0.0;
    vertexbuf.clear();
    while (angle < dblPI) {
        x = (radius * cos(angle)) + xcoord;
        y = (radius * sin(angle)) - ycoord;
        glVertex3f(x, y, height + z);
        pushvertex3f(x, y, height + z);
        glVertex3f(xcoord, -ycoord, z);
        pushvertex3f(xcoord, -ycoord, z);
        angle = angle + step;
    }
    glEnd();
    glColor4ub(R, G, B, A);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while (angle < dblPI) {
        x = (radius * cos(angle)) + xcoord;
        y = (radius * sin(angle)) - ycoord;
        glVertex3f(x, y, height + z);
        pushvertex3f(x, y, height + z);
        angle = angle + step;
    }
    glVertex3f(radius + xcoord, -ycoord, height + z);
    pushvertex3f(radius + xcoord, -ycoord, height + z);
    glEnd();
}

cube::cube(GLfloat x, GLfloat y, GLfloat z, GLfloat cw) {
    xcoord = x;
    ycoord = y;
    zcoord = z;
    cubewidth = cw;
}

void cube::renderfigure(GLubyte R, GLubyte G, GLubyte B, GLubyte A, GLenum primtype) {
    GLfloat x = xcoord;
    GLfloat y = ycoord;
    GLfloat z = zcoord;
    GLfloat colortint = 0;
    vertexbuf.clear();
    glColor4ub(R - colortint, G - colortint, B - colortint, A);
    glBegin(primtype);
    glVertex3f(x, y, z);
    pushvertex3f(x, y, z);
    glVertex3f(x, y, cubewidth + z);
    pushvertex3f(x, y, cubewidth + z);
    glVertex3f(x + cubewidth, y, z);
    pushvertex3f(x + cubewidth, y, z);
    glVertex3f(x + cubewidth, y, cubewidth + z);
    pushvertex3f(x + cubewidth, y, cubewidth + z);
    glVertex3f(x + cubewidth, y + cubewidth, z);
    pushvertex3f(x + cubewidth, y + cubewidth, z);
    glVertex3f(x + cubewidth, y + cubewidth, cubewidth + z);
    pushvertex3f(x + cubewidth, y + cubewidth, cubewidth + z);
    glVertex3f(x, y + cubewidth, z);
    pushvertex3f(x, y + cubewidth, z);
    glVertex3f(x, y + cubewidth, cubewidth + z);
    pushvertex3f(x, y + cubewidth, cubewidth + z);
    glVertex3f(x, y, z);
    pushvertex3f(x, y, z);
    glVertex3f(x, y + cubewidth, z);
    pushvertex3f(x, y + cubewidth, z);
    glVertex3f(x, y, cubewidth + z);
    pushvertex3f(x, y, cubewidth + z);
    glVertex3f(x, y + cubewidth, cubewidth + z);
    pushvertex3f(x, y + cubewidth, cubewidth + z);
    glVertex3f(x, y, z);
    pushvertex3f(x, y, z);
    glVertex3f(x + cubewidth, y, z);
    pushvertex3f(x + cubewidth, y, z);
    glVertex3f(x, y + cubewidth, z);
    pushvertex3f(x, y + cubewidth, z);
    glVertex3f(x + cubewidth, y + cubewidth, z);
    pushvertex3f(x + cubewidth, y + cubewidth, z);
    glEnd();
}

void sphere::renderfigure(GLubyte R, GLubyte G, GLubyte B, GLubyte A, GLenum primtype) {
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat z = 0.0;
    GLfloat xy = 0.0;
    GLfloat lengthInv = 1.0 / (GLfloat)(((swidth + sheight) / 2) / 2) - 1.0;
    GLfloat dblpi = 2 * PI;
    GLfloat sectorstep = dblpi / sectors;
    GLfloat stackstep = PI / stacks;
    GLfloat stackangle = 0.0;
    GLfloat sectorangle = 0.0;
    GLfloat colortint = 0;
    glColor4ub(R - colortint, G - colortint, B - colortint, A);
    glBegin(primtype);
    vertexbuf.clear();
    for (int i = 0; i <= stacks; ++i) {
        stackangle = PI / 2 - i * stackstep;
        xy = radius * cosf(stackangle);
        z = radius * sinf(stackangle) * lengthInv;
        for (int i2 = 0; i2 <= sectors; ++i2) {
            sectorangle = i2 * sectorstep;
            x = xy * cosf(sectorangle) * lengthInv;
            y = xy * sinf(sectorangle) * lengthInv;
            glVertex3f(x + xcoord, y + ycoord, z + zcoord);
            pushvertex3f(x + xcoord, y + ycoord, z + zcoord);
        }
    }
    glEnd();
}

sphere::sphere(GLfloat x, GLfloat y, GLfloat z, GLfloat r, GLint sec, GLint stk) {
    xcoord = x;
    ycoord = y;
    zcoord = z;
    radius = r;
    sectors = sec;
    stacks = stk;
}

void triprism::renderfigure(GLubyte R, GLubyte G, GLubyte B, GLubyte A, GLenum primtype) {
    GLfloat colortint = 40; //can be changed
    glBegin(primtype);
    glColor4ub(R - colortint, G - colortint, B - colortint, A);
    //Side faces
    glVertex3f(xcoord, ycoord, zcoord);
    glVertex3f(xcoord, ycoord-height, zcoord);
    glVertex3f(xcoord, ycoord, zcoord+vertlength);
    glVertex3f(xcoord, ycoord - height, zcoord+vertlength);
    glVertex3f(xcoord+horizlength, ycoord, zcoord);
    glVertex3f(xcoord+horizlength, ycoord - height, zcoord);
    glVertex3f(xcoord, ycoord, zcoord);
    glVertex3f(xcoord, ycoord - height, zcoord);

    pushvertex3f(xcoord, ycoord, zcoord);
    pushvertex3f(xcoord, ycoord - height, zcoord);
    pushvertex3f(xcoord, ycoord, zcoord + vertlength);
    pushvertex3f(xcoord, ycoord - height, zcoord + vertlength);
    pushvertex3f(xcoord + horizlength, ycoord, zcoord);
    pushvertex3f(xcoord + horizlength, ycoord - height, zcoord);
    pushvertex3f(xcoord, ycoord, zcoord);
    pushvertex3f(xcoord, ycoord - height, zcoord);
    //Top and bottom faces
    glColor4ub(R, G, B, A);
    glVertex3f(xcoord+ horizlength, ycoord, zcoord);
    glVertex3f(xcoord, ycoord, zcoord+ vertlength);
    glVertex3f(xcoord, ycoord, zcoord);

    glVertex3f(xcoord+ horizlength, ycoord-height, zcoord);
    glVertex3f(xcoord, ycoord-height, zcoord+ vertlength);
    glVertex3f(xcoord, ycoord-height, zcoord);

    pushvertex3f(xcoord + horizlength, ycoord, zcoord);
    pushvertex3f(xcoord, ycoord, zcoord + vertlength);
    pushvertex3f(xcoord, ycoord, zcoord);

    pushvertex3f(xcoord + horizlength, ycoord - height, zcoord);
    pushvertex3f(xcoord, ycoord - height, zcoord + vertlength);
    pushvertex3f(xcoord, ycoord - height, zcoord);
    glEnd();

}

triprism::triprism(GLfloat hlength, GLfloat vlength, GLfloat hgt, GLfloat x, GLfloat y, GLfloat z) {
    horizlength = hlength;
    vertlength = vlength;
    height = hgt;
    xcoord = x;
    ycoord = y;
    zcoord = z;
}

GLuint LoadTexture(const char* filename) {
    GLuint texture;
    int width, height;
    unsigned char* data;

    FILE* file;
    file = fopen(filename, "rb");

    if (file == NULL) return 0;
    width = 1024;
    height = 512;
    data = (unsigned char*)malloc(width * height * 3);
    //int size = fseek(file,);
    fread(data, width * height * 3, 1, file);
    fclose(file);

    for (int i = 0; i < width * height; ++i)
    {
        int index = i * 3;
        unsigned char B, R;
        B = data[index];
        R = data[index + 2];

        data[index] = R;
        data[index + 2] = B;
    }

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
    free(data);

    return texture;
}