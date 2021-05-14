#include "ex3.h"
#include "constants.h"

#define EX3DEBUG
#ifdef EX3DEBUG
#include <iostream>
#endif

namespace Ex3 {
	GLfloat rotZ = 0;
	int mouseCurButton = -1;

	void init() {
		glEnable(GL_DEPTH_TEST);
		glClearColor(1.0, 1.0, 1.0, 0.0);
		glLoadIdentity();
	}

	void display() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glPushMatrix(); // draw axis
			glBegin(GL_LINES);

			glColor3f(1.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(2.0, 0.0, 0.0);

			glColor3f(0.0, 1.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 2.0, 0.0);

			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 2.0);
			glEnd();
		glPopMatrix();

		glPushMatrix(); // draw cube
			glLoadIdentity();
			glRotatef(rotZ, 0, 0, 1);
			glPushMatrix();
				glColor3f(1.0, 0.0, 0.0); // red cube
				glTranslatef(-0.5, 0, 0);
				glutSolidCube(.33);
				glColor3f(1.0, 1.0, 1.0);
				glutWireCube(.33);
				glColor3f(0.0, 0.0, 1.0); // blue cube
				glTranslatef(1.0, 0, 0);
				glutSolidCube(.33);
				glColor3f(1.0, 1.0, 1.0);
				glutWireCube(.33);
			glPopMatrix();
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
			if (x < Constant::SCREEN_WIDTH / 2)
			{
				// rotate scene counterclockwise
#ifdef EX3DEBUG
				std::cout << "lbtn down at x: " << x << "\n";
#endif
				rotZ += 30;
			}
			else
			{
				// rotate scene clockwise
#ifdef EX3DEBUG
				std::cout << "lbtn down at x: " << x << "\n";
#endif
				rotZ -= 30;
			}
		}

		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
			glViewport(0, 0, Constant::screen_width, Constant::screen_height);
		}

		if (button == GLUT_MIDDLE_BUTTON) {
			mouseCurButton = state == GLUT_DOWN ? GLUT_MIDDLE_BUTTON : -1;
		}
	}

	// move scene when mouse middle button's state is down
	void ex3MouseMotion(int x, int y) {
#ifdef EX3DEBUG
		std::cout << "ex3MouseMotion called\n";
#endif
		if (mouseCurButton == GLUT_MIDDLE_BUTTON) {
			// follow mouse position
#ifdef EX3DEBUG
			std::cout << "mouse middle button down\n";
#endif
			y = Constant::SCREEN_HEIGHT - y;
			glViewport(x - Constant::SCREEN_WIDTH / 2,
				y - Constant::SCREEN_HEIGHT / 2,
				Constant::SCREEN_WIDTH,
				Constant::SCREEN_HEIGHT);
			glutPostRedisplay();
		}
	}
}