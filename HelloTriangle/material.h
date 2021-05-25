#pragma once
#include <GL/freeglut.h>

namespace Kang {

	class Material {
	private:
		GLfloat mat_ambient[4];
		GLfloat mat_diffuse[4];
		GLfloat mat_specular[4];
		GLfloat mat_emissive[4];
		GLint mat_shineness;
	public:
		Material() {
			mat_ambient[0] = 0.1f;
			mat_ambient[1] = 0.1f;
			mat_ambient[2] = 0.1f;
			mat_ambient[3] = 1.0f;

			mat_diffuse[0] = 0.7f;
			mat_diffuse[1] = 0.7f;
			mat_diffuse[2] = 0.7f;
			mat_diffuse[3] = 1.0f;

			mat_specular[0] = 1.0f;
			mat_specular[1] = 1.0f;
			mat_specular[2] = 1.0f;
			mat_specular[3] = 1.0f;

			mat_emissive[0] = 0.0f;
			mat_emissive[1] = 0.0f;
			mat_emissive[2] = 0.0f;
			mat_emissive[3] = 0.0f;

			mat_shineness = 50;
		}

		void setAmbientColor(const GLfloat ambient4f[4]) {
			for (int i = 0; i < 4; i++) {
				mat_ambient[i] = ambient4f[i];
			}
		}

		void setDiffuseColor(const GLfloat diffuse4f[4]) {
			for (int i = 0; i < 4; i++) {
				mat_diffuse[i] = diffuse4f[i];
			}
		}

		void setSpecularColor(const GLfloat specular4f[4]) {
			for (int i = 0; i < 4; i++) {
				mat_specular[i] = specular4f[i];
			}
		}

		void setEmissiveColor(const GLfloat emissive4f[4]) {
			for (int i = 0; i < 4; i++) {
				mat_ambient[i] = emissive4f[i];
			}
		}

		void setShineness(const GLint shineness) {
			mat_shineness = shineness;
		}

		void applyMaterial() {
			glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
			glMaterialfv(GL_FRONT, GL_EMISSION, mat_emissive);
			glMateriali(GL_FRONT, GL_SHININESS, mat_shineness);
		}
	};
}