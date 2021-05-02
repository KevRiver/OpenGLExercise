#define RUN
#ifdef RUN
#include <Windows.h>
#include <GL/freeglut.h>

int screen_width = 500;
int screen_height = 500;

namespace Cube {
	GLfloat vertices[][3] = {
			{-1.0, -1.0, -1.0}, {1.0, -1.0, -1.0},
			{1.0, 1.0, -1.0}, {-1.0, 1.0, -1.0},
			{-1.0, -1.0, 1.0}, {1.0, -1.0, 1.0},
			{1.0, 1.0, 1.0}, {-1.0, 1.0, 1.0}
	};

	GLfloat colors[][3] = {
		{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0},
		{1.0, 1.0, 0.0}, {0.0, 1.0, 0.0},
		{0.0, 0.0, 1.0}, {1.0, 0.0, 1.0},
		{1.0, 1.0, 1.0}, {0.0, 1.0, 1.0}
	};

	// Topology
	GLubyte cubeIndices[24] = { 0,3,2,1,2,3,7,6,0,4,7,3,1,2,6,5,4,5,6,7,0,1,5,4 };

	void init() {
		glEnable(GL_DEPTH_TEST);
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, vertices); // notify vertices array address to gl
		glColorPointer(3, GL_FLOAT, 0, colors); // notify color array address to gl
	}

	void display() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndices);

		glutSwapBuffers();
	}
}

namespace Cylinder {

	void display() {
	}
}



void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, GLfloat(w) / GLfloat(h), 0.5, 40.0);
	gluLookAt(10, 10, 10, .5, .5, .5, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(screen_width, screen_height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("15010951 S.G. Kang");

	// call init() function
	Cube::init();

	// call display() function
	glutDisplayFunc(Cube::display);
	
	// call reshape() function
	glutReshapeFunc(reshape);

	glutMainLoop();
}

#endif