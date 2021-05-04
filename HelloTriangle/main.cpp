#define RUN
#ifdef RUN

#pragma once
#include <Windows.h>
#include <GL/freeglut.h>
#include "constants.h"
#include "cube.h"
#include "Ex3.h"

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(Constant::screen_width, Constant::screen_height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("15010951 S.G. Kang");

	// call init() function
	Ex3::init();

	// call display() function
	glutDisplayFunc(Ex3::display);

	// call reshape() function
	glutReshapeFunc(Ex3::reshape);

	glutMouseFunc(Ex3::ex3MouseStatus);
	glutMotionFunc(Ex3::ex3MouseMotion);

	glutMainLoop();
}

#endif
