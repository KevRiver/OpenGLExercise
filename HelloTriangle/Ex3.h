#pragma once
#include <GL/freeglut.h>
#include "mouse_callback.h"

namespace Ex3 {
	static GLfloat rotZ = 0;

	class lDownAtLeftEventListener : public MouseCallback::MouseEventListener {
	public:
		lDownAtLeftEventListener();
		virtual void onRaise();
	};

	class lDownAtRightEventListener : public MouseCallback::MouseEventListener {
	public:
		lDownAtRightEventListener();
		virtual void onRaise();
	};

	class mDownEventListener :public MouseCallback::MouseEventListener {
	public:
		mDownEventListener();
		virtual void onRaise();
	};

	void init();

	void display();

	void reshape(int w, int h);

	void ex3MouseStatus(int button, int state, int x, int y);
	void ex3MouseMotion(int x, int y);
}