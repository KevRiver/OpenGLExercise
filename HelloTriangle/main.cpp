#include <Windows.h>
#include <GL/freeglut.h>

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); // black clear color, opaque window
	glColor3f(1.0, 1.0, 1.0); // white
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // screen size (-1.0,-1.0) to (1.0,1.0)
}

void mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT); // clear the window
	glBegin(GL_POLYGON); // fill connected polygon
	glVertex2f(-0.5, -0.5); // vertices of the square
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	// glut init
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// actual window size
	glutInitWindowSize(500, 500);
	// initial window location, top-left corner
	glutInitWindowPosition(0, 0);
	// create window with title ¡°simple¡±
	glutCreateWindow("Hello GL");
	// call mydisplay() function
	glutDisplayFunc(mydisplay);
	// call init() function
	init();
	// main event loop, do not use exit()
	glutMainLoop();
}
