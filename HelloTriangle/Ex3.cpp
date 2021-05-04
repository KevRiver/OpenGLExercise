#include "Ex3.h"
#include "constants.h"

#define EX3DEBUG
#ifdef EX3DEBUG
	#include <iostream>
#endif

namespace Ex3 {
	lDownAtLeftEventListener::lDownAtLeftEventListener() { 
		MouseCallback::lDownAtLeft.addListener((lDownAtLeftEventListener*)this); 
	}
	
	void lDownAtLeftEventListener::onRaise() {
		Ex3::rotZ += 30;
		glutSwapBuffers();
#ifdef EX3DEBUG
		std::cout << "lbtn down at leftside ";
		std::cout << "rot: " << rotZ << "\n";
#endif
	}

	lDownAtRightEventListener::lDownAtRightEventListener() { 
		MouseCallback::lDownAtRight.addListener((lDownAtRightEventListener*)this); 
	}
	
	void lDownAtRightEventListener::onRaise() {
		Ex3::rotZ -= 30;
		glutSwapBuffers();
#ifdef EX3DEBUG
		std::cout << "lbtn down at rightside ";
		std::cout << "rot: " << rotZ << "\n";
#endif

	}
	
	mDownEventListener::mDownEventListener() { 
		MouseCallback::mDown.addListener(this); 
	}
	
	void mDownEventListener::onRaise() {
		Ex3::rotZ += 6;
	}

	lDownAtLeftEventListener* lDownLeft;
	lDownAtRightEventListener* lDownRight;

	void init() {
		glEnable(GL_DEPTH_TEST);
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glLoadIdentity();
	}

	void display() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glLoadIdentity();
		glRotatef(rotZ, 0, 0, 1);

		glPushMatrix();
		
		glColor3f(1.0, 0.0, 0.0); // red
		glTranslatef(-0.5, 0, 0);
		glutSolidCube(.33);
		
		glColor3f(0.0, 0.0, 1.0); // blue
		glTranslatef(0.5, 0, 0);
		glutSolidCube(.33);
		glPopMatrix();

		glutSwapBuffers();
	}
	void reshape(int w, int h) {
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(90.0, GLfloat(w) / GLfloat(h), 0.1, 40.0);
		gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);
		glMatrixMode(GL_MODELVIEW);
	}

	void ex3MouseStatus(int button, int state, int x, int y) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (x < Constant::screen_width / 2)
			{
				// rotate scene counterclockwise
#ifdef EX3DEBUG
				std::cout << "lbtn down at x: " << x << "\n";
#endif
				//lDownAtLeft.raise();
				rotZ += 30;
				glutPostRedisplay();
			}
			else
			{
				// rotate scene clockwise
#ifdef EX3DEBUG
				std::cout << "mouse lbtn down at right size of screen\n";
#endif
				//lDownAtRight.raise();
				rotZ -= 30;
				glutPostRedisplay();
			}
		}
	}

	// move scene when mouse middle button's state is down
	void ex3MouseMotion(int x, int y) {

	}
}