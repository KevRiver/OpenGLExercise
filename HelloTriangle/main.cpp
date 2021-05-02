#ifdef RUN
	#include <Windows.h>
	#include <GL/freeglut.h>

	int mouseCurPositionX = 0;
	int mouseCurPositionY = 0;
	int mouseCurButton = -1;

	void mouseStatus(int button, int state, int x, int y) 
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
		{
			if (x < 250)
			{
				glColor3f(0.0f, 0.0f, 1.0f);
			}
			else
			{
				glColor3f(1.0f, 0.0f, 0.0f);
			}
		}

		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			if (y < 250)
			{
				glColor3f(1.0f, 1.0f, 1.0f);
			}
			else
			{
				glColor3f(0.0f, 0.0f, 0.0f);
			}
		}

	}

	void mouseMotion(int x, int y) {
		int dx = x - mouseCurPositionX;
		int dy = y - mouseCurPositionY;
		mouseCurPositionX = x;
		mouseCurPositionY = y;

		if (dx < 0) {
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if (dx > 0) {
			glColor3f(0.0f, 1.0f, 0.0f);
		}

		glutPostRedisplay();
	}

	void init()
	{
		glClearColor(1.0, 1.0, 0.0, 1.0); // background RGBA, opaque window
		glColor3f(1.0, 1.0, 1.0); // RGB
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // screen size (-1.0,-1.0) to (1.0,1.0)
	}

	void display()
	{
		glClear(GL_COLOR_BUFFER_BIT); // clear the window
	
		glBegin(GL_QUADS);
		glVertex2f(-0.75, 0.75);
		glVertex2f(-0.75, 0.25);
		glVertex2f(-0.25, 0.25);
		glVertex2f(-0.25, 0.75);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(0.75, 0.75);
		glVertex2f(0.75, 0.25);
		glVertex2f(0.25, 0.25);
		glEnd();

		glBegin(GL_POLYGON); // fill connected polygon
		glVertex2f(0, 0); // vertices of the square
		glVertex2f(-0.35, -0.35);
		glVertex2f(-0.35, -0.7);
		glVertex2f(0.35, -0.7);
		glVertex2f(0.35, -0.35);
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
		glutInitWindowPosition(1350, 100);
		// create window with title ¡°simple¡±
		glutCreateWindow("15010951 S.G. Kang");
	

		// call init() function
		init();

		// call display() function
		glutDisplayFunc(display);

		// add mousefunc callback
		glutMouseFunc(mouseStatus);
		//glutMotionFunc(mouseMotion);
	
		// main event loop, do not use exit()
		glutMainLoop();
	}
#endif
