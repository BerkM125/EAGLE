//Standard libraries
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
//External engine dependencies
#include "vectorlib.hpp"
#include "cameralib.hpp"
#include "interfacelib.hpp"
#include "shaderslib.hpp"
#define MSCONSTANT 1000.0

double lastTime = time(NULL);
int nbFrames = 0;

void debugperformance(void) {
    // Measure speed
    double framedur = 0.0f;
    double currentTime = time(NULL);
    nbFrames++;
    if (currentTime - lastTime >= 1.0) { // If last prinf() was more than 1 sec ago
        std::cout << "FRAME SPEED: " << (MSCONSTANT / double(nbFrames)) << " FPS: " << 1 / (MSCONSTANT / double(nbFrames) / 1000) << std::endl;
        nbFrames = 0;
        lastTime += 1.0;
    }
    return;
}