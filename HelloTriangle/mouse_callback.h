#pragma once

#include <set>
#include <unordered_map>
#include <GL/freeglut.h>

namespace MouseCallback {
	
	class MouseEventListener {
	public:
		int key;
	public:
		virtual void onRaise() {}
	};

	class MouseEvent {
	private:
		std::set<int, std::greater<int>> keys;
		std::unordered_map<int, MouseEventListener*> listeners;
	private:
		int generateKey();
	public:
		void addListener(MouseEventListener* listener);
		void removeListener(int key);
		void raise();
	};

	static MouseEvent lDownAtLeft;
	static MouseEvent lDownAtRight;
	static MouseEvent mDown;

	static int mouseCurPositionX = 0;
	static int mouseCurPositionY = 0;
	static int mouseCurButton = -1;

	void mouseStatus(int button, int state, int x, int y);
	void mouseMotion(int x, int y);

	void ex3MouseStatus(int button, int state, int x, int y);
	void ex3MouseMotion(int x, int y);
}