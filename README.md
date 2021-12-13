# EAGLE [![Hits](https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2FBerkM125%2FEAGLE&count_bg=%2379C83D&title_bg=%23555555&icon=&icon_color=%23E7E7E7&title=hits&edge_flat=false)](https://hits.seeyoufarm.com)
Easy A** Game & graphics Library and Engine (OpenGL). Cross platform graphics engine for simple graphics.
## Some quick prerequisites
EAGLE is written in pure C++ and OpenGL with the GLUT/FreeGLUT library, and built with a shell script requiring g++. 
## What is EAGLE?
It's pretty self explanatory through the title, yet for clarity's sake EAGLE is a highly convenient yet powerful graphics library and engine that can be used to make 3d graphics, games, and animations. Being that it's been developed for only around 2 days (6/15/21), EAGLE is still in its basic and development stages, with many of its planned features, namely:

1) Physics engine
2) GUI + Editor
3) Textures and Shaders
4) Modeling interface

To be coming soon later. For the time being, EAGLE supports many basic yet useful features, such as:

1) Mesh loading + rendering
2) Camera functionality and vector transformation
3) 3D figure geometry
4) 3D transformation
5) Vertex buffer support
6) Blending + 4-byte color capability
7) Shader loading (implementation still buggy, will patch later)

Now, let's take a look at how to use EAGLE to make some 3D graphics.

## Structure 
Before doing anything with EAGLE, you should have an idea of how the EAGLE engine actually works. The structure of the EAGLE engine consists of freely edited files (these are the files where the programmer writes whatever they need to for their game), semi-freely editable files (though still surface level, these files involve a bit more core functionality than a purely freely editable file, and they can still be edited by the programmer), deeper core graphics and engine class files (these files are advised to be untouched, but if the programmer is confident in their ability they can feel free to edit and "hack" these files however they want), header files, and build file(s). Let's start by looking at some of the freely editable files:
### gameprocess.cpp

### interface.cpp

### camera.cpp
