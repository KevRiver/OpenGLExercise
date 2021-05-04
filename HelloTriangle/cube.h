#pragma once
#include <GL/freeglut.h>

namespace Cube {
	static GLfloat vertices[][3] = {
			{-1.0, -1.0, -1.0}, {1.0, -1.0, -1.0},
			{1.0, 1.0, -1.0}, {-1.0, 1.0, -1.0},
			{-1.0, -1.0, 1.0}, {1.0, -1.0, 1.0},
			{1.0, 1.0, 1.0}, {-1.0, 1.0, 1.0}
	};

	static GLfloat colors[][3] = {
		{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0},
		{1.0, 1.0, 0.0}, {0.0, 1.0, 0.0},
		{0.0, 0.0, 1.0}, {1.0, 0.0, 1.0},
		{1.0, 1.0, 1.0}, {0.0, 1.0, 1.0}
	};

	// Topology
	static GLubyte cubeIndices[24] = { 0,3,2,1,2,3,7,6,0,4,7,3,1,2,6,5,4,5,6,7,0,1,5,4 };

	void init();

	void display();

	void reshape(int w, int h);
}