#pragma once
#include <GL/freeglut.h>

namespace Kang {
	class Light {
	private:
		GLenum  _lightIdx;
		GLfloat _ambientLightColor[4];
		GLfloat _diffuseLightColor[4];
		GLfloat _specularLightColor[4];
		GLfloat _position[3];
	public:
		Light(GLenum lightIdx) {
			_lightIdx = lightIdx;

			_ambientLightColor[0] = .25f;
			_ambientLightColor[1] = .25f;
			_ambientLightColor[2] = .25f;
			_ambientLightColor[3] = 1.0f;
			glLightfv(_lightIdx, GL_AMBIENT, _ambientLightColor); // white

			_diffuseLightColor[0] = .9f;
			_diffuseLightColor[1] = .9f;
			_diffuseLightColor[2] = .9f;
			_diffuseLightColor[3] = 1.0f;
			glLightfv(_lightIdx, GL_DIFFUSE, _diffuseLightColor); // white

			_specularLightColor[0] = 0.0f;
			_specularLightColor[0] = 0.0f;
			_specularLightColor[0] = 0.0f;
			_specularLightColor[0] = 1.0f;
			glLightfv(_lightIdx, GL_SPECULAR, _specularLightColor); // white

			_position[0] = 5.0f;
			_position[1] = 5.0f;
			_position[2] = -5.0f;
			glLightfv(_lightIdx, GL_POSITION, _position);
		}

		void setAmbientColor(GLfloat rgba[4]) {
			for (int i = 0; i < 4; i++) {
				_ambientLightColor[i] = rgba[i];
			}
			glLightfv(_lightIdx, GL_AMBIENT, _ambientLightColor);
		}

		void setDiffuseColor(GLfloat rgba[4]) {
			for (int i = 0; i < 4; i++) {
				_diffuseLightColor[i] = rgba[i];
			}
			glLightfv(_lightIdx, GL_DIFFUSE, _diffuseLightColor);
		}

		void setSpecularLColor(GLfloat rgba[4]) {
			for (int i = 0; i < 4; i++) {
				_specularLightColor[i] = rgba[i];
			}
			glLightfv(_lightIdx, GL_SPECULAR, _specularLightColor);
		}

		void setPosition(GLfloat position[3]) {
			for (int i = 0; i < 3; i++) {
				_position[i] = position[i];
			}
			glLightfv(_lightIdx, GL_POSITION, _position);
		}

		void enable() {
			glEnable(_lightIdx);
		}

		void disable() {
			glDisable(_lightIdx);
		}
	};
}