#define RUN
#ifdef RUN

#pragma once
#include <Windows.h>
#include <GL/freeglut.h>
#include "constants.h"
#include "light.h"
#include "material.h"

#include <iostream>

GLUquadricObj* quadricObj;

Kang::Light whiteLight(GL_LIGHT0);
Kang::Light redLight(GL_LIGHT1);

Kang::Material whiteSphereMaterial;
Kang::Material redSphereMaterial;

Kang::Material materials[5];

GLfloat rotZ = 0;

void init() {
	quadricObj = gluNewQuadric();
	gluQuadricDrawStyle(quadricObj, GLU_FILL);
	gluQuadricNormals(quadricObj, GLU_SMOOTH);
	gluQuadricOrientation(quadricObj, GLU_OUTSIDE);
	gluQuadricTexture(quadricObj, GLU_FALSE);

	glShadeModel(GL_FLAT);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);

	GLfloat whiteLightPosition[] = { 5.0, 5.0, -10.0 };
	whiteLight.setPosition(whiteLightPosition);

	GLfloat redLightPosition[] = { 5.0f, -5.0f, -10.0f };
	GLfloat ambientColor[] = { 0.25f, 0.0f, 0.0f, 0.1f }; // red
	GLfloat diffuseColor[] = { 0.75f, 0.0f, 0.0f, 0.5f }; // red
	redLight.setAmbientColor(ambientColor);
	redLight.setDiffuseColor(diffuseColor);
	redLight.setPosition(redLightPosition);

	for (int i = 0; i < 5; i++) {
		materials[i].setAmbientColor(Constant::COLORSET_RGBA[i]);
		materials[i].setDiffuseColor(Constant::COLORSET_RGBA[i]);
	}

	glClearColor(0.0, 0.0f, 0.0f, 1.0f);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

	glPushMatrix(); // sphere 0
	glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
	glTranslatef(-3.0f, 0.0f, 0.0f);
	materials[0].applyMaterial();
	gluSphere(quadricObj, 1, 16, 16);
	glPopMatrix();

	glPushMatrix(); // sphere 1
	glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, 0.0f, 0.0f);
	materials[1].applyMaterial();
	gluSphere(quadricObj, 1, 16, 16);
	glPopMatrix();

	glPushMatrix(); // sphere 2
	glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
	glTranslatef(3.0f, 0.0f, 0.0f);
	materials[2].applyMaterial();
	gluSphere(quadricObj, 1, 16, 16);
	glPopMatrix();

	glPushMatrix(); // cylinder 0
	glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, 0.0f, -5.0f);
	materials[3].applyMaterial();
	gluCylinder(quadricObj, 1, 1, 3, 16, 16);
	glPopMatrix();

	glPushMatrix(); // cylinder 1
	glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, 0.0f, 2.0f);
	materials[4].applyMaterial();
	gluCylinder(quadricObj, 1, 1, 3, 16, 16);
	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, GLfloat(w) / GLfloat(h), 0.1, 40.0);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}

void mouseStatus(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// click left side of screen
		if (x < Constant::SCREEN_WIDTH / 2) {
			rotZ += 6;
		}
		else {
			rotZ -= 6;
		}
	}
}

void mouseMotion(int x, int y) {
}

void getKey(unsigned char keycode, int x, int y) {

	//std::cout << "keycode : ";
	//std::cout << keycode << "\n";
	
	switch (keycode) {
	case '0':
		// turn white light only
		whiteLight.enable();
		redLight.disable();
		break;
	case '1':
		// turn red light only
		whiteLight.disable();
		redLight.enable();
		break;
	case '2':
		// turn both lights
		whiteLight.enable();
		redLight.enable();
		break;
	case '3':
		// turn off both lights
		whiteLight.disable();
		redLight.disable();
		break;
	defualt:
		break;
	}

	glutPostRedisplay();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(Constant::SCREEN_WIDTH, Constant::SCREEN_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("15010951 S.G. Kang");

	// call init() function
	init();

	// call display() function
	glutDisplayFunc(display);

	// call reshape() function
	glutReshapeFunc(reshape);

	glutMouseFunc(mouseStatus);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(getKey);

	glutMainLoop();
}

#endif
