/*
* 3D FIGURES + OBJECTS CPP FILE
* Contains definitions of all three-dimensional-based
* classes and functions involving those classes. Declarations
* of the classes and functions here are located in "figureslib.hpp".
*/
//Standard libraries
#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
//External engine dependencies
#include "figureslib.hpp"
#include "cameralib.hpp"
#include "interfacelib.hpp"
#include "shaderslib.hpp"

extern std::vector<object3d> sceneassets;
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

object3d::object3d() {
    sceneassets.push_back(*this);
    this->sceneindice = sceneassets.size()-1;
    std::cout << sceneindice << " " << sceneassets.size()-1 << std::endl;
}

void object3d::cloneobj (object3d *n_obj) {
    n_obj->xcoord = xcoord;
    /*n_obj->ycoord = ycoord;
    n_obj->zcoord = zcoord;
    /*n_obj->objcolor.A = objcolor.A;
    n_obj->objcolor.R = objcolor.R;
    n_obj->objcolor.G = objcolor.G;
    n_obj->objcolor.B = objcolor.B;
    n_obj->uvbuf.clear();
    n_obj->vertexbuf.clear();
    n_obj->normalsbuf.clear();
    for(int n = 0; n < uvbuf.size(); n++)
        n_obj->uvbuf.push_back(uvbuf[n]);
    for(int n = 0; n < vertexbuf.size(); n++)
        n_obj->vertexbuf.push_back(vertexbuf[n]);
    for(int n = 0; n < normalsbuf.size(); n++)
        n_obj->normalsbuf.push_back(normalsbuf[n]);*/
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

void object3d::rendermesh3d(GLubyte R, GLubyte G, GLubyte B, GLubyte A, GLenum primtype) {
    glColor4ub(R, G, B, A);
    glBegin(primtype);
    for (int n = 0; n < vertexbuf.size(); n++)
        glVertex3f(vertexbuf[n].xcoord, vertexbuf[n].ycoord, vertexbuf[n].zcoord);
    glEnd();
}

void object3d::importmesh3d(const char* fn) {
    FILE *objfp;
    char line[64];
    std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
    std::vector< vertex3d > tmpvertices;
    std::vector< vertex3d > tmpnormals;
    std::vector< vertex2d > tmpuvs;
    vertex3d tpoint;
    vertex2d tcoord;
    unsigned int index = 0;
    float xcrd, ycrd, zcrd;

    objfp = fopen(fn, "r+");
    if (!objfp) return;
    uvbuf.clear();
    normalsbuf.clear();
    vertexbuf.clear();
    while (fgets(line, 64, objfp)) {
        if (line[0] == 'v' && line[1] == ' ') {
            sscanf(line, "v %f %f %f\n", &xcrd, &ycrd, &zcrd);
            tpoint.xcoord = xcrd;
            tpoint.ycoord = ycrd;
            tpoint.zcoord = zcrd;
            tmpvertices.push_back(tpoint);
        }
        else if (line[0] == 'v' && line[1] == 'n') {
            sscanf(line, "vn %f %f %f\n", &xcrd, &ycrd, &zcrd);
            tpoint.xcoord = xcrd;
            tpoint.ycoord = ycrd;
            tpoint.zcoord = zcrd;
            tmpnormals.push_back(tpoint);
        }
        else if (line[0] == 'v' && line[1] == 't') {
            sscanf(line, "vt %f %f\n", &xcrd, &ycrd);
            tcoord.xcoord = xcrd;
            tcoord.ycoord = ycrd;
            tmpuvs.push_back(tcoord);
        }
        else if (line[0] == 'f' && line[1] == ' ') {
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = sscanf(line, "f %d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
            if(matches == 9) {
                //printf("f %d/%d/%d %d/%d/%d %d/%d/%d\n", vertexIndex[0], uvIndex[0], normalIndex[0], vertexIndex[1], uvIndex[1], normalIndex[1], vertexIndex[2], uvIndex[2], normalIndex[2]);
                for(int x = 0; x < 3; x++) {
                    vertexIndices.push_back(vertexIndex[x]);
                    uvIndices.push_back(uvIndex[x]);
                    normalIndices.push_back(normalIndex[x]);
                }
            }
            else {
                //std::cout << "Face formatting in OBJ went wrong at index " << index << " for " << fn << ", skipping indice..." << std::endl;
            }
        }
        index++;
    }
    //This checks if the faces/indices were in the right formatted and were stored. If not, resort to simply the vertices
    if(vertexIndices.size() > 1) {
        for (int i = 0; i < vertexIndices.size(); i++) {
            unsigned int vertexIndex = vertexIndices[i];
            unsigned int uvIndex = uvIndices[i];
            unsigned int normalIndex = normalIndices[i];
            vertex3d vertex = tmpvertices[vertexIndex-1];
            vertex2d uv = tmpuvs[uvIndex-1];
            vertex3d normal = tmpnormals[normalIndex-1];
            vertexbuf.push_back(vertex);
            uvbuf.push_back(uv);
            normalsbuf.push_back(normal);
        }
    }
    else {
        for (int i = 0; i < tmpvertices.size(); i++) {
            vertex3d vertex = tmpvertices[i];
            vertexbuf.push_back(vertex);
        }
    }
    fclose (objfp);
    //sceneassets[sceneindice].xcoord = this->xcoord; 
    //cloneobj(&sceneassets[sceneindice]);
    std::cout << sceneindice << std::endl;
}

void object3d::importvertex3dbuf(const char* fn) {
    FILE *objfp;
    char line[64];
    unsigned int index = 0;
    float xcrd, ycrd, zcrd;
    vertex3d tpoint;
    objfp = fopen(fn, "r+");
    if (!objfp) return;
    vertexbuf.clear();
    while (fgets(line, 64, objfp)) {
        if (line[0] == 'v' && line[1] == ' ') {
            sscanf(line, "v %f %f %f\n", &xcrd, &ycrd, &zcrd);
            tpoint.xcoord = xcrd;
            tpoint.ycoord = ycrd;
            tpoint.zcoord = zcrd;
            //printf("%s %f %f %f\n", line, tpoint.xcoord, tpoint.ycoord, tpoint.zcoord);
            vertexbuf.push_back(tpoint);
        }
        index++;
    }
    fclose (objfp);
    cloneobj(&sceneassets[sceneindice]);
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