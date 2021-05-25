#pragma once
#include <GL/freeglut.h>

namespace Constant {
	static const int SCREEN_WIDTH = 500;
	static const int SCREEN_HEIGHT = 500;
	static const char* TITLE = "15010951 S.G. Kang";

	static const GLfloat COLORSET_RGBA[5][4] = {
		{(GLfloat)249/255, (GLfloat)209/255, (GLfloat)0, 1},
		{(GLfloat)255/255, (GLfloat)38/255, (GLfloat)141/255, 1},
		{(GLfloat)1.0, (GLfloat)1.0, (GLfloat)1.0, 1},
		{(GLfloat)181/255, (GLfloat)78/255, (GLfloat)175/255, 1},
		{(GLfloat)255/255, (GLfloat)169/255, 0, 1}
	};
}