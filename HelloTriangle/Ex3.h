#pragma once
#include <GL/freeglut.h>

namespace Ex3 {
	void init();

	void display();

	void reshape(int w, int h);

	void ex3MouseStatus(int button, int state, int x, int y);
	void ex3MouseMotion(int x, int y);
}