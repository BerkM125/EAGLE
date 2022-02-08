#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/freeglut.h>
extern GLuint vs;
extern GLuint fs;
extern GLuint shaderprogram;
extern char vertexshader[256];
extern char fragmentshader[256];
extern void loadvertexshader(const char* fn);
extern void loadfragmentshader(const char* fn);
extern void bindvertexbuffer(GLuint* vao, GLuint* vbo, GLfloat *vertexbuf);
extern void initshaders(GLuint* vs, GLuint* fs, GLuint* shaderprogram, const char* fragshader, const char* vertshader);