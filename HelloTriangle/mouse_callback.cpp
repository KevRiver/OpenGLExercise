#pragma once
#include <algorithm>

#include "mouse_callback.h"
#include "constants.h"
#include "Ex3.h"

#define MCBDEBUG

#ifdef MCBDEBUG
	#include <iostream>
#endif

namespace MouseCallback {
	
	int MouseEvent::generateKey() {
		int newKey = 0;
		if (this->keys.empty()) return newKey;

		auto it = keys.begin();
		newKey = *it + 1;

		return newKey;
	}

	void MouseEvent::addListener(MouseEventListener* listener) {
		try {
			listener->key = generateKey();
#ifdef DEBUG
			std::cout << "new key: " << listener->key << "\n";
#endif
			listeners.emplace(std::make_pair(listener->key, listener));
		}
		catch (std::exception& e) {
#ifdef DEBUG
			std::cout << e.what() << "\n";
#endif
		}
	}

	void MouseEvent::removeListener(int key) {
		try {
			listeners.erase(key);
		}
		catch (std::exception& e) {
#ifdef DEBUG
			std::cout << e.what() << "\n";
#endif
		}
	}

	void MouseEvent::raise() {
		try {
			for (auto it = this->listeners.begin(); it != listeners.end(); it++) {
				it->second->onRaise();
			}
		}catch (std::exception& e) {
#ifdef MCBDEBUG
			std::cout << e.what() << "\n";
#endif
		}
	}

	
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

	// rotate scene on left button click
	void ex3MouseStatus(int button, int state, int x, int y) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (x < Constant::screen_width)
			{
				// rotate scene counterclockwise
#ifdef MCBDEBUG
				std::cout << "lbtn down at x: " << x << "\n";
#endif
				//lDownAtLeft.raise();
				Ex3::rotZ += 30;
				glutPostRedisplay();
			}
			else
			{
				// rotate scene clockwise
#ifdef MCBDEBUG
				std::cout << "mouse lbtn down at right size of screen\n";
#endif
				//lDownAtRight.raise();
				Ex3::rotZ -= 30;
				glutPostRedisplay();
			}
		}

		if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
			mDown.raise();
		}
	}

	// move scene when mouse middle button's state is down
	void ex3MouseMotion(int x, int y) {
	
	}
}